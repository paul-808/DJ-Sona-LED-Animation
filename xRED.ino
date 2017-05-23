void red (){

 
  for (uint8_t x = 0;  x < 24; x++){ 
    for (uint8_t y = 0; y < 15; y++){
      if (x<5){
            uint8_t r = redwave[15-y][x]/bright;
            uint8_t g = redwave[15-y][x]*.1/bright;
            uint8_t b = 0;
            int pixelIndex = location[y][x];
            leds.setPixel(pixelIndex, ((r << 16) | (g << 8) | b));} 
      else if (x > 4 && x < 10){
            uint8_t r = redwave2[15-y][5+beatFrame%10+x-8]/bright;
            uint8_t g = redwave2[15-y][5+beatFrame%10+x-9]*0/bright;
            uint8_t b = 0;
            int pixelIndex = location[y][x];
            leds.setPixel(pixelIndex, ((r << 16) | (g << 8) | b));}     
      else if (x > 9 && x < 15){
            uint8_t r = redwave2[15-y][5+beatFrame%10+x-4]/bright;
            uint8_t g = redwave2[15-y][5+beatFrame%10+x-5]*0/bright;
            uint8_t b = 0;
            int pixelIndex = location[y][x];
            leds.setPixel(pixelIndex, ((r << 16) | (g << 8) | b));}  
      else if (x > 14 && x < 19){
            uint8_t r = redwave[15-y][5+beatFrame%10+x-14]*.5/bright;
            uint8_t g = redwave[15-y][5+beatFrame%10+x-14]*0/bright;
            uint8_t b = 0;
            int pixelIndex = location[y][x];
            leds.setPixel(pixelIndex, ((r << 16) | (g << 8) | b));}  
      else if (x>18){
            uint8_t r = redwave[15-y][x]/bright;
            uint8_t g = redwave[15-y][x]*.1/bright;
            uint8_t b = 0;
            int pixelIndex = location[y][x];
            leds.setPixel(pixelIndex, ((r << 16) | (g << 8) | b));}       
  }
    }
 
 for (uint16_t x = 1;  x < 25; x++){
                uint8_t r = blueFader[((beatFrame-12) % 15)][0]/bright;
                uint8_t g = blueFader[((beatFrame-11) % 15)][1]*0/bright;
                uint8_t b = 0;
                int pixelIndex = location[15][x];
                leds.setPixel(pixelIndex, ((r << 16) | (g << 8) | b)); 
    }

 for (uint16_t v = 385;  v < 1250; v++){
                uint8_t r = blueFader[((beatFrame-12) % 15)][0]/bright;
                uint8_t g = blueFader[((beatFrame-11) % 15)][1]*0/bright;
                uint8_t b = 0;
                leds.setPixel(v, ((r << 16) | (g << 8) | b)); 
    }
    
    digitalWrite(13, HIGH);
    leds.show();  // not sure if this function is needed  to update each frame
    digitalWrite(13, LOW);

    if (millis() > lastBeat + 29){
    beatFrame ++;
    lastBeat = millis();
    }
}

