#include "Arduino.h"

#define Vin   //*** Define the GPIO pin 12 as Vin ***
#define Vout   //*** Define the GPIO pin 27 as Vout ***
#define Cal  //*** Define the GPIO pin 14 as the node for current calcultion ***

float R =  ; //*** Resistance in Mohms ***

float x;
float y;
float c1;
float c2;

void setup() {

  Serial.begin(); //*** Define the data rate as 115200 ***
  pinMode(Vin, ); //*** Set Vin as OUTPUT ***
  pinMode(Vout, ); //*** Set Vout as INPUT ***
  pinMode(Cal, ); //*** Set Test as INPUT ***
  
  delay(100);   //*** Set 100 ms delay ***
  //This task only needs to be done once, thus it is placed in setup().
  Serial.println("Vout (mV), I (uA)"); // display Vout (mV), I (uA) for Task 2 3 4
  for (int onPeriod = 0; onPeriod < 256; onPeriod++) 
    {
    
    analogWrite(Vin,onPeriod);// Output PWM at Vin      
    int Vout_value = analogRead(Vout); // read the voltage level at Vout 0-3.3 V and convert it to 12 bit binary number 
    int c_value = analogRead(Cal); // read the voltage level at pin D14 0-3.3 V and convert it to 12 bit binary number 
    c1 = float(Vout_value*3.3)/4095 ; // convert 12 bit binary number of Voltage level at Vout back to 0-3.3 V 
    c2 = float(c_value*3.3)/4095 ; // convert 12 bit binary number of Voltage level at D14 back to 0-3.3 V 
    x =  ; // calculate the voltage at Vout in mV
    y =  ; // calculate current in uA for Task 2 3 4 
    Serial.print(); // print the voltage at Vout in mV
    Serial.print(","); 
    Serial.println();// print the current in uA  
  }

  // Press reset button for a new sweep
}

void loop() {
  // Code for continuous operation can be added here
 
}