// Right Side Motor
#define stpPin1 2
#define dirPin1 3
#define stpPin3 10
#define dirPin3 11

// Left Side Motor
#define stpPin2 8
#define dirPin2 9
#define stpPin4 13
#define dirPin4 12

// Enable Pin
#define enPin 5

// Bt
#define bt 6

#define stepsPerRevolution 200
void setup() {
  Serial.begin(9600);

  pinMode(enPin , OUTPUT);
  
  // Right Side
  pinMode(stpPin1 , OUTPUT);
  pinMode(dirPin1 , OUTPUT);
  pinMode(stpPin3 , OUTPUT);
  pinMode(dirPin3 , OUTPUT);

  // Left Side
  pinMode(stpPin2 , OUTPUT);
  pinMode(dirPin2 , OUTPUT);
  pinMode(stpPin4 , OUTPUT);
  pinMode(dirPin4 , OUTPUT);

  // Right Side
  digitalWrite(dirPin1 , HIGH);
  digitalWrite(dirPin3 , HIGH);
  
  //Left Side
  digitalWrite(dirPin2 , LOW);
  digitalWrite(dirPin2 , LOW);

  digitalWrite(enPin , HIGH);
}
void loop() {
  if(Serial.available() > 0)
  {
    char inChar = Serial.read();
    digitalWrite(enPin, LOW);
    if(inChar == 'o')
    {
      Serial.println("Out!");
      for(int x = 0; x < stepsPerRevolution; x++)
      {
        digitalWrite(stpPin1 , HIGH);
        digitalWrite(stpPin3 , HIGH);
        digitalWrite(stpPin2 , LOW);
        digitalWrite(stpPin4 , LOW);
        delayMicroseconds(1000);
    
        digitalWrite(stpPin1 , LOW);
        digitalWrite(stpPin3 , LOW);
        digitalWrite(stpPin2 , HIGH);
        digitalWrite(stpPin4 ,HIGH);
        delayMicroseconds(1000);
      }
    }
  
  }

  digitalWrite(enPin , HIGH);
  

}
