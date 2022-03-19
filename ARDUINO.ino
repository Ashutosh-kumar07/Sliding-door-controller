const int in1 = 4;
const int in2 = 5;
const int pirin = 6;
const int ledout = 7;
const int ledin = 8;

void setup() 
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(pirin, INPUT);
  pinMode(ledout, OUTPUT);
  pinMode(ledin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
     int countopen=0,countclose=0;
     while(1)
     {
     if(digitalRead(pirin)==HIGH)
     {
        if(digitalRead(ledin)==LOW)
        {
          open_door();
          countopen=countopen+1;
       }
     }
     if (digitalRead(pirin)==LOW)
     {
        if(digitalRead(ledin)==HIGH)
        {
          close_door();
          countclose=countclose+1;
        }
     }  
     Serial.print(countopen);
     Serial.print(" - Open Count & , ");
     Serial.print(countclose);
     Serial.print(" - Close Count");
     Serial.println();
     delay(1000);  
     }                  
}

void close_door()
{
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(ledout,HIGH);
  for (int i=0;i<=9;i++)
  {
     delay(100);
     if (digitalRead(pirin)==HIGH)
     {
        if(digitalRead(ledin)==HIGH)
        {
          open_interrupt_door(i);
          return;
        }
     }
  }
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(ledout,LOW);
}

void open_door()
{
   digitalWrite(in1,LOW);
   digitalWrite(in2,HIGH);
   digitalWrite(ledout,HIGH);
   delay(1000);
   digitalWrite(in1,LOW);
   digitalWrite(in2,LOW);
   digitalWrite(ledout,HIGH);
   return;
}

void open_interrupt_door(int x)
{
   digitalWrite(in1,LOW);
   digitalWrite(in2,HIGH);
   digitalWrite(ledout,HIGH);
   for (int y=0;y<x;y++)
   {
      delay(100);
   }
   digitalWrite(in1,LOW);
   digitalWrite(in2,LOW);
   digitalWrite(ledout,HIGH);
   return;
}
