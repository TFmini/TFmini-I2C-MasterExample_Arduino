#include <Wire.h> // I2C head file

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // Initiate the Wire library and join the I2C bus as a master or Slave.
  Wire.begin(); 
  Serial.print("Ready to Read TFmini\r\n");
  delay(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte i = 0;
  byte rx_Num = 0;  // the bytes of received by I2C
  byte rx_buf[7] = {0}; // received buffer by I2C
  
  Wire.beginTransmission(7); // Begin a transmission to the I2C Slave device with the given address.
  Wire.write(1); // Reg's Address_H
  Wire.write(2); // Reg's Address_L
  Wire.write(7); // Data Length
  Wire.endTransmission(0);  // Send a START Sign
  
  // Wire.requestFrom（AA,BB）;receive the data form slave.
  // AA: Slave Address ; BB: Data Bytes 
  rx_Num = Wire.requestFrom(0x07, 7); 

  // Wire.available: Retuens the number of bytes available for retrieval with read().
  while( Wire.available())
  {
      rx_buf[i] = Wire.read(); // received one byte
      Serial.print(rx_buf[i], HEX);  // Printf data
      Serial.print(" ");
      i++;
  }
 Serial.print("\r\n");

  delay(5);
}
