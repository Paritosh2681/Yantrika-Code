// Sensor 1 Pins
const int trigPin1 = 2;
const int echoPin1 = 3;

// Sensor 2 Pins
const int trigPin2 = 4;
const int echoPin2 = 5;

// Sensor 3 Pins
const int trigPin3 = 6;
const int echoPin3 = 7;

long duration;
int distance1, distance2, distance3;

void setup() {
  Serial.begin(9600);

  // Sensor 1
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  // Sensor 2
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  // Sensor 3
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
}

void loop() {
  // Sensor 1
  distance1 = getDistance(trigPin1, echoPin1);
  // Sensor 2
  distance2 = getDistance(trigPin2, echoPin2);
  // Sensor 3
  distance3 = getDistance(trigPin3, echoPin3);

  // Print distances
  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.print(" cm\t");

  Serial.print("Distance 2: ");
  Serial.print(distance2);
  Serial.print(" cm\t");

  Serial.print("Distance 3: ");
  Serial.print(distance3);
  Serial.println(" cm");

  delay(500); // Wait before next reading
}

// Function to measure distance
int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  return distance;
}
