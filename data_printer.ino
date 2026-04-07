#include <SoftwareSerial.h>

// RX, TX
SoftwareSerial scaleSerial(9, 8);

void setup() {
  scaleSerial.begin(9600);
  delay(30);
}

void loop() {
  scaleSerial.print("00000200 mg\r\n");
  scaleSerial.print("00000300 mg\r\n");
  scaleSerial.print("00000400 mg\r\n");
  scaleSerial.flush();

  delay(30);
}
