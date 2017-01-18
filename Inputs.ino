void buttons (){

// read the state of the switch into a local variable:

  int b1 = digitalRead(button1);
  int b2 = digitalRead(button2);  
  int b3 = digitalRead(button3);

if (b1 == LOW && b2 == HIGH && b3 == HIGH){
    reading = 1; 
    delay(200);
    }
else if (b1 == HIGH && b2 == LOW && b3 == HIGH){
    reading = 2; 
    delay(200);
    }
else if (b1 == HIGH && b2 == HIGH && b3 == LOW){
    reading = 3; 
    delay(200);
    }
else if (b1 == LOW && b2 == LOW && b3 == LOW){
    delay(200);
  
    reading = 4; }


  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
    }
  }

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
}

void pots(){
  
  sensorValue = analogRead (pot1);
  bright = (50-(sensorValue/21))+2;

  
  }
