# Embedded-Fitness-Challenge
<h1> Project Description </h1>
<p> 
  The COVID-19 pandemic has forced almost all gyms to close until further notice. Because of this, many of us have become sedentary and are suffering from lack of sufficient exercise causing fatigue and obesity creating the need for new exercising options. The objective of this embedded project is to use the data collected from a single accelerometer to record body movements to identify one of 4 exercises:
  <ol>
    <li>Sit-ups</li>
    <li>Pushups</li>
    <li>Jumping Jacks</li>
    <li>Squats</li>
  </ol>
</p>

<h2> Project Thought Process</h2>
<p> 
  For this project the usage of the accelerometer is absolutely necessary. With the accelerometer, there are datapoints such as the X-axis, Y-axis, and Z-axis that are generated as a result from the accelerometer. To make the best use of these datapoints, the microcontrollr is best attached to the chest area. A belt held this microcontroller to my chest. The microcontroller will be pointed upward (JST Battery Connector on the top and Micro-B USB Jack on the bottom).
</p>

<p>
  Instead of using two buttons available on the microcontroller, the slide switch was used instead. Leave this switched to the right, the value read is 'low' (- symbol). Once the microcontroller is strapped onto the chest, make sure we're in position to start the exercise. When we are about to start the exercise, slide the switch to the left, the value reading is 'high' (thus the + symbol). Once this switch is slided to the left, begin any form of exercise (pushups, situps, squats or jumping jacks). There is no set order of what exercises should be done. In contrast from the project proposal, I will not be creating four functions. I will keep everything inside the loop() function as the code is pretty simplified in terms of the logic path. 
</p>

<p>
  I will be using if-conditions to detect the up and down motion of every exercise. These if-conditions will be looking at specific ranges for the X,Y, and Z data.

  After every repetition of an exercise is done, one NeoPixel will light up with a specific color (each color corresponds to one form of exercise). For example, a red NeoPixel will correspond to one pushup. Once there are ten repetitions, the ten lit NeoPixels will turn off and a melody will be played to signal the end of a set of 10 repetitions for that exercise. Make sure to perform 10 repetitions of an exercise before changing to another exercise. Before we change positions to perform other exercises, MAKE SURE TO SLIDE THE SLIDE SWITCH TO THE RIGHT. This is because we don't want anything to happen in case we trigger something while changing positions. Once we obtain the position that's required for a different exercise, we will slide the slide switch to the left now to begin the exercise again. Once you're done with all four exercises, congratulations, you're done!
</p>

<h3> Instructions (How to Use the Microcontroller) </h3>
<ol>
  <li>Downloade the .ino file and pitches.h file and keep in the same directory. Compile .ino file and upload onto microcontroller (Arduino Circuit Playground) </li>
  <li>Strap the microcontroller around your chest (JST Battery Connector on the TOP, Micro-B USB Jack on the BOTTOM). Surface with the NeoPixels should be facing outward from the body.</li>
  <li>Keep the slide switch slided to the - symbol until you're ready to start your exercises in the required position.</li>
  <li>Get in position of the exercise you want to perform. Slide the slide switch to the left (+ symbol). Do 10 repetitions of one exercise. When you're done with 10 repetitions, the NeoPixels will be shut off automatically. A tune will also be played to signal the end of one set.</li>
  <li>Slide the slide switch to the right (- symbol). This avoids the issue of an exercise being detected (in actuality, there was no exercise performed) when we are changing positions for another exercise. </li>
  <li>Repeat steps 2 - 4 until you finished all four exercises. Congratulations! Good work on your journey to stay healthy!</li>
</ol>
  
