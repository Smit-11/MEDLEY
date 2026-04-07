#include <SoftwareSerial.h>

SoftwareSerial tsc(8, 9); // RX, TX

void setup() {
  Serial.begin(9600);
  tsc.begin(9600);

  delay(1000);

  // Reset printer
  tsc.println("SIZE 75 mm,50 mm");
  tsc.println("GAP 3 mm,0");
  tsc.println("DIRECTION 1");
  tsc.println("CLS");

  // Text
  tsc.println("TEXT 50,40,\"3\",0,1,1,\"SHREE VINAYAK\"");
  tsc.println("TEXT 50,80,\"3\",0,1,1,\"WEIGHT: 25.60 KG\"");

  // Barcode
  tsc.println("BARCODE 50,120,\"128\",80,1,0,2,2,\"SVWS2560\"");

  // Print 1 label
  tsc.println("PRINT 1,1");
}

void loop() {
}
