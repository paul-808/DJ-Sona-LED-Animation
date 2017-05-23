void kittehz (){

 if(beatFrame % 150 < 4 || beatFrame % 150 == 15 || beatFrame % 150 == 16){ 
  for (uint8_t x = 0;  x < 24; x++){ 
    for (uint8_t y = 0; y < 16; y++){
            uint8_t r = kitteh2[15-y][x]*255/bright;
            uint8_t g = kitteh2[15-y][x]*55/bright;
            uint8_t b = kitteh2[15-y][x]*25/bright;
            int pixelIndex = location[y][x];
            leds.setPixel(pixelIndex, ((r << 16) | (g << 8) | b));     
    }
  } 
 }
 else{
  for (uint8_t x = 0;  x < 24; x++){ 
    for (uint8_t y = 0; y < 16; y++){
            uint8_t r = kitteh[15-y][x]*255/bright;
            uint8_t g = kitteh[15-y][x]*55/bright;
            uint8_t b = kitteh[15-y][x]*25/bright;
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

