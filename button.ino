 //


int buttonState_up = 0; // initial state of the button press
int buttonState_down = 0; // initial state of the button press


void setup() {
  pinMode(4, INPUT);  // Sets the digital pin as an input(button press)
  pinMode(5, INPUT); // Sets the digital pin as an input(button press)
  Serial.begin(115200);  // initialize the serial port
}

void loop() {

  buttonState_up = digitalRead(4); // HIGH or LOW
  buttonState_down = digitalRead(5);  // HIGH or LOW

  
  switch (buttonState_up) {
    case 1:
    Serial.write(1);
    break;
  }

  switch (buttonState_down) {
    case 1:
    Serial.write(0);
    break;
  }

 delay(200);
}
