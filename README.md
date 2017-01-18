# DJ-Sona-LED-Animation
Code for a teenshy-controlled LED display integrated into a DJ Sona costume


// Cosplay Controller

// By Paul Jarvey

// Sept 1, 2016

// Note: contains "plasma generator" by Edmund "Skorn" Horn

// Hardware: Teensy + OctoWS2811Lib + OctoWS2811 Shield + FFT

This code controls a large LED array for a DJ Sona costume, including an animated faceplate array, a dj 'deck', and various lights thoughout the costume. Animations include three modes, each of which plays a beat-responsive animation correspnoding to one of the 'modes' of the DJ Sona character. Over 1200 WS2812b LEDs are used, and the system is powered using a large LiPO battery and some power regulation circuitry. For those building similar projects, be warned that this many LEDs of this type can draw close to 30A continuous current! It can also make quite the impression in a dark room, and works great even in direct sunlight.

