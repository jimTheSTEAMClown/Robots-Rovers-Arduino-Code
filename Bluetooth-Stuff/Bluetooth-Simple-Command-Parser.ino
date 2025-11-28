// Sketch: HC06_Blynk_compatible_serial_commands.ino
// Simple serial command parser for HC-06 (classic Bluetooth SPP).
#include <SoftwareSerial.h>

SoftwareSerial btSerial(10, 11); // RX, TX to HC-06
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);        // debug
  btSerial.begin(9600);        // HC-06 default
  Serial.println("Ready");
}

void loop() {
  // Read from BT and act
  if (btSerial.available()) {
    String cmd = btSerial.readStringUntil('\n');
    cmd.trim();
    Serial.print("BT cmd: "); Serial.println(cmd);
    if (cmd.equalsIgnoreCase("LED ON")) {
      digitalWrite(ledPin, HIGH);
      btSerial.println("OK:LED ON");
    } else if (cmd.equalsIgnoreCase("LED OFF")) {
      digitalWrite(ledPin, LOW);
      btSerial.println("OK:LED OFF");
    } else if (cmd.startsWith("PWM ")) {
      int val = cmd.substring(4).toInt(); // PWM 0-255
      val = constrain(val, 0, 255);
      analogWrite(ledPin, val);
      btSerial.print("OK:PWM "); btSerial.println(val);
    } else if (cmd.equalsIgnoreCase("STATUS")) {
      btSerial.print("STATUS:LED ");
      btSerial.println(digitalRead(ledPin) ? "ON" : "OFF");
    } else {
      btSerial.println("ERR:UNKNOWN Message");
    }
  }

  // Optional: forward USB Serial <-> BT for debugging
  if (Serial.available()) {
    char c = Serial.read();
    btSerial.write(c);
  }
}
