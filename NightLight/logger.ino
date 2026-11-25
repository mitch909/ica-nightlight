// logger.ino - prints status messages to the Serial Monitor (9600 baud)

// TODO Task 4 (Project Manager): add modeName() here.

// logger.ino - prints status messages to the Serial Monitor (9600 baud)

const char* modeName(Mode m) {
  switch (m) {
    case MODE_OFF:  return "OFF";
    case MODE_AUTO: return "AUTO";
    case MODE_ON:   return "ON";
    default:        return "UNKNOWN";
  }
}

void logStatus(int light) {
  static unsigned long lastLogMs = 0;
  unsigned long now = millis();
  if (now - lastLogMs < LOG_INTERVAL_MS) {
    return;
  }
  lastLogMs = now;

  Serial.print("mode=");
  Serial.print(modeName(currentMode));
  Serial.print(" light=");
  Serial.print(light);
  Serial.print(" led=");
  Serial.print(ledBrightness);
  Serial.print(" room=");
  Serial.println(lightLabel(light));
}

// TODO Task 6 (Developer B): add logBanner() below this line.

// TODO Task 6 (Developer B): add logBanner() below this line.
void logBanner() {
  Serial.println("NightLight");
  Serial.println("Press the button to switch modes: OFF -> AUTO -> ON");
}
