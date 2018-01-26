#include "UART_tools.h"

//
//Envia una cadena de caracteres por el puerto serial
//
void UART_puts(UART_Handle uart_handle,const char* msj){
    while(*msj){
        UART_write(uart_handle,msj,1);
        *msj++;
    }
}
//
//Envia un caracter por el puerto serial
//
void UART_putch(UART_Handle uart_handle,char c_msj){
    UART_write(uart_handle,&c_msj,1);
}
//
//Envia el numero en formato ASCII Hex por el puerto serial
//
extern void UART_putHex(UART_Handle uart_handle,uint32_t number){
    uint32_t n_number=0;
    //Invertir los nibble de MSB - LSB , LSB - MSB
    //Es decir, ordenar la memoria en porciones de 4 bits Big-Endian
    UART_puts(uart_handle,"0x");
    LOOP_EXTRACT:
        n_number<<=4;
        n_number |= number&0xF;
        number>>=4;
        if(number)
            goto LOOP_EXTRACT;
    LOOP_SEND:
        //Enviar los 4bits LSB
        UART_putch( uart_handle, UART_intToHexChar(n_number&0xF));
        n_number >>= 4;
        if(n_number)
            goto LOOP_SEND;
}
//
//Envia el numero en formato ASCII por el puerto serial
//
void UART_putInt(UART_Handle uart_handle,uint32_t number){
    uint32_t n_number=0;
LOOP_EXTRACT:
    n_number*=10;
    n_number += number%10;
    number/=10;
    if(number)
        goto LOOP_EXTRACT;
LOOP_SEND:
    UART_putch( uart_handle, UART_intToHexChar(n_number%10) );
    n_number /= 10;
    if(n_number)
        goto LOOP_SEND;
}


//
//Envia el numero en formato ASCII por el puerto serial
//
void UART_putFloat(UART_Handle uart_handle,float number){
    if(number<0){
        UART_putch(uart_handle, '-');
        number *=-1;
    }
    number*=1000;

    //Obtenemos la parte entera del numero
    uint32_t d_buffer = (int)number;

//Enviamos la parte entera
UART_putInt(uart_handle,d_buffer/1000);
UART_putch(uart_handle,'.');
//Enviamos la parte decimal
UART_putInt(uart_handle,d_buffer%1000);
}

//
//Convierte el numero entregado en formato ASCII Hexadecimal
//
char UART_intToHexChar(uint8_t digit){
    if(digit<10){
        return digit+'0';
    }
    if(digit>9 && digit<16){
        return digit+'7';
    }
    return '.';
}
