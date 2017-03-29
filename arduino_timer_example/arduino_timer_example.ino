#include <Timer.h>

//This sketch should cause an LED to blink on pin 11

void setup() {
  //Set pin 11 to an output
  pinMode(11, OUTPUT);

  //For the timers to work, we have to enable interrupts. That's what sei() does.
  sei();
  //We need to call timer::init() before we do anything with the timers
  timer::init();

  //To create a timer, do the following:
  //Timer *a timer name*
  Timer my_timer;
  //We created a timer called my_timer

  //Set the timer to 1000 milliseconds
  my_timer = 1000;
  //Start the timer
  my_timer.start();

  //We use a boolean value to store the current timer state
  bool currentState;
  //Run an infinate loop
  while(true) {
    //When the timer has run out, it will be "true"
    //To compare the timer and a boolean value (such as "true"), we need to cast (change) the timer into a bool. This is done by putting (bool) in front of the timer.
    if((bool)my_timer == true) {
      //Change the state of the LED
      digitalWrite(11, currentState = !currentState);
      //Reset the timer
      my_timer.reset();
      //Start the timer again. It will now be "false", and won't be true again until the time has run out.
      my_timer.start();
    }
  }
}

void loop() {
  
}
