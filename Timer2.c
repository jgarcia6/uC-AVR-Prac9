#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>

static uint8_t Flag;

void Timer2_Ini( uint8_t baseT )
{
    
/* Configurar Timer2 para usar cristal externo según */
/* secuencia dada por la hoja de especificaciones    */
	
}

uint8_t Timer2_Flag ( void )
{
    if( Flag )
    {
        Flag=0;
        return 1;
    }
    else
    { 
      return 0;
    }
}
       
/* Rutina de Servicio de Interrupción  para atender la interrupción */
/* por Comparación del Timer2  (TCNT2 y OCR2 son iguales)		 */
ISR(SIG_OUTPUT_COMPARE2A)
{
    Flag = 1;	/* Activa Bandera para indicar los 1 segundos */

} 	/* fin de la rutina de servicio de Interrupción (RSI) */