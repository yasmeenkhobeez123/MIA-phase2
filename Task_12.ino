class PID {
  private:
    float kp, ki, kd;
    float integral, lastError;
    unsigned long lastTime;

  public:
    // Constructor to initialize PID parameters
    PID(float p, float i, float d) {
      kp = p;
      ki = i;
      kd = d;
      integral = 0;
      lastError = 0;
      lastTime = millis();
    }

    // PID compute method to calculate output
    float compute(float setpoint, float currentSpeed) {
      unsigned long currentTime = millis();
      float dt = (currentTime - lastTime) / 1000.0;  

      
      if (dt == 0) {
        dt = 0.001;  // Minimum delta time to prevent division by zero
      }

      // PID calculation
      float error = setpoint - currentSpeed;
      integral += error * dt;
      float derivative = (error - lastError) / dt;

      float output = kp * error + ki * integral + kd * derivative;

      // Update lastError and lastTime
      lastError = error;
      lastTime = currentTime;

      return output;
    }
};

// Soft start filter class for exponential smoothing
class SoftStartFilter {
  private:
    float alpha;
    float smoothedValue;

  public:
    // Constructor to set alpha (smoothing factor)
    SoftStartFilter(float smoothingFactor) {
      alpha = smoothingFactor;
      smoothedValue = 0;
    }

    // Compute the smoothed value
    float applyFilter(float newValue) {
      smoothedValue = alpha * newValue + (1 - alpha) * smoothedValue;
      return smoothedValue;
    }
};

const int motorPin = 9;
const int speedSensorPin = A0;

PID motorPID(1.0, 0.1, 0.05);  // Initialize PID with gains
SoftStartFilter softStart(0.1); // Initialize soft start filter

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float setpoint = 200;  // Desired speed
  float currentSpeed = analogRead(speedSensorPin);  
  

  currentSpeed = map(currentSpeed, 0, 1023, 0, 255);  

  // Calculate PID output
  float pidOutput = motorPID.compute(setpoint, currentSpeed);

  // Apply exponential smoothing
  float smoothedOutput = softStart.applyFilter(pidOutput);

  // Constrain smoothed output and write to motor
  int motorPWM = constrain(smoothedOutput, 0, 255);
  analogWrite(motorPin, motorPWM);

 
  Serial.print("Speed: ");
  Serial.print(currentSpeed);
  Serial.print(" | Smoothed Output: ");
  Serial.println(smoothedOutput);

  delay(10); 
}

