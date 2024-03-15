
/*
  This sketch is inspired by the Fade example
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade

  This sketch fade two LEDs on pin 9 and 10 using the analogWrite() function.

  The goal of this sketch :

  It's for mesearing the resistance of an LDR (Light Dependant Resistor) at differents step of light generated by a led.
  Thus we know the value of the LDR at each step of light.
  We could know which LDRs, in a bunch of 100, have the same values of resistance.

  Settings :
  I set fadeAmount to 50, thus i have 5 steps, but it's also possible to set fadeAmount to 25 to have 10 steps for a more accurate measurement.
  I set the delay to 5000ms to have time to do the measurement, but it's also possible to set the delay time with a smaller value if you're quick or a higher value if you're slow.

  Warning :
  Be careful, because LDRs have a delay before they return to their initial value. So, if you go too fast and measure the values several times, you'll end up with values that change with each measurement.

  This example code is CC By SA.
  https://github.com/dubhalley/Vactrol_Enclosure

*/

int ledVactrol = 9;   // the PWM pin the LED is attached to, for the Vactrol
int ledControl = 10;  // the PWM pin the LED is attached to, for the visual check
int brightness = 0;   // how bright the LED is
int fadeAmount = 50;  // how many points to fade the LED by from 0 to 255

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 and 10 to be an output:
  pinMode(ledVactrol, OUTPUT);
  pinMode(ledControl, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9 and 10:
  analogWrite(ledVactrol, brightness);
  analogWrite(ledControl, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // the delay is to have time to measure the resistance of the LDR
  delay(5000);

  // set the fading at 0 at the end of the fade:
  if (brightness <= 0 || brightness >= 255) {
    brightness = 0;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}

