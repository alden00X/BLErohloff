 
// Reads incoming serial data from two seperate labled pieces of data and writes the values to the boards specified outputs

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution

Stepper myStepper(stepsPerRevolution, 4, 5);  // initialize the stepper library on pins 4 and 5:

void setup() {
  myStepper.setSpeed(150);   // set the speed at * rpm:
  Serial.begin(115200);  // Initialize the serial port
}

void loop() {
  if (Serial.available() > 0) {  // 
    int x = Serial.read();
    Serial.print(x);  // 
    

    switch (x) { 
      case 1:     // 
      myStepper.step(stepsPerRevolution/8);
      break;
      case 0:
      myStepper.step(-stepsPerRevolution/8);
      break;
      
    }
   
  }
}
