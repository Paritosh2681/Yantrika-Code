// Motor A pins
const int IN1 = 8;
const int IN2 = 9;
const int ENA = 10; // PWM

// Motor B pins
const int IN3 = 7;
const int IN4 = 6;
const int ENB = 5;  // PWM

void setup() {
  // Set motor pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.println("Both motors forward");
  motorAForward(255);
  motorBForward(255);
  delay(3000);

  Serial.println("Both motors stop");
  motorStop();
  delay(1000);

  Serial.println("Both motors backward");
  motorABackward(255);
  motorBBackward(255);
  delay(3000);

  Serial.println("Both motors stop");
  motorStop();
  delay(1000);
}

// Motor A control functions
void motorAForward(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speed);
}

void motorABackward(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speed);
}

// Motor B control functions
void motorBForward(int speed) {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, speed);
}

void motorBBackward(int speed) {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, speed);
}

// Stop both motors
void motorStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

