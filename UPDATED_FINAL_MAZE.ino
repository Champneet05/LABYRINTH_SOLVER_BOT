int const IN1 = 5;
int const IN2 = 3;
int const IN3 = 9;
int const IN4 = 10;

int const SL = 12;
int const SM = 7;
int const SR = 2;

void setup() {
  // put your setup code here, to run once:
  // Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(SL, INPUT);
  pinMode(SM, INPUT);
  pinMode(SR, INPUT);
}

void moveLeft() {
  // thoda sa  piche aaa
  analogWrite(IN1, 60);
  analogWrite(IN2, 0);
  analogWrite(IN3, 60);
  analogWrite(IN4, 0);
}

void moveRight() {
  // thoda sa  piche aaa
  analogWrite(IN1, 0);
  analogWrite(IN2, 58);
  analogWrite(IN3, 0);
  analogWrite(IN4, 58);
}

void moveForward() {
  analogWrite(IN1, 55);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 55);
}

void loop() {
  // put your main code here, to run repeatedly:
  int l = digitalRead(SL);
  int m = digitalRead(SM);
  int r = digitalRead(SR);

  // straight
  if (l == 0 && m == 1 && r == 0) {
    moveForward();
    delay(10);
  }

  //left
  if (l == 1 && m == 0 && r == 0) {
    moveLeft();  // while moving forward
    delay(300);  //900 // 750 //650 // 450 - 350
    moveForward();
    delay(50);  //400
  }
  //right
  if ((l == 0 && m == 0 && r == 1)) {

    moveRight();  // while moving forward
    delay(600);   // 1ms original
  }

  if (l == 1 && m == 1 && r == 0) {

    moveLeft();
    delay(300);  // 900
    moveForward();
    delay(50);
    // delayMicroseconds(50);
  }

  if (l == 1 && m == 0 && r == 1) {
    moveLeft();
    delay(300);  // 900 // 550
    moveForward();
    delay(50);  //500
  }

  if (l == 0 && m == 1 && r == 1) {
    moveForward();
    delay(150);
    l = digitalRead(SL);
    m = digitalRead(SM);
    r = digitalRead(SR);
    if (l == 0 && m == 0 && r == 0) {
      moveRight();  // while moving forward
      delay(1500);   // 1ms original
    }
  }

  if (l == 1 && m == 1 && r == 1) {
    moveLeft();
    delay(50);
    //  moveForward();
    //  delay(40); // time
    //  stop();

    //  if (l == 1 && m == 1 && r == 1)
    //     {
    //       // Serial.println("ËND OF MAZE");
    //       stop();
    //       blink();
    //     }
    //  else
    //     {
    //     //  Serial.println("FOUR WAY INTERSECTION");
    //      moveLeft();
    //     }
  }


  if (l == 0 && m == 0 && r == 0) {
    // moveForward();
    // delay(150);
    // int i = 1; doesnt work
    // while(i == 1){
    //   moveForward();
    //   delay(1);
    //   i++;
    // }
    // moveForward();
    // delay(2000);
    moveLeft();
    delay(100);
  }
}