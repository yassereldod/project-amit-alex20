
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h> 
#include "master.h"
    

void UART_init(int BaudRate){
    UCSRB |= (1<<TXEN)|(1<<RXEN);
    UART_setBaudRate(BaudRate);
}
void SPI_INIT(int Master_Slave, int PRESCALER) {
    if (Master_Slave) {
        SPCR |= (1 << MSTR);
        SPCR |= (PRESCALER > 3) ? (PRESCALER & 0xFD) : PRESCALER;
        SPCR |= (PRESCALER > 3) ? (1 << SPI2X) : 0;
        DDRB |= (1 << MOSI) | (1 << SCK) | (1 << SS);
    } else {
        SPCR &= ~(1 << MSTR);       
        DDRB |= (1 << MISO);
    }
    SPCR |= (1 << SPE);
}
void UART_setBaudRate(int BaudRate){
  
    int UBRR = ((F_CPU/16.0)/BaudRate)-1;
    UBRRL = (char) UBRR;
    UBRRH = (UBRR>>8);
}
void UART_transmit(char data){
    while(!(UCSRA & (1<< UDRE)));
    UDR = data;
}
void SPI_TREANSMIT(char data) {
    SPDR = data;
    while (!(SPSR & (1 << SPIF)));
}
    
    
char UART_receive(){
    while(!(UCSRA & (1<< RXC)));
    return UDR;
}
void LEDs_init() {
    
    DDRC |= (1 << LED1) | (1 << LED0); 
    
}

void LED0_ON() {
    PORTC |= (1 << LED0);
}

void LED1_ON() {
    PORTC |= (1 << LED1);
}

void LED0_OFF() {
    PORTC &= ~(1 << LED0);
}

void LED1_OFF() {
    PORTC &= ~(1 << LED1);
}

