//www.elegoo.com modificated by ccantos
//2019.04.25

// Se define los pines donde 
// hemos conectado las patas del LED RGB
#define BLUE 3
#define GREEN 5
#define RED 6

// primero tenemos una función de configuración llamada SETUP
// se ejecuta cada vez que se pulsa el boton RESET o se reinicia la placa
void setup()
{
  // Inicializamos los PINs como salida
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  
  // Enciende el LED con un color inicial. 
  // En este caso el rojo, ya que pasamos de ROJO > VERDE > AZUL > ROJO...
  // HIGH = alto nivel de voltaje (encender)
  // LOW = bajo nivel de voltaje (apagar)
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

// definir variables de los 3 colores
int redValue;
int greenValue;
int blueValue;

// loop principal. PARTE DEL CÓDIGO QUE SE REPITE DE MANERA INDEFINIDA
void loop()
{
  // tiempo de desvanecimiento entre colores
  #define delayTime 100 

  // Elegimos el rojo como color inicial iniciando la variable a 255.
  redValue = 255; 
  greenValue = 0;
  blueValue = 0;
  
  // pasa de rojo a amarillo-verde cuando i=255
  for(int i = 0; i < 255; i += 1) 
  {
  redValue -= 1;
  greenValue += 1;
  
  analogWrite(RED, redValue);
  analogWrite(GREEN, greenValue);
  delay(delayTime);
  }

  
  // pasa de verde a azul cuando llega a i=255
  for(int i = 0; i < 255; i += 1)
  {
  greenValue -= 1;
  blueValue += 1;
  
  analogWrite(GREEN, greenValue);
  analogWrite(BLUE, blueValue);
  delay(delayTime);
  }


  // pasa de azul a rojo cuando llega a i=255
  for(int i = 0; i < 255; i += 1)
  {
  blueValue -= 1;
  redValue += 1;
  
  analogWrite(BLUE, blueValue);
  analogWrite(RED, redValue);
  delay(delayTime);
  }
  
}
