int  L1=8;
int L2=9;
int R1=12;
int R2=13;           


void setup() 
  // initialize serial communication at 9600 bits per second:
  {
  Serial.begin(9600);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  //pinMode(10,OUTPUT);
  Serial.println("   MAIN MENU    ");
  Serial.println("1-FORWARD");
  Serial.println("2-BACKWARD");
  Serial.println("3-LEFT");
  Serial.println("4-RIGHT");
  Serial.println("5-STOP");
}
int val=0;
void loop() {
if(Serial.available()>0)
{
  val=Serial.parseInt();
  Serial.println(val);
 // digitalWrite(10,HIGH);
  switch(val)
  {
 //FORWARD
    case 2:
      digitalWrite(L1,HIGH);
      digitalWrite(L2,LOW);
      digitalWrite(R1,HIGH);
      digitalWrite(R2,LOW);
      break;
 //BACKWARD
    case 1:
      digitalWrite(L1,LOW);
      digitalWrite(L2,HIGH);
      digitalWrite(R1,LOW);
      digitalWrite(R2,HIGH);
      break;
 //LEFT
    case 4:
      digitalWrite(L1,HIGH);
      digitalWrite(L2,LOW);
      digitalWrite(R1,LOW);
      digitalWrite(R2,HIGH);
      break;
 //RIGHT
    case 3:
      digitalWrite(L1,LOW);
      digitalWrite(L2,HIGH);
      digitalWrite(R1,HIGH);
      digitalWrite(R2,LOW);
      break;
 //STOP
     case 5:
      digitalWrite(L1,LOW);
      digitalWrite(L2,LOW);
      digitalWrite(R1,LOW);
      digitalWrite(R2,LOW);
      break;
  }}
   

}
