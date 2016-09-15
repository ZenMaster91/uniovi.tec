#include "C:\Documents and Settings\Propietario\Escritorio\Arturito\main.h"

// **************************************************************************************
//-- Definiciones para los motores. Estos valores definen los movimientos del robot

#define   AVANZA     0x1C  //-- Binario: 0001 1100
#define   ATRAS      0x16  //-- Binario: 0001 0110
#define   IZQUIERDA  0x1E  //-- Binario: 0001 1110
#define   DERECHA    0x14  //-- Binario: 0001 0100
#define   STOP       0x00  //-- Binario: 0000 0000

#byte PORTB = 0x06         // localizaci?n en la memoria de datos del puerto B
#byte TRISB = 0x86         // localizaci?n en la memoria de datos de   TRISB


//-- Controlaremos el Skybot usando la constante SKYBOT

#define SKYBOT PORTB

//-- Valor para configurar el puerto B para trabajar con el Skybot:
//-- Bits RB6 y RB7  entradas de los sensores detecci?n B/W 

//-- Bits RB1, RB2, RB3 y RB4  salidas de control de los motores
// RB2 (motor 1 ON/OFF)  y RB4 (motor 2 ON/OFF)
// RB1 (motor 1 direcci?n)  (RB1=0 adelante, RB1=1 atras)
// RB3 (motor 2 direcci?n)  (RB3=1 adelante, RB1=0 atras)


#define CONF_SKYBOT 0xE1      //-- Binario: 1110 0001    Configuracion E o S de los bits del puerto B

//-- Colocacion de los sensores

#bit   SENSOR3 = 0x06.6       // RB6       sensor derecho
#bit   SENSOR4 = 0x06.7       // RB7       sensor izquierdo
#bit   BUMPERD = 0x05.1		  // Bumbr derecho;
#bit   BUMPERI = 0x05.2		  // Bumper izquierdo;

//-- Modificar esto para indicar la colocacion de los sensores
#define IZQUIERDO  SENSOR4
#define DERECHO    SENSOR3
#define BDERECHO   BUMPERD
#define BIZQUIERDO BUMPERI

//-- Colores leidos por los sensores
#define NEGRO  1
#define BLANCO 0


// ***************************************************************************************

void configurar_skybot() {
  TRISB=CONF_SKYBOT;
}

void main() {

   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_spi(FALSE);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   configurar_skybot();

	//-- El comportamiento del robot deberá de ser le siguiente:
	//-- Alinearse con la linea de forma que el borde derecho de la pista quede alineado
	//-- en el centro de los dos sensores de forma que la forma de seguir la linea sea enteramente 
	//-- por el margen y reduciendo así el ancho necesario para seguir una linea a la mitad.
	while (1) {
		
		//-- Si se presiona el bumper derecho o el bumper izquierdo el robot se detiene.
		if(BDERECHO == 1 || BIZQUIERDO == 1) {
			SKYBOT = STOP;
		}
		
		//-- Estado normal en el que el robot debería de avanzar por el lateral derecho de la ljnea negra.
		else if ((IZQUIERDO==NEGRO) && (DERECHO==BLANCO)) {
			SKYBOT = AVANZA;
		}
		
		//-- Si el robot se sale por la derecha de la linea el sensor izquierdo detectará balnco,
		//-- entonces tenemos que girar a la izquierda para volver a la linea.
		else if((IZQUIERDO == BLANCO) && (DERECHO == BLANCO)) {
			SKYBOT = IZQUIERDA;
		}
		
		//-- Si el robot se desalinea por la izquierda el sensor derehco detectará negro,
		//-- entonces deverá de virar a la derecha para entrar otra vez en alineación.
		else if((IZQUIERDO == NEGRO) && (DERECHO == NEGRO)) {
			SKYBOT = DERECHA;
		}
	}
}
