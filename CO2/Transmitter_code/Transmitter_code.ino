#include <ArduinoBLE.h>
#include "Adafruit_CCS811.h"
 
Adafruit_CCS811 ccs;
const char* deviceServiceUuid = "19b10000-e8f2-537e-4f6c-d104768a1214";
const char* deviceServiceCharacteristicUuid = "19b10001-e8f2-537e-4f6c-d104768a1214";

void setup() {
  Serial.begin(9600);
  //digitalWrite(LED_PWR, LOW);
  //while (!Serial);
  
  if (!BLE.begin()) {
    Serial.println("* Starting Bluetooth® Low Energy module failed!");
    while (1);
  }
  Serial.println("CCS811 test");
 
  if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }
 
  // Wait for the sensor to be ready
  while(!ccs.available());
  
  BLE.setLocalName("Nano 33 BLE (Central)"); 
  BLE.advertise();

  Serial.println("Arduino Nano 33 BLE Sense (Central Device)");
  Serial.println(" ");
}

void loop() {
  connectToPeripheral();
}

void connectToPeripheral(){
  BLEDevice peripheral;
  
  Serial.println("- Discovering peripheral device...");

  do
  {
    BLE.scanForUuid(deviceServiceUuid);
    peripheral = BLE.available();
  } while (!peripheral);
  
  if (peripheral) {
    Serial.println("* Peripheral device found!");
    Serial.print("* Device MAC address: ");
    Serial.println(peripheral.address());
    Serial.print("* Device name: ");
    Serial.println(peripheral.localName());
    Serial.print("* Advertised service UUID: ");
    Serial.println(peripheral.advertisedServiceUuid());
    Serial.println(" ");
    BLE.stopScan();
    controlPeripheral(peripheral);
  }
}

void controlPeripheral(BLEDevice peripheral) {
  Serial.println("- Connecting to peripheral device...");

  if (peripheral.connect()) {
    Serial.println("* Connected to peripheral device!");
    Serial.println(" ");
  } else {
    Serial.println("* Connection to peripheral device failed!");
    Serial.println(" ");
    return;
  }

  Serial.println("- Discovering peripheral device attributes...");
  if (peripheral.discoverAttributes()) {
    Serial.println("* Peripheral device attributes discovered!");
    Serial.println(" ");
  } else {
    Serial.println("* Peripheral device attributes discovery failed!");
    Serial.println(" ");
    peripheral.disconnect();
    return;
  }

  BLECharacteristic co2Characteristic = peripheral.characteristic(deviceServiceCharacteristicUuid);
    
  if (!co2Characteristic) {
    Serial.println("* Peripheral device does not have gesture_type characteristic!");
    peripheral.disconnect();
    return;
  } else if (!co2Characteristic.canWrite()) {
    Serial.println("* Peripheral does not have a writable gesture_type characteristic!");
    peripheral.disconnect();
    return;
  }
  
  while (peripheral.connected()) {
      int co2 = co2Detectection();
      Serial.print("* Writing value to CO2_type characteristic: ");
      Serial.println(co2);
      co2Characteristic.writeValue((byte)co2);
      delay(1000);
      Serial.println("* Writing value to CO2_type characteristic done!");
      Serial.println(" ");
  }
  Serial.println("- Peripheral device disconnected!");
}
  
int co2Detectection() {
  int a;
    if(ccs.available()){
    if(!ccs.readData()){
      Serial.print("CO2: ");
      Serial.println(ccs.geteCO2());
      a=((int)ccs.geteCO2())/20;
    }
    else{
      Serial.println("ERROR!");
      while(1);
    }
  }
  delay(1);
    return a;
}
