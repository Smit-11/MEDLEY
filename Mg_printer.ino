#include <SoftwareSerial.h>

// Printer serial (RX not used, TX = pin 8)
SoftwareSerial printerSerial(9, 8);

String buffer = "";

const int ledPin = 10;

void setup() {
  Serial.begin(9600);          // Scale input
  printerSerial.begin(9600);  // Printer output

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);  // LED OFF initially
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();

    // End of line from scale
    if (c == '\n') {
      processAndSend(buffer);
      buffer = "";
    }
    else if (c != '\r') {
      buffer += c;
    }
  }
}

// ================= PROCESS FUNCTION =================
void processAndSend(String data) {

  // Check if unit is mg
  if (data.indexOf("mg") != -1) {
    data = removeDecimalForMG(data);
  }

  // Turn LED ON when printing
  digitalWrite(ledPin, HIGH);

  // Send to printer
  printerSerial.print(data);
  printerSerial.print("\r\n");

  // Optional: keep LED ON briefly to show print indication
  delay(200);

  // Turn LED OFF
  digitalWrite(ledPin, LOW);
}

// ============ REMOVE DECIMAL BEFORE mg ===============
String removeDecimalForMG(String s) {
  int dotIndex = s.indexOf('.');

  // Remove only the decimal point, keep digits
  if (dotIndex != -1) {
    s.remove(dotIndex, 1);
  }

  return s;
}
