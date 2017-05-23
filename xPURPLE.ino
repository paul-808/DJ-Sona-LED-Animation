void purple (){

for (uint8_t x = 0;  x < 24; x++){
  
            //int z = (x*10.6);
            int edge = (7 - columnOffset[1][x])*4;
            for (uint8_t y = 0; y < 16; y++){


            
            
            uint8_t r = ((purpleFader[(beatFrame + (columnOffset[2][x]/5) - (2*y)) % 299][0])/ (bright + edge));
            if(r > 0) {r--;}
            uint8_t g = ((purpleFader[(beatFrame + (columnOffset[2][x]/5)- (2*y)) % 299][1])/(bright + edge));
            if(g > 0) {g--;}
            uint8_t b = ((purpleFader[(beatFrame + (columnOffset[2][x]/5)- (2*y)) % 299][2])/(bright + edge));
            if(b > 0) {b--;}
            pixelIndex = location[y][x];
            leds.setPixel(pixelIndex, ((r << 16) | (g << 8) | b)); 

            //ears etc
             if (x == 12 && y == 0){
              for(int v = 385; v < 1250; v++){
                 leds.setPixel(v, ((r << 16) | (g << 8) | b)); 
              }
             
            }

              
            //glitter
            if(map(beatFrame - lastSY,0,16,0,24)<15){
              pixelIndex = location [map(beatFrame - lastSY,0,16,0,24)][sX];
              int w = 255/((250 - cos_wave[sX])/8);
              leds.setPixel(pixelIndex, ((w << 16) | (w << 8) | w)); }       
    }
  }




 
    digitalWrite(13, HIGH);
    leds.show();  // not sure if this function is needed  to update each frame
    digitalWrite(13, LOW);

    if (millis() > lastBeat + 30){
    beatFrame = beatFrame + 1;
    lastBeat = millis();      
    }

    if (millis() > lastSX + 300 + c ){
      int sY = 5;
      sX = random (24); 
      lastSY = beatFrame;
      lastSX = millis();
      c = random (1000);
      }    
    
    


    
}







 
    

