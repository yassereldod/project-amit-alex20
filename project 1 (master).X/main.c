

#include "master.h"


int main() {
    char data;
   
    UART_init(9600);
    SPI_INIT(master,SPI_PS_128);
    while (1){
        data=UART_receive();
        SPI_TREANSMIT(data);
        

    }
    return 0;
}