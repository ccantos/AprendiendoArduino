# LED RGB

Con este ejercicio se jugará con un LED RGB que siempre es una manera divertida de ver el trabajo realizado.

Primero se dará una pequeña introducción teórica de los elementos nuevo que se utilizarán.

### Hardware necesario

* Placa Arduino Uno R3
* Protoboard (MB-102)
* Cables de puente Macho-macho para Arduino
* 1xLED RGB
* 3xResistencias de 220 Ohmios

### Introducción teórica

- ##### Protoboard/Breadboard/Placa de pruebas

  [Protoboard](https://github.com/ccantos/AprendiendoArduino/blob/master/Curso%20con%20Super%20Starter%20Kit%20UNO%20R3%20Project/2.%20LED%20RGB/protoboard.png)

  Un Protoboard permite circuitos prototipo rápidamente, sin necesidad de soldar las conexiones. Está hecho de dos materiales, un aislante y un conductor que conecta los diversos orificios entre sí. Suelen tener esta distribución: 

  [Esquema protoboard](https://github.com/ccantos/AprendiendoArduino/blob/master/Curso%20con%20Super%20Starter%20Kit%20UNO%20R3%20Project/2.%20LED%20RGB/Esquema_interno_de_una_Breadboard.png)

* **Resistencias**

  Como su nombre indica las resistencias resisten el flujo de electricidad. A mayor valor de la resistencia, mas resiste y menos corriente circulará por el elemento. Se va a utilizar para el control del flujo que circulará por el LED (nos permite aumentar o disminuir el brillo del LED). La unidad de resistencia es el Ohmio y sigue la **Ley de Ohm**:
  $$
  R = \frac{V}{I} (\Omega)
  $$
  Para saber cual es el valor en Ohmios de una resistencia solo hay que seguir la gama de colores que tienen estas resistencias dibujadas de la siguiente forma:

  [Esquema Resistencia](https://github.com/ccantos/AprendiendoArduino/blob/master/Curso%20con%20Super%20Starter%20Kit%20UNO%20R3%20Project/2.%20LED%20RGB/resistencia.png)

  Entonces en este ejercicio vamos a utilizar una resistencia de 220 Ohmios, luego buscaremos una resistencia con los colores: *ROJO > ROJO > NEGRO > NEGRO > (último color ahora mismo no tiene importancia, solo indica valor máximo y mínimo que puede alcanzar la resistencia)*. Este componente es recíproco, es decir, da igual en que sentido se ponga pues se comporta de la mismo forma.

* **LED**

  [LED](https://github.com/ccantos/AprendiendoArduino/blob/master/Curso%20con%20Super%20Starter%20Kit%20UNO%20R3%20Project/2.%20LED%20RGB/led.png)

  Es un tipo de diodo que emite luz, por sus siglas en inglés *light-emitting diode*. Utilizan poca electricidad y son durareros. Hay mucha ciencia detrás de estos elementos, recomiendo para una explicación más completa este vídeo [video LED](https://www.youtube.com/watch?v=Y324Y55lm2E)

  No es un elemento recíproco entonces hay que tener en cuenta el lado positivo y negativo. La patilla corta del elemento será el lado negativo (observar la imagen abajo). El LED solo se encenderá si la corriente va del ánodo al cátodo (de la patilla larga a la corta). 

  [Anodo Catodo](https://github.com/ccantos/AprendiendoArduino/blob/master/Curso%20con%20Super%20Starter%20Kit%20UNO%20R3%20Project/2.%20LED%20RGB/anodo_catodo.png)

  Los LED necesitan **resistencias de protección**, muy importante tenerlo en cuenta para nuestro circuito y así no quemar nuestro LED.

* **LED RGB**

  Este elemento se compone de tres diodos LED. Mezcla los tres colores principales de forma que se podrá obtener el color que se requiera jugando con la corriente que le llega por cada pata.

  [LED RGB](https://github.com/ccantos/AprendiendoArduino/blob/master/Curso%20con%20Super%20Starter%20Kit%20UNO%20R3%20Project/2.%20LED%20RGB/LEDRGB.jpg)

  La pata más larga es el cátodo. Para las demás patas, por donde llegará la corriente, necesitaremos una resistencia de protección para cada LED.
  
  Ahora tenemos los tres principales colores y con ellos se simulará todo el espectro de colores. Esta idea que se va a simular es lo que realiza cada píxel en las pantallas LCD. Con todos los colores tendremos el blanco:
  
  [RGB](https://github.com/ccantos/AprendiendoArduino/blob/master/Curso%20con%20Super%20Starter%20Kit%20UNO%20R3%20Project/2.%20LED%20RGB/RGB.png)

* **Teoría PWM**

  Hay que decir nuestra placa de Arduino no es capaz de proporcionar una auténtica salida analógica, lo único que pueden proporcionar es una salida -V o V (p. e. 0V y 5V). Entonces para poder simular una salida analógica se usa un *truco* que consiste en **activar la salida digital durante un tiempo y mantenerla apagada durante el resto**. El promedio de la salida, en el tiempo, sería la señal analógica deseada.

  Para conseguir esta simulación se hace uso de la **modulación por ancho de pulsos (PWM)** es una técnica para el control de potencia que se envía a una carga.

  [PWM](https://github.com/ccantos/AprendiendoArduino/blob/master/Curso%20con%20Super%20Starter%20Kit%20UNO%20R3%20Project/2.%20LED%20RGB/pwm.png)

  Como se puede observar en la imagen tenemos pulsos de 5 voltios con una frecuencia fija y que solamente cambia la anchura (tiempo que se esta emitiendo ese voltaje).

  La duración de estos pulsos es controlada por la funcion *analogWrite* es nuestro código. *analogWrite(0)* no producirá ningun pulso, en cambio *analogWrite(255)* producirá un pulso que dura todo el tiempo. De esta forma conseguiremos el desvanecimiento de los colores en este proyecto.

### Esquema del circuito

[PWM](https://github.com/ccantos/AprendiendoArduino/blob/master/Curso%20con%20Super%20Starter%20Kit%20UNO%20R3%20Project/2.%20LED%20RGB/diagrama_de_cableado.png)



**Mirar el código .ino** en las carpeta LED_RGB.

