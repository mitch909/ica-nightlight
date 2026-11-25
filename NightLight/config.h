// config.h - pins and settings shared by every file in the sketch.
// Tip: put your new setting inside YOUR OWN section so that teammates'
// edits do not collide with yours.
// Declare settings as typed constants (const int ...), not with #define.

#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ---------- Wiring ----------
const int LED_PIN          = 9;    // must be a PWM pin (marked with ~)
const int BUTTON_PIN       = 2;
const int LIGHT_SENSOR_PIN = A0;

// ---------- Modes ----------
enum Mode { MODE_OFF, MODE_AUTO, MODE_ON };

// ---------- Light sensor settings (Task 1, Developer A) ----------
const int SENSOR_SAMPLES = 8;  // number of readings to average for light sensor

// ---------- LED settings (Task 2, Developer B) ----------
// TODO Task 2: add any settings you need here (for example: const int FADE_STEP = 5;)
const int FADE_STEP = 5;

// ---------- Button settings (Task 3, Developer C) ----------
// TODO Task 3: add any settings you need here (for example: const unsigned long BUTTON_DEBOUNCE_MS = 40;)

// ---------- Logger settings (Task 4, Project Manager) ----------
// TODO Task 4: add any settings you need here (for example: const unsigned long LOG_INTERVAL_MS = 500;)
const unsigned long LOG_INTERVAL_MS = 500;  // how often to log (in milliseconds)
// ---------- Night light behavior (shared by everyone) ----------
const int DARK_THRESHOLD    = 500;  // light readings below this mean "dark"
const int NIGHT_BRIGHTNESS = 120;  // LED brightness (0-255) when it is dark
const int LOOP_DELAY_MS    = 20;

#endif
