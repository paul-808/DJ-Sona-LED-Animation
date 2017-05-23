void smile (){

 if(beatFrame % 150 < 4 || beatFrame % 150 == 15 || beatFrame % 150 == 16){ 
  for (uint8_t x = 0;  x < 24; x++){ 
    for (uint8_t y = 0; y < 16; y++){
            uint8_t r = SmileBlink[15-y][x]*255/bright;
            uint8_t g = SmileBlink[15-y][x]*255/bright;
            uint8_t b = SmileBlink[15-y][x]*255/bright;
            int pixelIndex = location[y][x];
            leds.setPixel(pixelIndex, ((r << 16) | (g << 8) | b));     
    }
  } 
 }
 else{
  for (uint8_t x = 0;  x < 24; x++){ 
    for (uint8_t y = 0; y < 16; y++){
            uint8_t r = Smile[15-y][x]*255/bright;
            uint8_t g = Smile[15-y][x]*255/bright;
            uint8_t b = Smile[15-y][x]*255/bright;
            int pixelIndex = location[y][x];
            leds.setPixel(pixelIndex, ((r << 16) | (g << 8) | b));     
    }
  } 
  
  } 
    digitalWrite(13, HIGH);
    leds.show();  // not sure if this function is needed  to update each frame
    digitalWrite(13, LOW);

    if (millis() > lastBeat + 29){
    beatFrame ++;
    lastBeat = millis();
    }
}

