const int in1 = 6;
const int in2 = 9;
const int in3 = 10;
const int in4 = 11;
int value = 450;
int V1 = 350;


const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin2 = 4;
const int echoPin2 = 5;
const int trigPin3 = 7;
const int echoPin3 = 8;

// defines variables

long duration1;
int distance1;
long duration2;
int distance2;
long duration3;
int distance3;

void setup() {  
pinMode(trigPin1, OUTPUT); 
pinMode(echoPin1, INPUT); 
pinMode(trigPin2, OUTPUT); 
pinMode(echoPin2, INPUT); 
pinMode(trigPin3, OUTPUT); 
pinMode(echoPin3, INPUT); 

pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);

Serial.begin(9600); 
}
void loop(){
 ultrasonic1();
 ultrasonic2();
 ultrasonic3();
 const int c = 10;
 
 if(distance1 <= c && distance2 >= c && distance3 <= c )
{
  FRWD();
}
if(distance1 >= c && distance2 >= c && distance3 >= c )
{
  FRWD();
}
else if(distance1 < c && distance2 <= c && distance3 > c)
{
  RIGHT();
}
else if(distance1 < c && distance2 > c && distance3 > c)
{
  RIGHT();
}

else if(distance1 > c && distance2 < c && distance3 < c)
{

  LEFT();
}
else if(distance1 > c && distance2 >c && distance3 < c)
{

  LEFT();
}

else if(distance1 < c && distance2 < c && distance3 < c)
{
  RIGHT();
  delay(1500);
}
else if( distance2 <= c ){

  
  if(distance1 < distance3){
 
    RIGHT();
  }
  if(distance1 > distance3){

    LEFT();
  }
}


}


void ultrasonic1(){
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1*0.034/2;
  Serial.print("Distance1 :");
  Serial.println(distance1);
  
}

void ultrasonic2(){
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2*0.034/2;
  Serial.print("Distance2 :");
  Serial.println(distance2);
  
}

void ultrasonic3(){
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = duration3*0.034/2;
  Serial.print("Distance3 :");
  Serial.println(distance3);
  
}
void BACK(){
  analogWrite(in1, LOW);
  analogWrite(in2, value);
  analogWrite(in3, value);
  analogWrite(in4, LOW);
}

void FRWD(){
  analogWrite(in1, value);
  analogWrite(in2, LOW);
  analogWrite(in3, LOW);
  analogWrite(in4, value);
}

void RIGHT(){
  analogWrite(in1, LOW);
  analogWrite(in2, V1);
  analogWrite(in3, LOW);
  analogWrite(in4, V1);
}

void LEFT(){
  analogWrite(in1, V1);
  analogWrite(in2, LOW);
  analogWrite(in3, V1);
  analogWrite(in4, LOW);
}
void STOP(){
  analogWrite(in1, LOW);
  analogWrite(in2, LOW);
  analogWrite(in3, LOW);
  analogWrite(in4, LOW);
}


