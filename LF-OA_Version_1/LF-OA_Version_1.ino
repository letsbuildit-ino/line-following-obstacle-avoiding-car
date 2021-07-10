#define enA 9
#define in1 7
#define in2 6
#define in3 5
#define in4 4
#define enB 8

#define R_S A0
#define L_S A1

const int trigPin = 10;
const int echoPin = 11;

long duration, distance;

void setup(){

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(R_S, INPUT);
  pinMode(L_S, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  analogWrite(enA, 150);
  analogWrite(enB, 150);
  delay(1000);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
  
}
 
void loop(){
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(12, LOW);
  
  
  if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)&&(distance > 25 )){forward();}
  if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)&&(distance > 25 )){turnLeft();}
  if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)&&(distance > 25 )){turnRight();}

  if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)&&(distance < 25 )){stop();}
  if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)&&(distance < 25 )){stop();}
  if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)&&(distance < 25 )){stop();}
  
  if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){stop();}
  
}

void forward(){
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);

  
  while((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)&&(distance > 25 )){
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);
    }
}

void turnLeft(){
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);

  while((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)&&(distance > 25 )){
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   digitalWrite(in3, LOW);
   digitalWrite(in4, LOW);
  }

}
void turnRight(){
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);
    
while((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)&&(distance > 25 )){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  }
}
void stop(){
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);
   
while((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  }
}
