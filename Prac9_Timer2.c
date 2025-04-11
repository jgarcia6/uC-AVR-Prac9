#include <avr/io.h>
#include "Timer0.h"
#include "Timer2.h"

/* incluir lo necesario para usar UART0 */

#define TIME_INTERVAL   7

void UART0_AutoBaudRate(void);

void Clock_Ini(uint8_t hr, uint8_t min, uint8_t seg)
{
    /* Implementar */
}

void Clock_Update(uint8_t seg)
{
    /* Implementar */
}

void Clock_Date_Display()
{
    /* Implementar */
    UART_puts(0,'hh:mm:ss');
}
int main(){

    /* llamar a función para inicializar puertos E/S */
    /* llamar a función para inicializar UART0   	*/

    UART0_AutoBaudRate();
    clrscr();
    gotoxy(5,1);
    UART0_puts("Autobauding done. UBRR0=");
    itoa(UBRR0,str,10);
    UART0_puts(str);
    UART0_puts('\n\r');
    
    Timer0_Ini();               /* Inicializar contador de millis.*/
    Timer2_Ini(TIME_INTERVAL);  /* Inicializar Timer2 para 7 sec.*/
    Clock_Ini(23,59,50);

    while(1){                   /* == main loop ==              */
        if( Timer2_Flag() )     /* ¿Ya expiro el Timer2?       	*/
        {
            Clock_Update(TIME_INTERVAL);
            gotoxy(5,2);
            Clock_Display();
            gotoxy(5,3);
            UART0_puts("millis=");
            /* itoa solo convertirá los 16bits menos significativos */
            itoa(millis(),str,10);
            UART0_puts(str);
        } 
    }	                    /* fin del loop principal           */ 
    return 0;               /* <-- no se llega aquí             */
}
