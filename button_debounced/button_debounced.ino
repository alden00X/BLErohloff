 //

int buttonState_up = 0; // initial state of the button press
int buttonState_down = 0; // initial state of the button press

int current_buttonState_up; 
int current_buttonState_down;

int lastButtonState_up = 0;
int lastButtonState_down = 0;

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 100;    // the debounce time; increase if the output flickers


void setup() {
  pinMode(4, INPUT);  // Sets the digital pin as an input(button press)
  pinMode(5, INPUT); // Sets the digital pin as an input(button press)
  
  Serial.begin(115200);  // initialize the serial port
}

void loop() {

  int buttonState_up = digitalRead(5); //  LOW
  int buttonState_down = digitalRead(4);  //  LOW

  
  switch (buttonState_up) {
    case 1:
      
      if (buttonState_up != lastButtonState_up) { // If the switch changed, due to noise or pressing:
        lastDebounceTime = millis(); // reset the debouncing timer
  }
      if ((millis() - lastDebounceTime) > debounceDelay) { // whatever the reading is at, it's been there for longer than the debounce
                                                           // delay, so take it as the actual current state:
        if (buttonState_up != current_buttonState_up) { // if the button state has changed:
          current_buttonState_up = buttonState_up;
          if (current_buttonState_up == 1) { // only write to serial if the new button state is HIGH      
      }
    }
  }
    Serial.write(1);
    Serial.print(1);
    break;    
  }
  switch (buttonState_down) {
    case 1:
     
      if (buttonState_down != lastButtonState_down) {  // If the switch changed, due to noise or pressing:
        lastDebounceTime = millis(); // reset the debouncing timer
  }
      if ((millis() - lastDebounceTime) > debounceDelay) { // whatever the reading is at, it's been there for longer than the debounce
                                                           // delay, so take it as the actual current state:
        if (buttonState_down != current_buttonState_down) { // if the button state has changed:
          current_buttonState_down = buttonState_down;
          if (current_buttonState_down == 1) { // only write to serial if the new button state is HIGH   
      }
    }
  }
    Serial.write(0);
    Serial.print(0);
    break;   
  }   
 delay(100); 
 lastButtonState_up = buttonState_up;
 lastButtonState_down = buttonState_down; 
}
