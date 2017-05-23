void plasma (){
     // arbitrary seed to calculate the three time displacement variables t,t2,t3
 
  if(buttonState = 4) {
    frameCount++ ; 
    uint16_t t = fastCosineCalc((42 * frameCount)/100);  //time displacement - fiddle with these til it looks good...
    uint16_t t2 = fastCosineCalc((35 * frameCount)/100); 
    uint16_t t3 = fastCosineCalc((38 * frameCount)/100);

    for (uint8_t y = 0; y < 16; y++) {   // change to y < ROWS_LEDs to write to all
        int left2Right, pixelIndex;
//      if (((y % (ROWS_LEDs/8)) & 1) == 0) {
//        left2Right = 1;
//        pixelIndex = y * COLS_LEDs;
//      } else {
//        left2Right = -1;
//        pixelIndex = (y + 1) * COLS_LEDs - 1;
//      }
      for (uint8_t x = 0; x < 24 ; x++) { //change to x< COLS_LEDs to write to all
        //Calculate 3 seperate plasma waves, one for each color channel
        uint8_t r = fastCosineCalc(((x << 3) + (t >> 1) + fastCosineCalc((t2 + (y << 3)))))/bright;
        uint8_t g = fastCosineCalc(((y << 3) + t + fastCosineCalc(((t3 >> 2) + (x << 3)))))/(bright*10);
        uint8_t b = fastCosineCalc(((y << 3) + t2 + fastCosineCalc((t + x + (g >> 2)))))/(bright+5);
              //uncomment the following to enable gamma correction
              //r=pgm_read_byte_near(exp_gamma+r);  
              //g=pgm_read_byte_near(exp_gamma+g);
              //b=pgm_read_byte_near(exp_gamma+b);
        pixelIndex = location[y][x];
        leds.setPixel(pixelIndex, ((r << 16) | (g << 8) | b)); 

            //ears etc
             if (x == 12 && y == 0){
              for(int v = 385; v < 1250; v++){
                 leds.setPixel(v, ((r << 16) | (g << 8) | b)); 
              }
             }

      }
    }
    digitalWrite(13, HIGH);
    leds.show();  // not sure if this function is needed  to update each frame
    digitalWrite(13, LOW);
    
} 
  }

inline uint8_t fastCosineCalc( uint16_t preWrapVal)
{
  uint8_t wrapVal = (preWrapVal % 255);
  if (wrapVal<0) wrapVal=255+wrapVal;
  return (pgm_read_byte_near(cos_wave+wrapVal)); 
}
