#include <ArduinoBLE.h>
const char* deviceServiceUuid = "19b10000-e8f2-537e-4f6c-d104768a1214";
const char* deviceServiceCharacteristicUuid = "19b10001-e8f2-537e-4f6c-d104768a1214";
BLEService co2Service(deviceServiceUuid); 
BLEByteCharacteristic co2Characteristic(deviceServiceCharacteristicUuid, BLERead | BLEWrite);


void setup() {
  Serial.begin(9600);
  while (!Serial);  
  if (!BLE.begin()) {
    Serial.println("- Starting Bluetooth® Low Energy module failed!");
    while (1);
  }

  BLE.setLocalName("Arduino Nano 33 BLE (Peripheral)");
  BLE.setAdvertisedService(co2Service);
  co2Service.addCharacteristic(co2Characteristic);
  BLE.addService(co2Service);
  co2Characteristic.writeValue(-1);
  BLE.advertise();

  Serial.println("Nano 33 BLE (Peripheral Device)");
  Serial.println(" ");
}

void loop() {
  BLEDevice central = BLE.central();
  Serial.println("- Discovering central device...");
  delay(500);

  if (central) {
    Serial.println("* Connected to central device!");
    Serial.print("* Device MAC address: ");
    Serial.println(central.address());
    Serial.println(" ");

    while (central.connected()) {
      if (co2Characteristic.written()) {
         int co2 = co2Characteristic.value();
         Serial.println(co2*20);
       }
    }
    
    Serial.println("* Disconnected to central device!");
  }
}
