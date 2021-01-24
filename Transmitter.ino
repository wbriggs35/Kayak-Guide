#include <SPI.h>
#include <NRFLite.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;
// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);
NRFLite _radio;


float coordinatesrx [2];

void setup() {
Serial.begin(9600);
  ss.begin(GPSBaud);
  _radio.init(0, 9, 10);

}

void loop() {
 while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);
     coordinatesrx [0] = gps.location.lat();
     coordinatesrx [1] = gps.location.lng();
      delay(1000);
    }
  

 // _radio.send(1, &coordinatesrx, sizeof(coordinatesrx));

  delay(1000);

}
}
