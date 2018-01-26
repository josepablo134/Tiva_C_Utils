#ifndef UART_TOOLS_H
#define UART_TOOLS_H
    #include <stdint.h>
    #include <ti/drivers/UART.h>
    #define UART_endl(UART_HANDLE) UART_putch(UART_HANDLE,'\n')
    //
    //Envia una cadena de caracteres por el puerto serial
    //
    extern void UART_puts(UART_Handle,const char*);
    //
    //Envia un caracter por el puerto serial
    //
    extern void UART_putch(UART_Handle,char);
    //
    //Envia el numero en formato ASCII Hex por el puerto serial
    //
    extern void UART_putHex(UART_Handle,uint32_t);
    //
    //Envia el numero en formato ASCII por el puerto serial
    //
    extern void UART_putInt(UART_Handle,uint32_t);
    //
    //Envia el numero en formato ASCII por el puerto serial
    //
    extern void UART_putFloat(UART_Handle,float);
    //
    //Convierte el numero entregado en formato ASCII Hexadecimal
    //
    extern char UART_intToHexChar(uint8_t);
#endif
