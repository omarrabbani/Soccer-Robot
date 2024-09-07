const int in1 = 5; // PWM pin
const int in2 = 6; // PWM pin
const int in3 = 9; // PWM pin
const int in4 = 10; // PWM pin

int SPEED = 200; // Initial speed
const int SPEED_INCREMENT = 5; // Amount to increase/decrease speed
const int MAX_SPEED = 255; // Maximum PWM value
const int MIN_SPEED = 0;   // Minimum PWM value

int input;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    input = Serial.read();

    if (input == 'S' || input == 's') {
      Stop();
    } 
    else if (input == 'F' || input == 'f') {
      forward();
    } 
    else if (input == 'B' || input == 'b') {
      back();
    } 
    else if (input == 'R' || input == 'r') {
      right();
    } 
    else if (input == 'L' || input == 'l') {
      left();
    } 
    else if (input == 'D' || input == 'd') {
      rightFwd();
    } 
    else if (input == 'G' || input == 'g') {
      leftFwd();
    } 
    else if (input == 'Z' || input == 'z') {
      leftBack();
    } 
    else if (input == 'X' || input == 'x') {
      rightBack();
    } 
    else if (input == '+') {
      increaseSpeed();
    } 
    else if (input == '-') {
      decreaseSpeed();
    } 
    else {
      Serial.println("Incorrect input entered.");
    }
  }
  delay(100);
}

// Function to increase the speed by SPEED_INCREMENT, capped at MAX_SPEED
void increaseSpeed() {
  SPEED += SPEED_INCREMENT;
  if (SPEED > MAX_SPEED) {
    SPEED = MAX_SPEED;
  }
  Serial.print("Speed increased to: ");
  Serial.println(SPEED);
}

// Function to decrease the speed by SPEED_INCREMENT, capped at MIN_SPEED
void decreaseSpeed() {
  SPEED -= SPEED_INCREMENT;
  if (SPEED < MIN_SPEED) {
    SPEED = MIN_SPEED;
  }
  Serial.print("Speed decreased to: ");
  Serial.println(SPEED);
}

void Stop() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}

void left() {
  analogWrite(in1, SPEED);
  analogWrite(in2, 0);
  analogWrite(in3, SPEED);
  analogWrite(in4, 0);
}

void right() {
  analogWrite(in1, 0);
  analogWrite(in2, SPEED);
  analogWrite(in3, 0);
  analogWrite(in4, SPEED);
}

void forward() {
  analogWrite(in1, 0);
  analogWrite(in2, SPEED);
  analogWrite(in3, SPEED);
  analogWrite(in4, 0);
}

void back() {
  analogWrite(in1, SPEED);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, SPEED);
}

void leftFwd() {
  analogWrite(in1, SPEED / 2);
  analogWrite(in2, 0);
  analogWrite(in3, SPEED);
  analogWrite(in4, 0);
}

void rightFwd() {
  analogWrite(in1, 0);
  analogWrite(in2, SPEED);
  analogWrite(in3, SPEED / 2);
  analogWrite(in4, 0);
}

void leftBack() {
  analogWrite(in1, SPEED / 2);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, SPEED);
}

void rightBack() {
  analogWrite(in1, SPEED);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, SPEED / 2);
}
