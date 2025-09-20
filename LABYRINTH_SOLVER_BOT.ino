// Define pins for the Left Motors
#define in1 10
#define in2 9

// Define pins for the Right Motors
#define in3 5
#define in4 3

// Define pins for the IR Sensors
#define s1 12 // Left Sensor
#define s2 7  // Middle Sensor
#define s3 2  // Right Sensor

// Set the motor speed
int speed = 65;

// setup() function runs once when you press reset or power the board
void setup() {
  // Initialize sensor pins as inputs
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);

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
  // Read the state of the IR sensors
  int IR1 = digitalRead(s1);
  int IR2 = digitalRead(s2);
  int IR3 = digitalRead(s3);

  // --- LOGIC FOR SINGLE SENSOR DETECTION ---

  // If only the middle sensor detects the line, move forward
  if (IR1 == LOW && IR2 == HIGH && IR3 == LOW) { // STRAIGHT LINE
    Forward();
    delay(100);
  }
  // If only the left sensor detects the line, turn left
  else if (IR1 == HIGH && IR2 == LOW && IR3 == LOW) { // LEFT TURN
    Left();
    delay(50);
  }
  // If only the right sensor detects the line, turn right
  else if (IR1 == LOW && IR2 == LOW && IR3 == HIGH) { // RIGHT TURN
    Right();
    delay(30);
  }

  // --- LOGIC FOR COMBINATION OF SENSORS ---

  // If left and middle sensors detect a line (T-intersection to the left)
  else if (IR1 == HIGH && IR2 == HIGH && IR3 == LOW) { // T-INTERSECTION LEFT
    Left(); // As Left is possible
    delay(50);
    Forward();
    delay(20);
  }
  // If middle and right sensors detect a line (T-intersection to the right)
  else if (IR1 == LOW && IR2 == HIGH && IR3 == HIGH) { // T-INTERSECTION RIGHT
    Forward();
    delay(20);
  }
  // If left and right sensors detect a line (line is deviated)
  else if (IR1 == HIGH && IR2 == LOW && IR3 == HIGH) { // MIDDLE DEVIATED
    Left();
    delay(20);
  }
  // If all three sensors detect a line (T-junction or intersection)
  else if (IR1 == HIGH && IR2 == HIGH && IR3 == HIGH) { // T-JUNCTION
    Left();
    delay(10);
  }
  // If no sensors detect a line (dead end)
  else if (IR1 == LOW && IR2 == LOW && IR3 == LOW) { // DEAD END
    Forward();
    delay(20);
    Left(); // Turn left as no other direction is possible
    delay(30);
  }
}
