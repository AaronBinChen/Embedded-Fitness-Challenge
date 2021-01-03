#include <Adafruit_CircuitPlayground.h>
#include "pitches.h"

// we light one pixel at a time, this is our counter for number of repetitions
int num_of_repetitions = 0;
// variables for accelerometer data
float X, Y, Z;
// variables to keep track of the completion of up/down movement of each exercise
bool pushup_up = false;
bool pushup_down = false;
bool situp_up = false;
bool situp_down = false;
bool jumpjack_up = false;
bool jumpjack_down = false;
bool squat_up = false;
bool squat_down = false;

// Variables for Completion Music after a set of 10 repetitions is done
const int numNotes = 8;                                                               // number of notes we are playing
int melody[] = { NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4 };  // specific notes in the melody
 
int noteDurations[] = { 4, 8, 8, 4, 4, 4, 4, 4 };                                     // note durations: 4 = quarter note, 8 = eighth note, etc.

void completion_music() {
    for (int thisNote = 0; thisNote < numNotes; thisNote++) {                         // play notes of the melody
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      CircuitPlayground.playTone(melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
    }
}

// Begin Serial Monitor and Plotter, Circuit Playground and Clear All of the Lighted Up NeoPixels Upon Startup
void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels();
}

void loop() {
  // reading in the accelerometer data
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();

  //printing out the accelerometer data on Serial Monitor for Testing
  Serial.print("X: ");
  Serial.print(X);
  Serial.print("  Y: ");
  Serial.print(Y);
  Serial.print("  Z: ");
  Serial.println(Z);

  // If the slideSwitch is turned to the left, we will start analyzing the accelerometer data. Otherwise, no data being analyzed.
  if (CircuitPlayground.slideSwitch() == 1){
    // Pushup Conditions --------------------------------------------------------------------------------------------------------------
    if (((X > -3) && (X < -1)) && ((Y > -5) && (Y < 3)) && ((Z > -16) && (Z < -6))){
      pushup_up = true;                                                                       // Up Position (Motion) of Pushup                                                 
    }
    else if ((X > -1) && ((Y > -5) && (Y < 3)) && ((Z > -16) && (Z < -6))){
      pushup_down = true;                                                                     // Down Position (Motion) of Pushup
    }
    // If we moved up and down, we did one pushup. 
    if (pushup_up == true && pushup_down == true)
    {
      pushup_up = false;                                                                      // Reset boolean variables
      pushup_down = false;                                                                    // Reset boolean variables
      // Lighting up the NeoPixels (one for each repetition, red for pushup)
      CircuitPlayground.setPixelColor(num_of_repetitions, 255, 0, 0);
      num_of_repetitions = num_of_repetitions + 1;                                            // Increase number of repetitions
      CircuitPlayground.playTone(400, 1000);                                                  // Tone to denote one pushup
      Serial.println("This is a pushup");                                                     // Serial Monitor Output for Testing
    }
    
    // Situp Condition ---------------------------------------------------------------------------------------------------------------
    if (((X < -8) && (X > -16)) && ((Y > -4) && (Y < 1)) && ((Z < 2) && (Z > -5))){
      situp_up = true;                                                                        // Up Position (Motion) of Situp
    }
    else if (((X < 1) && (X > -2)) && ((Y > -4) && (Y < 1)) && ((Z > 8) && (Z < 16))){
      situp_down = true;                                                                      // Down Position (Motion) of Situp
    }
    // If we moved up and down, we did one situp. 
    if (situp_up == true && situp_down == true){
      situp_up = false;                                                                       // Reset boolean variables
      situp_down = false;                                                                     // Reset boolean variables
      // Lighting up the NeoPixels (one for each repetition, green for situp)
      CircuitPlayground.setPixelColor(num_of_repetitions, 0, 255, 0);
      num_of_repetitions = num_of_repetitions + 1;                                            // Increase number of repetitions
      CircuitPlayground.playTone(500, 1000);                                                  // Tone to denote one situp
      Serial.println("This is a situp");                                                      // Serial Monitor Output for Testing
    }
  
    // Jumping Jack Condition -------------------------------------------------------------------------------------------------------
    if (((X > -10) && (X > -10)) && ((Z < 5) && (Z > -5)) && ((Y < 5) && (Y > -5))){
      jumpjack_up = true;                                                                     // Up Position (Motion) of Jumping Jack
    }
    else if (((X < -15) && (X > -20)) && ((Z < 5) && (Z > -5)) && ((Y < 5) && (Y > -5))){
      jumpjack_down = true;                                                                   // Down Position (Motion) of Jumping Jack
    }
    // If we moved up and down, we did one jumping jack.
    if (jumpjack_up == true && jumpjack_down == true){
      jumpjack_up = false;                                                                    // Reset boolean variables
      jumpjack_down = false;                                                                  // Reset boolean variables
      // Lighting up the NeoPixels (one for each repetition, blue for jumping jack)
      CircuitPlayground.setPixelColor(num_of_repetitions, 0, 0, 255);                         
      num_of_repetitions = num_of_repetitions + 1;                                            // Increase number of repetitions
      CircuitPlayground.playTone(600, 1000);                                                  // Tone to denote one jumping jack
      Serial.println("This is a jumping jack");                                               // Serial Monitor Output for Testing
    }
  
    // Squat Condition --------------------------------------------------------------------------------------------------------------
    if (((Z > -2) && (Z < 2)) && ((Y > -4) && (Y < 4)) && ((X < -6) && (X > -12))){
      squat_up = true;                                                                        // Up Position (Motion) of Squat
    }
    else if ((Z < -3) && ((Y > -4) && (Y < 4)) && ((X < -6) && (X > -12))){
      squat_down = true;                                                                      // Down Position (Motion) of Squat
    }
    // If we moved up and down, we did one squat.
    if (squat_up == true && squat_down == true){
      squat_up = false;                                                                      // Reset boolean variables
      squat_down = false;                                                                    // Reset boolean variables
      // Lighting up the NeoPixels (one for each repetition, white for squat)
      CircuitPlayground.setPixelColor(num_of_repetitions, 125, 125, 125);                    
      num_of_repetitions = num_of_repetitions + 1;                                           // Increase number of repetitions
      CircuitPlayground.playTone(700, 1000);                                                 // Tone to denote one squat
      Serial.println("This is a squat");                                                     // Serial Monitor Output for Testing
    }
    
    // Reset counter and NeoPixels once counter hits 10, AND play some music to signal the end of the set----------------------------
    if (num_of_repetitions == 10)
    {
      num_of_repetitions = 0;
      CircuitPlayground.clearPixels();
      completion_music();
    }
    delay(200);
  }
}
