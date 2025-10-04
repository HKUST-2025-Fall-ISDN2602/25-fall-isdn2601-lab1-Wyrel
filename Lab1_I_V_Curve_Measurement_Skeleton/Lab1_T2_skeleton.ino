#include "Arduino.h"

#define Vin 12 //*** Define the GPIO pin 12 as Vin ***
#define Vout 27 //*** Define the GPIO pin 27 as Vout ***
#define Cal 14 //*** Define the GPIO pin 14 as the node for current calcultion ***

float R = 22000 ; //*** Resistance in Mohms ***

const float Vref = 3.3
const int ADC_MAX = 4095

float vout_V;
float vcal_V;
float v_r2_V;
float I_A;

void setup() {

  Serial.begin(115200); //*** Define the data rate as 115200 ***
  analogReadResolution(12); 

  pinMode(Vin, OUTPUT); //*** Set Vin as OUTPUT ***
  pinMode(Vout, INPUT); //*** Set Vout as INPUT ***
  pinMode(Cal, INPUT); //*** Set Test as INPUT ***
  
  delay(100);   //*** Set 100 ms delay ***
  //This task only needs to be done once, thus it is placed in setup().
  Serial.println("Vout (mV), I (uA)"); // display Vout (mV), I (uA) for Task 2 3 4
  for (int onPeriod = 0; onPeriod < 256; onPeriod++) 
    {
    
    analogWrite(Vin,onPeriod);// Output PWM at Vin      
    delay(10)
    
    const int N = 8;
    long sumvout = 0, sumCal = 0;
    for (int i = 0; i < N; i++) {
      sumVout += analogRead(Vout)
      sumCal += analogRead(Cal);
      delayMicroseconds(200);
    }
    
    int Vout_value = sumVout / N; // read the voltage level at Vout 0-3.3 V and convert it to 12 bit binary number 
    int c_value = sumCal / N; // read the voltage level at pin D14 0-3.3 V and convert it to 12 bit binary number 
    c1 = float(Vout_value * Vref ) / ADC_MAX ; // convert 12 bit binary number of Voltage level at Vout back to 0-3.3 V 
    c2 = float(c_value * Vref) / ADC_MAX ; // convert 12 bit binary number of Voltage level at D14 back to 0-3.3 V 
    x = float(Vout_V * 1000) ; // calculate the voltage at Vout in mV
    y = (I_uA * 1e6) ; // calculate current in uA for Task 2 3 4 
    Serial.print(vout_mV, 2); // print the voltage at Vout in mV
    Serial.print(","); 
    Serial.println(I_uA, 2);// print the current in uA  
  }

  // Press reset button for a new sweep
}

void loop() {
  // Code for continuous operation can be added here
 
}