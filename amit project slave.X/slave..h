

#ifndef SLAVE_H
#define	SLAVE_H

#define LED0    2
#define LED1    7
#define master 1 
#define slave 0
#define SPI_PS_2  4
#define SPI_PS_4   0
#define SPI_PS_8   5 
#define SPI_PS_16   1
#define SPI_PS_32   6
#define SPI_PS_64  2
#define SPI_PS_128  3
#define SPI_NONE 8 

#define MOSI 5
#define MISO 6
#define SS   4
#define SCK 7

void UART_init();
void SPI_INIT(int Master_Slave, int PRESCALER);
void UART_setBaudRate(int BaudRate);
char SPI_RECIVIER();
void UART_transmit(char data);
void LED0_ON();
void LED1_ON();
void LED0_OFF();
void LED1_OFF();
#endif	

