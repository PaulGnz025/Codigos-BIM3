#include <Wire.h> //libreria que me permite usar el protocolo i2c
#include <SparkFun_ADXL345.h>       //libreria que me permite usar el acelerometro ADXL345
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
ADXL345 acelerometro_ADXL345 = ADXL345();    //constructor para poder utilizar el acelerometro.

//Variables donde guardo las aceleraciones.
int x;
int y;
int z;

void setup() {
  Serial.begin(9600);     //Inicio la comunicacion serial a 9600 baudios.
  Serial.println("Alarma sismica");
  acelerometro_ADXL345.powerOn();             //Enciendo el acelerometro.
  acelerometro_ADXL345.setRangeSetting(8);    //Configuro para medir la aceleracion con 8g.
  pinMode( 2,OUTPUT);
  pinMode( 3,OUTPUT);
  pinMode( 4,OUTPUT);
  pinMode( 5,OUTPUT);
  pinMode( 6,OUTPUT);
  pinMode( 7,OUTPUT);
  pinMode( 8,OUTPUT);
  mySerial.begin(9600); 

  if (!myDFPlayer.begin(mySerial)) {  // Use softwareSerial to communicate with mp3.
    Serial.println("Unable to begin:");
    Serial.println("1.Please recheck the connection!");
    Serial.println("2.Please insert the SD card!");
    while(true);
  }
  Serial.println("CORRAAAAAAAAAAAAAAAAAAN!!!!!!!!!!");
}


void loop() {
 /*
  * Obtengo las aceleraciones por cada eje
 */
 acelerometro_ADXL345.readAccel(&x,&y,&z);
 float magnitude = sqrt(x * x + y * y + z * z) / 64.0;
 
 Serial.print("La magnitud del terremoto es ");
 Serial.println(magnitude);
 
 apagarTodosLosLEDs();

 if (magnitude < 2.0) {
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
   
  } else if (magnitude < 4.0) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  } else if (magnitude < 6.0) {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    Serial.println("CORRAAAAAAAAAAAAAAAAAAN!!!!!!!!!!");
    myDFPlayer.volume(15);  // Set volume value. From 0 to 30
    myDFPlayer.play(0002);  // Play the first mp3
    delay(6000);
  }
  delay(100);
}

void apagarTodosLosLEDs() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  myDFPlayer.pause();
}
