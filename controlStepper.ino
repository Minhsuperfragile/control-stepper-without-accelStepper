/* Example sketch to control a stepper motor with TB6600 stepper motor driver and Arduino without a library: number of revolutions, speed and direction. More info: https://www.makerguides.com */

// Define stepper motor connections and steps per revolution:
#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 1600
// angel = 360/stepsPerRevolution
void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600);
}

void stepperRotate(int angle, bool clockwise){
  if (clockwise){
    digitalWrite(dirPin, HIGH);
    Serial.println("Clockwise");
  }
  if(!clockwise){
    digitalWrite(dirPin, LOW);
    Serial.println("Counter Clockwise");
  }
  for (int steps = 0; steps < (360/angle); steps++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }
  Serial.println(angle);
}

String themBuLuLQua = ""; // string to hold time number
String func = ""; // string to hold shit thing you want to do

void loop() {
  int action = Serial.read();
  if (isDigit(action)){
    themBuLuLQua += (char)action;
  }
  else{
    if (action > -1){ func += (char)action; }
  }
  if (action == "\n"){
    if (func == "tien"){
      stepperRotate(themBuLuLQua.toInt(),true);
    }
    if (func == "lui"){
      stepperRotate(themBuLuLQua.toInt(),false);
    }

  }
//  Serial.println(action);
//  Serial.println(themBuLuLQua);
//  Serial.println(func);
}
