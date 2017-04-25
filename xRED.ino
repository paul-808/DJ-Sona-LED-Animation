// main animation for RED mode (unfinished, currently just pulses gently)
// NOTE: Error test fount an issue between this and the interrupt - an entire animation cycle is run per loop, rather than a single frame. Add interrupts or revise to calculate one frame per loop   
void red (){

              for (int c = 0; c < 256; c++){
                int m = abs(c-128)/bright;
                for (uint16_t v = 0;  v < 1250; v++){
                uint8_t r = (m);
                uint8_t g = 0;
                uint8_t b = 0;
                leds.setPixel(v, ((r << 16) | (g << 8) | b)); 
                }
                
              leds.show();
              }


}
  
