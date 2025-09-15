// C++ code
// Libraries Used


// Program Pin as Constants
const int status_led_pin = 13;
const int sensor_pin = 7;

// Program Global Variables
int sensor_status = -1;

void setup()
{
  pinMode(status_led_pin, OUTPUT);
  pinMode(sensor_pin, INPUT_PULLUP); // Button has pullup
}

void loop()
{
  digitalWrite(status_led_pin, HIGH);
  delay(300); // Wait for a few millisecond(s)
  digitalWrite(status_led_pin, LOW);
  delay(300); // Wait for a few millisecond(s)
}
