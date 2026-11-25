// light_sensor.ino - reads the photoresistor on LIGHT_SENSOR_PIN
// Returns 0 (dark) up to 1023 (bright).

/* Read the light sensor and average SENSOR_SAMPLES readings to reduce noise.
*
*  @return the average light reading (0-1023)
*/
int readLight() {
  int sum = 0;
  for (int i = 0; i < SENSOR_SAMPLES; i++) {
    sum += analogRead(LIGHT_SENSOR_PIN);
    delay(10);
  }
  return sum / SENSOR_SAMPLES;
}

// TODO Task 8 (Project Manager): add lightLabel() below this line.
