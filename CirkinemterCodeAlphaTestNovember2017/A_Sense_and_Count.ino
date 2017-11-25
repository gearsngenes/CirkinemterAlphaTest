void countRevs() {
  while (count < maxcount)
  {
    if (!digitalRead(Button_C)) {
      buttoncount++;
      Serial.print("Button Pressed. COunt:");Serial.println(buttoncount);
      delay(500);
    }
    if ((buttoncount % 2) == 1)
    {
      digitalWrite(buttonCLED,HIGH);
      xval = oldXval;
      yval = oldYval;
    }
    else
    {
      digitalWrite(buttonCLED,LOW);
      //Serial.println("no Button Pressed");
      oldXval = xval;
      xval = analogRead(x);
      oldYval  = yval;
      yval = analogRead(y);

    }
    getSetSpeed();
    getSetDirection();

    sensorState = digitalRead(SENSORPIN);
    if (sensorState == LOW) {
      // turn LED on:
      digitalWrite(LEDPIN, HIGH);
    }
    else {
      // turn LED off:
      digitalWrite(LEDPIN, LOW);
    }

    if (sensorState && !lastState) {
      //  Serial.println("Unbroken");
    }
    if (!sensorState && lastState) {
      //  Serial.println("Broken");
      count++;
    }
    lastState = sensorState;

  }



}

