#include <Timer.h>

void setup() {
  //We need to enable interrupts for the timers to work
  sei();

  //Call timer::init(), because we have to
  timer::init();

  //To create a stopwatch, we use the following syntax: Stopwatch *a stopwatch name*
  Stopwatch my_stopwatch;
  //Reset the stopwatch to make sure everything is ready
  my_stopwatch.reset();
  //To start the stopwatch, call the start function. It will count in milliseconds.
  my_stopwatch.start();

  //Create an 64 bit unsigned int to store the stopwatch value
  uint64_t stopwatch_value;
  //We can take the value at any time. We need to cast the stopwatch to a uint64_t to read it though (well, we don't actually, but trying not to confuse)
  stopwatch_value = (uint64_t)my_stopwatch;
  
  //To stop the stopwatch, call the stop function.
  my_stopwatch.stop();

  //We can also take the stopwatch value after it has stopped
  stopwatch_value = (uint64_t)my_stopwatch;

  //To reset the stopwatch to zero, call reset
  my_stopwatch.reset();
}

void loop() {
  // put your main code here, to run repeatedly:

}
