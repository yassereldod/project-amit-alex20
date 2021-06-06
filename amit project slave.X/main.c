#include "slave..h"
#include <avr/io.h>

int main() {
    char data;
   
    UART_init(9600);
    SPI_INIT(slave,SPI_PS_128);
    while (1) {
       data= SPI_RECIVIER();
        if (data == 'a') {
            LED1_ON();
            
        } 
        else if (data == 'b') {
            LED1_OFF();
           
        }
       
        else if (data == 'c') {
            LED0_ON();
            
        }
       
        else if  (data == 'd') {
            LED0_OFF();
            
        }
        

    }
    return 0;
}

