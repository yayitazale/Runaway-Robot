
//##############################################################################
//##############################################################################
//                                                                             #
// Runaway_Robot                                                               #
// by Joseba Egia Larrinaga                                                    #
// V 2.0 - 31.10.2014                                                          #            
// hirikilabs.tabakalera.eu                                                    #
//                                                                             #
// A través de la señal de los sensores de ultrasonidos se mide                #
// la distancia respecto a los obstaculos de la derecha y de                   #
// la izuiqerda, de manera que el robot nunca choque con ellos.                #
//                                                                             #
//                                                                             #
// Con una batería de 9V a plena carga, el robot debe durar unos               #
// 45 minutos sin descanso.                                                    #
//                                                                             #
//##############################################################################
//##############################################################################

//Incluimos las librerías del servo ya integradas y el del ultrasonido https://github.com/JRodrigoTech/Ultrasonic-HC-SR04
#include <Ultrasonic.h>
#include <Servo.h>


// Definimos los movimientos de cada motor servo mediante una posición.  
#define derechoParada 1450
#define izquierdoParada  1390
#define derechoAdelante 2000
#define izquierdoAdelante 1000
#define derechoAtras 1000
#define izquierdoAtras 2000

// Definimos dos motores
Servo derecho;
Servo izquierdo;

// Definimos dos sensores de ultrasonido, con sus respectivos cables Trig y Echo.
Ultrasonic ultrasonicD(3,A3);
Ultrasonic ultrasonicI(4,A4);



// Configuramos los motores en sus respectivas salidas digitales.
void setup() 
{
derecho.attach(12);
izquierdo.attach(6);
}


// El loop general del programa. Realizamos comparaciones sobre la distancia de cada ultrasonido y actuamos girando en el sentido opuesto. 
void loop() {
   
  if (ultrasonicD.Ranging(CM) > 8 ){
    if (ultrasonicI.Ranging(CM) > 8 ){
      derecho.writeMicroseconds(derechoAdelante);
      izquierdo.writeMicroseconds(izquierdoAdelante);
      delay(100);
    }
    else {
      derecho.writeMicroseconds(derechoAtras);
      izquierdo.writeMicroseconds(izquierdoAdelante);
      delay(100);
    }
  }
  else
  {
    if (ultrasonicI.Ranging(CM) > 8 ){
      derecho.writeMicroseconds(derechoAdelante);
      izquierdo.writeMicroseconds(izquierdoAtras);
      delay(100);
    }
    else {
      derecho.writeMicroseconds(derechoAtras);
      izquierdo.writeMicroseconds(izquierdoAtras);
      delay(100);
    }
  }
}


