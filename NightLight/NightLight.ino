// NightLight.ino - main program
//
// Press the button to cycle through three modes: OFF -> AUTO -> ON
//   OFF  : the LED stays off
//   AUTO : the LED fades on when the room is dark
//   ON   : the LED stays on

#include "config.h"

Mode currentMode = MODE_AUTO;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // TODO Task 6 (Developer B): print the startup banner here.
}

void handleButton() {
  if (buttonPressed()) {
    currentMode = (Mode)((currentMode + 1) % 3);

    // TODO Task 7 (Developer C): blink the LED to confirm the mode change.
  }
}


/**
 * Automatically turn on light when it is dark, and turn off when it is light.
 * @param light The measured ambient light level (0-1023)
 */
void applyAuto(int light) {
  if(light < DARK_THRESHOLD) {  // If room is dark
    fadeTowards(NIGHT_BRIGHTNESS);
  } else {
    fadeTowards(0);
  }
}

void applyMode(int light) {
  switch (currentMode) {
    case MODE_OFF:  fadeTowards(0);    break;
    case MODE_AUTO: applyAuto(light);  break;
    case MODE_ON:   fadeTowards(255);  break;
  }
}

void loop() {
  int light = readLight();
  handleButton();
  applyMode(light);
  logStatus(light);
  delay(LOOP_DELAY_MS);
}
