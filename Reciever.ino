#include <SPI.h>

#include <NRFLite.h>


float coordinatesrx [2];
struct RadioPacket1 {
uint8_t FromRadioId;
float crd [2];

};
NRFLite _radio;
RadioPacket1 _crdData;  
void setup()

{

    Serial.begin(115200);

    _radio.init(1, 9, 10); // Set this radio's Id = 1, along with its CE and CSN pins

}

void loop()

{
uint8_t packetSize = _radio.hasData();
    if (packetSize == sizeof(RadioPacket1))

    {

        _radio.readData(&_crdData);
        float crd[2] = {_crdData.crd[0], _crdData.crd[1]}
        


        
        Serial.println(crd[0], crd[1]);

    }

}
