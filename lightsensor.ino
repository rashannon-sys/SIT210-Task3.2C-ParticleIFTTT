#include <BH1750Lib.h>
#define brightLightThreshold 8000

BH1750Lib lightmeter;

void setup(){
    Serial.begin(9600);
    lightmeter.begin(BH1750LIB_MODE_CONTINUOUSHIGHRES);
    Serial.println("Running...");
}


void loop() {
    uint16_t lux = lightmeter.lightLevel();
    if (lux > brightLightThreshold)
    {
        Particle.publish("lightLevel", "sun");
    }
    else
    {
        Particle.publish("lightLevel", "dark");
    }
    delay(5000);
}


