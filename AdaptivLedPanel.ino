#define LED_PIN    D2   // Define the pin for the LED panel
#define LDR_PIN    A0   // Define the pin for the LDR sensor

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);
  Serial.begin(115200);
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);  // Read LDR sensor value (0-1023)
  int brightness = map(ldrValue, 0, 1023, 0, 255);  // Map LDR value to brightness (0-255)

  // Ensure brightness is within a reasonable range (0-255)
  brightness = constrain(brightness, 0, 255);

  // Set the LED panel brightness
  analogWrite(LED_PIN, brightness);

  // You can also print the brightness value for debugging
  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print(", Brightness: ");
  Serial.println(brightness);

  delay(1000);  // Adjust the update frequency as needed
}
