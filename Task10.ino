#include <Wire.h>

const int MPU = 0x68;               // MPU6050 I2C address
float GyroZ;
float yaw;
float elapsedTime, currentTime, previousTime;
float zGyroOffset = 0;              // Variable to store the gyro offset

void setup() {
  Serial.begin(19200);
  Wire.begin();

  // Wake up MPU6050 (default state is sleeping)
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);  // Register 0x6B: Power management 1
  Wire.write(0x00);  // Wake up the MPU6050
  Wire.endTransmission(true);

  calibrateGyro();
  delay(20);
}

void loop() {
  previousTime = currentTime;
  currentTime = millis();
  elapsedTime = (currentTime - previousTime) / 1000.0;  // Correct division to float

  // Read the Z-axis gyroscope data directly
  Wire.beginTransmission(MPU);
  Wire.write(0x43);  // Register 0x43: Gyroscope Z-axis data high byte
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 2, true);  // Request 2 bytes of data

  // Read raw gyroscope data and combine high and low bytes
  int16_t zGyroRaw = Wire.read() << 8 | Wire.read();
  GyroZ = (zGyroRaw / 131.0) - zGyroOffset;

  // Integrate to calculate yaw angle
  yaw += GyroZ * elapsedTime;

  Serial.print("Yaw: ");
  Serial.println(yaw);

  delay(100);  // Added delay to slow down the loop
}

void calibrateGyro() {
  const int samples = 1000;
  long zGyroSum = 0;

  Serial.println("Calibrating Gyroscope...");

  for (int i = 0; i < samples; i++) {
    Wire.beginTransmission(MPU);
    Wire.write(0x43);  // Register 0x43: Gyroscope Z-axis data high byte
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 2, true);  // Request 2 bytes of data

    // Read raw gyroscope data and combine high and low bytes
    int16_t zGyroRaw = Wire.read() << 8 | Wire.read();
    zGyroSum += zGyroRaw;
    delay(2);  // Small delay for stability
  }

  // Calculate the average offset for the Z-axis gyroscope
  zGyroOffset = (zGyroSum / (samples * 131.0));

  Serial.print("Z Gyroscope Offset: ");
  Serial.println(zGyroOffset);
}

