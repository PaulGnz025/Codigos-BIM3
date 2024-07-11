#include <Adafruit_NeoPixel.h>


//Directivas de preprocesador
#define Cantidad_Leds 7
#define pin_Led 2
#define Trigger 3
#define Echo 4
int A=5;
int B=6;
int C=16;
int D=15;
int E=14;
int F=7;
int G=8;
int cont=0;
int distancia_max = 9.99;
int distancia_min = 5.99;
bool personadetectada=false;
enum colores
{
   rojo, 
   azul,
   blanco,
   verde,
   naranja
};
Adafruit_NeoPixel anillo(Cantidad_Leds,pin_Led,NEO_GRB + NEO_KHZ800);
float signSensor(void);
void setColor(int color);
void setup(){
  anillo.begin();
 Serial.begin(9600);
 
 pinMode(A,OUTPUT);
 pinMode(B,OUTPUT);
 pinMode(C,OUTPUT);
 pinMode(D,OUTPUT);
 pinMode(E,OUTPUT);
 pinMode(F,OUTPUT);
 pinMode(G,OUTPUT);
 pinMode(Trigger,OUTPUT);
 pinMode(Echo,INPUT);
  
}
void loop(){
 Serial.print("Distancia ");
 Serial.print(signSensor());
  Serial.println("cm");
  delay(750);
  if(signSensor() >= distancia_min && signSensor() <= distancia_max)
  {
    if(! personadetectada){
   cont++;
   personadetectada = true;
    }
    else{
      personadetectada = false;
    }
  }
  Serial.print("Personas detectada ");
  Serial.println(cont);
  
  if(cont == 0)
  {
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(F,HIGH);
  setColor(verde);
  delay(500);
  }
  
  else if(cont == 1)
  {
  digitalWrite(A,LOW);
  digitalWrite(F,LOW);
  digitalWrite(E,LOW);
  digitalWrite(D,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(B,HIGH);
  setColor(verde);
  delay(500);
  }
  else if(cont == 2 )
  {
  digitalWrite(C,LOW);
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(G,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(D,HIGH);
  setColor(verde);
  delay(500);
  }
  else if(cont == 3)
  {
  digitalWrite(E,LOW);
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(G,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
  setColor(verde);
  delay(500);
  }
  else if(cont == 4 )
  {
   digitalWrite(D,LOW);
   digitalWrite(A,LOW); 
   digitalWrite(F,HIGH);
   digitalWrite(G,HIGH);
   digitalWrite(B,HIGH);
   digitalWrite(C,HIGH);
   setColor(verde);
   delay(500);
  }
  else if(cont == 5)
  {
   digitalWrite(B,LOW);
   digitalWrite(A,HIGH);
   digitalWrite(F,HIGH);
   digitalWrite(G,HIGH);
   digitalWrite(C,HIGH);
   digitalWrite(D,HIGH);
   setColor(verde);
   delay(500);
  }
  else if(cont ==6)
  {
  digitalWrite(A,HIGH);
  digitalWrite(F,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(G,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(C,HIGH);
  setColor(verde);
  delay(500);
}
  else if(cont == 7)
  {
   digitalWrite(A,HIGH);
   digitalWrite(B,HIGH);
   digitalWrite(C,HIGH);
   digitalWrite(F,LOW);
   digitalWrite(E,LOW);
   digitalWrite(D,LOW);
    digitalWrite(G,LOW);
   setColor(verde);
   delay(500);
  }
  else if(cont == 8)
  {
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(E,HIGH);
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);
  setColor(naranja);
  delay(500);
  }
  else if(cont == 9)
  {
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(F,HIGH);
  digitalWrite(G,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(E,LOW);
  digitalWrite(D,LOW);
  setColor(rojo);
  delay(500);
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,HIGH);
  digitalWrite(C,LOW);
  
  
  }  
}
float signSensor(void){
  digitalWrite(Trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger,LOW);
  
  
 long Sensor=pulseIn(Echo,HIGH);
 long distancia =Sensor/59;
  return distancia;
}

void setColor(int color)
{
  switch(color)
  {
    case(rojo):
    {
        for(int i =0; i<25; i++)
        {
          anillo.setPixelColor(i,anillo.Color(255,0,0));
          anillo.show();  //muestro el color en el led
        } 
      break;
    }
    
    case(naranja):
    {
        for(int i =0; i<25; i++)
        {
          anillo.setPixelColor(i,anillo.Color(255,140,0));
          anillo.show();  //muestro el color en el led
        }
      break;
    }
    
    case(verde):
    {
        for(int i =0; i<25; i++)
        {
          anillo.setPixelColor(i,anillo.Color(124,252,0));
          anillo.show();  //muestro el color en el led
        }
      break;
    }
  
  }
}
