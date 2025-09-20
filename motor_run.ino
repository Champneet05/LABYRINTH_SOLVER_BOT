// Define pins for the Left Motors
#define in1 10
#define in2 9

// Define pins for the Right Motors
#define in3 5
#define in4 3

// Set the motor speed
int speed = 70;

// setup() function runs once when you press reset or power the board
void setup() {
  // Initialize motor pins as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Start serial communication for debugging
  Serial.begin(9600);
}

// Function to move the robot forward
void Forward() {
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
}

// Function to turn the robot right
void Right() {
  analogWrite(in1, speed);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, speed);
}

// Function to turn the robot left
void Left() {
  analogWrite(in1, 0);
  analogWrite(in2, speed);
  analogWrite(in3, speed);
  analogWrite(in4, 0);
}

// Function to stop the robot
void Stop() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}

// loop() function runs over and over again forever
void loop() {
  // Test Forward
  Serial.println("Moving Forward");
  Forward();
  delay(2000); // run forward for 2 seconds

  // Test Stop
  Serial.println("Stopping");
  Stop();
  delay(1000); // stop for 1 second

  // Test Right
  Serial.println("Turning Right");
  Right();
  delay(1000); // turn right for 1 second

  // Test Stop
  Serial.println("Stopping");
  Stop();
  delay(1000); // stop for 1 second

  // Test Left
  Serial.println("Turning Left");
  Left();
  delay(1000); // turn left for 1 second
  
  // Test Stop
  Serial.println("Stopping");
  Stop();
  delay(1000); // stop for 1 second
}

