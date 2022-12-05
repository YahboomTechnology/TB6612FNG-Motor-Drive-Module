/****************************************************************************8
   Program: TB6612FNG test program
   The test motor can be used when the program is directly burned to the balance car.
*/
int STBY = 8; //Enable Pin
  
//Motor A
int PWMA = 9; //Left motor PWM output control pin  
int AIN1 = 7; //Left motor positive electrode
int AIN2 = 6; //Left motor negative electrode  
  
//Motor B  
int PWMB = 10; //Right motor PWM output control pin 
int BIN1 = 13; //Right motor positive electrode
int BIN2 = 12; //Right motor negative electrode 
  
void setup(){  
  pinMode(STBY, OUTPUT);  
  
  pinMode(PWMA, OUTPUT);  
  pinMode(AIN1, OUTPUT);  
  pinMode(AIN2, OUTPUT);  
  
  pinMode(PWMB, OUTPUT);  
  pinMode(BIN1, OUTPUT);  
  pinMode(BIN2, OUTPUT);  
}  

void runset(int motor, int speed, int direction){  
  
  digitalWrite(STBY, HIGH);
  
  boolean Pin1 = LOW;  
  boolean Pin2 = HIGH;  
  
  if(direction == 1){  
    Pin1 = HIGH;  
    Pin2 = LOW;  
  }  
  
  if(motor == 1){  
    digitalWrite(AIN1, Pin1);  
    digitalWrite(AIN2, Pin2);  
    analogWrite(PWMA, speed);  
  }else{  
    digitalWrite(BIN1, Pin1);  
    digitalWrite(BIN2, Pin2);  
    analogWrite(PWMB, speed);  
  }  
}  
  
void loop(){  
  runset(1, 255, 1);  
  runset(2, 255, 1);   
  
  delay(1000);
  stop(); 
  delay(250); 
  
  runset(1, 128, 0); 
  runset(2, 128, 0);  
  
  delay(1000);  
  stop();  
  delay(250);  
}  
   
void stop(){  
  digitalWrite(STBY, LOW);   
}  
