void setup() {
  Serial.begin(9600);   // SAME as scale baud rate
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    Serial.write(c);   // echo back exactly
  }
}
