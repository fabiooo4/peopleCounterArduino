int enterTrig = 10;
int enterEcho = 9;

int exitTrig = 6;
int exitEcho = 5;

int i=0;


void setup() 
{
  Serial.begin(9600);
  
  pinMode(enterTrig,OUTPUT);
  pinMode(enterEcho,INPUT);
  
  pinMode(exitTrig,OUTPUT);
  pinMode(exitEcho,INPUT);
}

void loop() {
  // Entrance
  digitalWrite(enterTrig,LOW);
  delayMicroseconds(2);
 
  digitalWrite(enterTrig,HIGH);
  delayMicroseconds(10);
 
  digitalWrite(enterTrig,LOW);
 
  int enterDuration = pulseIn(enterEcho,HIGH);
 
  int enterDistance = enterDuration*0.034/2;

  Serial.print("Enter Distance: ");
  Serial.print(enterDistance);
  Serial.print(" cm");

  if (enterDistance < 80) //in
  {
  	i++;
    
    Serial.println();
    Serial.print("People: ");
    Serial.println(i);
    delay(800);

  }
  
  // Exit
  digitalWrite(exitTrig,LOW);
  delayMicroseconds(2);
 
  digitalWrite(exitTrig,HIGH);
  delayMicroseconds(10);
 
  digitalWrite(exitTrig,LOW);
 
  int exitDuration = pulseIn(exitEcho,HIGH);
 
  int exitDistance = exitDuration*0.034/2;

  Serial.print(" / Exit Distance: ");
  Serial.print(exitDistance);
  Serial.println(" cm");
  
  if (exitDistance < 80 && i>0) //in
  {
  	i--;
    
    Serial.print("People: ");
    Serial.println(i);
    delay(800);
  }
}
