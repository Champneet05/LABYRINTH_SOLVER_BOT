// IR sensor connected to digital pin 2
int irSensorPin = 2; 
int irSensorValue = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  // Set the IR sensor pin as input
  pinMode(irSensorPin, INPUT); 
}

void loop() {
  // Read the IR sensor value
  irSensorValue = digitalRead(irSensorPin); 

  if (irSensorValue == HIGH) {
    // Print message if object is detected
    Serial.println("Object Detected"); 
  } else {
    // Print message if no object is detected
    Serial.println("No Object");
  }

  // Delay to avoid spamming the Serial Monitor
  delay(500); 
}
