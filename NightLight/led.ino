// led.ino - controls the LED brightness (0 = off, 255 = full brightness)

int ledBrightness = 0;   // remembers the current brightness

void setLed(int brightness) {
  ledBrightness = constrain(brightness, 0, 255);
  analogWrite(LED_PIN, ledBrightness);
}

// Moves the LED toward the target brightness.
void fadeTowards(int target) {
  // TODO Task 2 (Developer B): fade in small steps instead of jumping.
  if (ledBrightness < target) {
    // Step up, but never past the target
    setLed(min(ledBrightness + FADE_STEP, target));
  } else if (ledBrightness > target) {
    // Step down, but never past the target
    setLed(max(ledBrightness - FADE_STEP, target));
  }
  // If they are equal, do nothing
}

// TODO Task 7 (Developer C): add blinkLed() below this line.
