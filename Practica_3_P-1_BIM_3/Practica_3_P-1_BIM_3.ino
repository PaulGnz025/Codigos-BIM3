#include <LedControl.h>

#define canal0_pot A0
#define din_matrix 4
#define cs_matrix 3
#define clk_matrix 2

unsigned int valor_adc_pot;
unsigned int del_del_motor;
LedControl Pacman_Matrix = LedControl(din_matrix, clk_matrix, cs_matrix, 1);
 
byte Pacman_boca_abierta[8] = {
   B00111100,
   B01000010,
   B10010010,
   B10000100,
   B10001000,
   B10000100,
   B01000010,
   B00111100,

 };

byte Pacman_boca_cerrada[8] = 
{
 B00111000,
 B01000100,
 B10010010,
 B10000010,
 B10001110,
 B10000010,
 B01000100,
 B00111000,



};
void setup() {
Serial.begin(9600);
Pacman_Matrix.shutdown(0, false);
Pacman_Matrix.setIntensity(0, 15);
Pacman_Matrix.clearDisplay(0);
Serial.println("Uso de la matriz led");
 
}
 
void loop() {
  valor_adc_pot= analogRead(canal0_pot);
  del_del_motor= map(valor_adc_pot,0,1023,100,5000);
for(int i=0; i<8; i++ ){
  Pacman_Matrix.setRow(0,i, Pacman_boca_abierta[i]);
}
delay(del_del_motor);
for(int i=0;i<8;i++){
  Pacman_Matrix.setRow(0,i, Pacman_boca_cerrada[i]);
}
delay(del_del_motor);

}
 
