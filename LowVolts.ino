void lowVolt(){
  sensorValue = analogRead (batt);
  voltage = (sensorValue/1024)*8.75;
  if (voltage >= 7.4){battstat = 3;}
  else if (voltage <= 6.5 && voltage > 6.2) {battstat = 1;} 
  else if (voltage <= 6.2) {battstat = 0;} 
  else {battstat = 2;}
}
