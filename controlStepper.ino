// Define stepper motor connections and steps per revolution:
#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 6400 //set different as different setup in driver

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(115200); // baud rate
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
  int stepsToTake = stepsPerRevolution*angle/360;
  for (int steps = 0; steps < stepsToTake; steps++){
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }
}

String inString = ""; // string to hold time number
String state = ""; // string to hold shit thing you want to do
String fuckup = "";

void loop() {
  int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }
    else 
    {
      if (inChar > -1) state += (char)inChar;
      //Serial.println(state);
    }
    if (state == "Lui" || state == "Tien") 
    {
    Serial.println(state);
    fuckup = state;
    state = "";
    }
    if (inChar == '\n') 
    {
      Serial.print("Value:");
      Serial.println(inString.toInt());
      if (fuckup == "Lui"){ stepperRotate(inString.toInt(),false);}
      if (fuckup == "Tien"){ stepperRotate(inString.toInt(),true);}
      Serial.println("done");
      state = "";
      fuckup = "";
      inString = "";
    }
//  Serial.println(action);
//  Serial.println(themBuLuLQua);
//  Serial.println(func);
}
