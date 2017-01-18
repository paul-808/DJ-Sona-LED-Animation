// main animatin for BLUE mode

void blue (){

for (uint8_t x = 0;  x < 24; x++){
  
  for (uint8_t y = 0; y < 16; y++){

/// This 4 checks which case to use, based on the beat, or the 128 bpm timer (468ms/16frames = 29ms)    

        if (y < ((((100000-beatFrame)+1) % 15)/1.9) && x > 1 && x < 8){
            uint8_t r = blueForeground[y][0]/bright;
            uint8_t g = blueForeground[y][1]/bright;
            uint8_t b = blueForeground[y][2]/bright;
            int pixelIndex = location[y][x];
            leds.setPixel(pixelIndex, ((r << 16) | (g << 8) | b));           
        }
        else if (y < ((100000-beatFrame) % 15) && x > 8 && x < 17){
            uint8_t r = blueForeground[y][0]/bright;
            uint8_t g = blueForeground[y][1]/bright;
            uint8_t b = blueForeground[y][2]/bright;
            int pixelIndex = location[y][x];
            leds.setPixel(pixelIndex, ((r << 16) | (g << 8) | b));           
        }

        else if (y < ((((100000-beatFrame)+3) % 15)/3) && x > 17 && x < 23){
            uint8_t r = blueForeground[y][0]/bright;
            uint8_t g = blueForeground[y][1]/bright;
            uint8_t b = blueForeground[y][2]/bright;
            int pixelIndex = location[y][x];
            leds.setPixel(pixelIndex, ((r << 16) | (g << 8) | b));           
        }
        
        else{
            uint8_t r = blueBackground[y][0]/bright;
            uint8_t g = blueBackground[y][1]/bright;
            uint8_t b = blueBackground[y][2]/bright;
            int pixelIndex = location[y][x];
            leds.setPixel(pixelIndex, ((r << 16) | (g << 8) | b)); 
        }
    }
  }

// ears etc

    for (uint16_t v = 385;  v < 1250; v++){
                uint8_t r = blueFader[((beatFrame-12) % 15)][0]/bright;
                uint8_t g = blueFader[((beatFrame-11) % 15)][1]/bright;
                uint8_t b = blueFader[((beatFrame-11) % 15)][2]/bright;
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
