// Pin for DAC1 (GPIO 25)
const int dacPin = 25;  

void setup() {
  // No setup needed for the basic dacWrite function
  Serial.begin(115200);
  Serial.println("ESP32 DAC Sawtooth Wave Example");
}

void loop() {

  // Gradually increase the voltage from 0V to 3.3V
  int voltage = 128;
  dacWrite(dacPin, voltage);
}