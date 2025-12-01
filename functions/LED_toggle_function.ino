const int LED_PIN = 13;

// This function blinks the LED every 1000ms for 100ms, preserving its own state
void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  timedToggle();   // call repeatedly; function manages its own timing using static locals
  // other non-blocking code can go here
}

// Function encapsulates state with static locals
void timedToggle() {
  unsigned long now = millis();

  // static locals: preserve value across calls but invisible outside this function
  static unsigned long lastChange = 0;   // stores last time the LED changed
  static bool isOn = false;              // current state

  const unsigned long INTERVAL_ON = 200;     // how long ON (ms)
  const unsigned long INTERVAL_PERIOD = 1000; // total period (ms)

  if (isOn) {
    // If LED is on and ON interval passed, turn it off
    if (now - lastChange >= INTERVAL_ON) {
      isOn = false;
      digitalWrite(LED_PIN, LOW);
      lastChange = now;
      Serial.println("timedToggle: turned OFF");
    }
  } else {
    // If LED is off and time to start a new on period
    if (now - lastChange >= (INTERVAL_PERIOD - INTERVAL_ON)) {
      isOn = true;
      digitalWrite(LED_PIN, HIGH);
      lastChange = now;
      Serial.println("timedToggle: turned ON");
    }
  }
}
