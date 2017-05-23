int fader (int currentpixel, int faderate){
  
  // get the pixel value

int rgb = leds.getPixel(currentpixel);
int b1 = rgb & 255;
int g1 = (rgb & 65280) >> 8;
int r1 = (rgb & 16711680) >> 16;
int b2 = b1 - faderate;
int g2 = g1 - faderate;
int r2 = r1 - faderate;
int rgb2 = ((r2 << 16) | (g2 << 8) | b2);
  
  // 
  return(rgb2);
  }
