#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
/*
 * Define the variables:
 * -km counter
 */
 int kmPin=10;
 volatile unsigned long actualTime;
 volatile unsigned int timeIncrement;
 volatile unsigned long previousTime;
 volatile unsigned int laps;
 
void setup() {
  // put your setup code here, to run once:
  // initialize the pushbutton pin as an input:
  pinMode(kmPin, INPUT);
  // Attach an interrupt to the ISR vector
  attachInterrupt(0, km_ISR, CHANGE);
  // recover laps from sd

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();   
}

void loop() {
  // put your main code here, to run repeatedly:
  //sleep(1000);
}

void km_ISR () {
  actualTime=micros();
  timeIncrement=(int)(actualTime-previousTime);
  previousTime=actualTime;
  laps++;
}

