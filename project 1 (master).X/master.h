#ifndef MASTER__H
#define	MASTER__H

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
#define LED0    2
#define LED1    7



void UART_init();
void SPI_INIT(int Master_Slave, int PRESCALER);
void SPI_TREANSMIT(char data);
char UART_receive();
void UART_setBaudRate(int BaudRate);
void UART_transmit(char data);


#endif	

