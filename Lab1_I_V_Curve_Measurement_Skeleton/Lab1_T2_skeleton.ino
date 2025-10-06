#include "Arduino.h"

#define Vin 12   // Define the GPIO pin 12 as Vin
#define Vout 27  // Define the GPIO pin 27 as Vout
#define Cal 14   // Define the GPIO pin 14 as the node for current calculation

float R = 1000.0; // Resistance in ohms (example: 1k ohm)

float x; // Voltage at Vout
float y; // Current in uA
float c1; // Voltage at Vout in V
float c2; // Voltage drop across R2 in V

void setup() {
  Serial.begin(115200); // Define the data rate as 115200
  pinMode(Vin, OUTPUT); // Set Vin as OUTPUT
  pinMode(Vout, INPUT); // Set Vout as INPUT
  pinMode(Cal, INPUT); // Set Cal as INPUT
  
  delay(100); // Set 100 ms delay
  Serial.println("Vout (mV), I (uA)"); // Display header for output

  for (int onPeriod = 0; onPeriod < 256; onPeriod++) {
    analogWrite(Vin, onPeriod); // Output PWM at Vin      
    
    int Vout_value = analogRead(Vout); // Read the voltage level at Vout
    int c_value = analogRead(Cal); // Read the voltage level at Cal
    c1 = float(Vout_value * 3.3) / 4095; // Convert to V
    c2 = float(c_value * 3.3) / 4095; // Convert to V 
    
    x = c1 * 1000; // Calculate the voltage at Vout in mV
    y = (c2 / R) * 1000000; // Calculate current in uA using I = V / R

    Serial.print(x); // Print the voltage at Vout in mV
    Serial.print(","); 
    Serial.println(y); // Print the current in uA  
  }
}

void loop() {
  // Code for continuous operation can be added here
}