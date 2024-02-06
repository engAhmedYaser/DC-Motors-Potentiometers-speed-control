// C++ code
//
const int buttonL = 2;int valueL;
const int buttonR = 3;int valueR;
const int pot1 = A0;int reading1;
const int pot2 = A1;int reading2;
const int motorR = 6; char x;int value1;
int value2 ;
const int motorL = 11;
void setup()
{
  pinMode(motorR, OUTPUT);
 pinMode(motorL, OUTPUT);
  pinMode( buttonL,INPUT);
    pinMode( buttonR,INPUT);
  Serial.begin(9600);
}

void loop()
{
  valueL = digitalRead(buttonL);
    valueR = digitalRead(buttonR);
  reading1= analogRead(pot1);
  reading2=analogRead(pot2);
  if(Serial.available()){ x = Serial.read();}
  if( valueL == HIGH ){
    if ( x == 's'|| x == 'S'){
      digitalWrite( motorL, LOW); }
    else{analogWrite( motorL , map(reading1,0,1023,255,0));}
  }
  else if ( valueL == LOW ){ 
      if (x == 'l'|| x == 'L'){
      analogWrite( motorL , map(reading1,0,1023,255,0));}
    else if ( x == 's'|| x == 'S'){
      digitalWrite( motorL, LOW);}
    else{digitalWrite( motorL, LOW);}
  }
  if( valueR == HIGH ){
    if ( x == 's'|| x == 'S'){
      digitalWrite( motorR, LOW); }
    else{analogWrite( motorR , map(reading2,0,1023,255,0));}
  }
  else if ( valueR == LOW ){ 
      if (x == 'r'|| x == 'R'){
      analogWrite( motorR , map(reading2,0,1023,255,0));}
    else if ( x == 's'|| x == 'S'){
      digitalWrite( motorR, LOW);}
    else{digitalWrite( motorR, LOW);}
  }
}    