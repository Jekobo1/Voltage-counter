int pinA = 9;
int pinB = 8;
int pinC = 7;
int pinD = 6;
int pinE = 5;
int pinF = 4;
int pinG = 3;
int pinDP = 2;
int D1 = 10;
int D2 = 11;
int D3 = 12;
int D4 = 13;
int delayT = 5;
void choose_digit(char num){
switch(num){
  default:
  digitalWrite(pinA, LOW);
digitalWrite(pinB, LOW);
digitalWrite(pinC, LOW);
digitalWrite(pinD, LOW);
digitalWrite(pinE, LOW);
digitalWrite(pinF, LOW);
digitalWrite(pinG, HIGH);
break;
case 1:
digitalWrite(pinA, HIGH);
digitalWrite(pinB, LOW);
digitalWrite(pinC, LOW);
digitalWrite(pinD, HIGH);
digitalWrite(pinE, HIGH);
digitalWrite(pinF, HIGH);
digitalWrite(pinG, HIGH);
break;
case 2:
digitalWrite(pinA, LOW);
digitalWrite(pinB, LOW);
digitalWrite(pinC, HIGH);
digitalWrite(pinD, LOW);
digitalWrite(pinE, LOW);
digitalWrite(pinF, HIGH);
digitalWrite(pinG, LOW);
break;
case 3:
digitalWrite(pinA, LOW);
digitalWrite(pinB, LOW);
digitalWrite(pinC, LOW);
digitalWrite(pinD, LOW);
digitalWrite(pinE, HIGH);
digitalWrite(pinF, HIGH);
digitalWrite(pinG, LOW);
break;
case 4:
digitalWrite(pinA, HIGH);
digitalWrite(pinB, LOW);
digitalWrite(pinC, LOW);
digitalWrite(pinD, HIGH);
digitalWrite(pinE, HIGH);
digitalWrite(pinF, LOW);
digitalWrite(pinG, LOW);
break;
case 5:
digitalWrite(pinA, LOW);
digitalWrite(pinB, HIGH);
digitalWrite(pinC, LOW);
digitalWrite(pinD, LOW);
digitalWrite(pinE, HIGH);
digitalWrite(pinF, LOW);
digitalWrite(pinG, LOW);
break;
case 6:
digitalWrite(pinA, LOW);
digitalWrite(pinB, HIGH);
digitalWrite(pinC, LOW);
digitalWrite(pinD, LOW);
digitalWrite(pinE, LOW);
digitalWrite(pinF, LOW);
digitalWrite(pinG, LOW);
break;
case 7:
digitalWrite(pinA, LOW);
digitalWrite(pinB, LOW);
digitalWrite(pinC, LOW);
digitalWrite(pinD, HIGH);
digitalWrite(pinE, HIGH);
digitalWrite(pinF, HIGH);
digitalWrite(pinG, HIGH);
break;
case 8:
digitalWrite(pinA, LOW);
digitalWrite(pinB, LOW);
digitalWrite(pinC, LOW);
digitalWrite(pinD, LOW);
digitalWrite(pinE, LOW);
digitalWrite(pinF, LOW);
digitalWrite(pinG, LOW);
break;
case 9:
digitalWrite(pinA, LOW);
digitalWrite(pinB, LOW);
digitalWrite(pinC, LOW);
digitalWrite(pinD, LOW);
digitalWrite(pinE, HIGH);
digitalWrite(pinF, LOW);
digitalWrite(pinG, LOW);
break;

}
}

void pick_digit(int digit){
    digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  switch(digit){
    case 1:
    digitalWrite(D1, HIGH);
    break;
    case 2:
    digitalWrite(D2, HIGH);
    break;
    case 3:
    digitalWrite(D3, HIGH);
    break;
    default:
    digitalWrite(D4, HIGH);
    break;
  }
}
void seven_segment(int number){
  unsigned char thousands = int(number / 1000);
  unsigned char hundreds = int((number/100)%10);
  unsigned char tens = int((number/10)%10);
  unsigned char ones = int(number%10);
  choose_digit(thousands);
  pick_digit(1);
  delay(delayT);
  
  choose_digit(hundreds);
  pick_digit(2);
  delay(delayT);

  choose_digit(tens);
  pick_digit(3);
  delay(delayT);

  choose_digit(ones);
  pick_digit(4);
  delay(delayT);
}
void setup() {
  // put your setup code here, to run once:
pinMode(pinA, OUTPUT);
pinMode(pinB, OUTPUT);
pinMode(pinC, OUTPUT);
pinMode(pinD, OUTPUT);
pinMode(pinE, OUTPUT);
pinMode(pinF, OUTPUT);
pinMode(pinG, OUTPUT);
pinMode(D1, OUTPUT);
pinMode(D2, OUTPUT);
pinMode(D3, OUTPUT);
pinMode(D4, OUTPUT);
Serial.begin(9600);
}

void loop() {
  int sensor_value = analogRead(A0);
  Serial.println(sensor_value);
  
seven_segment(sensor_value);
  //delay(200);
  



}
