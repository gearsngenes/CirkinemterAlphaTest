void publishRPS(){
  unsigned long deltaT = millis() - curtime;
    
//    Serial.print("no of rotations:"); Serial.print(count); Serial.print(" detaT: "); Serial.println(deltaT);
    
    rps = (count * 1000.0) / (deltaT);
    omega = rps *3.14159*2;
    
 //   Serial.print("RPS: "); Serial.println(rps);
  //  Serial.print("Omg.: "); Serial.println(omega);
    oledPrint();
    count = 0;
}

