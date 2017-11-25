//-----------Listing all the directions.
void counterclockwise(){  //BO1 on while BO2 off gives CounterClock
  digitalWrite(BO1, HIGH);
  digitalWrite(BO2, LOW);
  printval();
}
void clockwise(){   //BO1 off while BO2 on gives Clock
  digitalWrite(BO1, LOW);
  digitalWrite(BO2, HIGH);
  printval();
}
void Stop(){
  digitalWrite(BO1, LOW);
  digitalWrite(BO2, LOW);
  printval();
}
//----------------------------------------------------

//Print which input pin is on for the TB66 for future Debug test
void printval(){
//  Serial.print("B1: "); Serial.println(digitalRead(BO1));
//  Serial.print("B2: "); Serial.println(digitalRead(BO2));
}

//RPM control for Motor
void getSetSpeed(){
  speedval= map(yval,0,1023,0,255); //takes yval and divides 0 to 1023 val by 4 (255)
 // Serial.print("speedval:");Serial.println(speedval);
  analogWrite(pwmB, speedval);  //sends speedval to PWMB on tb66
}

void getSetDirection(){ //Test to see if the input from the Joystick is working
  if(xval>700){
  //  Serial.println("counterclockwise");
    counterclockwise();
  }
  else if(xval<300){
  //  Serial.println("clockwise");
    clockwise();
  }
  else if(xval>=300 && xval<=700){  //if not surpass threshold, no movement
    Stop();

  }
}
