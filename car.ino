1;       // 왼쪽 모터 제어선 IN4

int motor_s = 160;              // 최대 속도(0~255)의 60% 
int val = 0;
const int RPin = A3;
void setup() {  
  EduServo.attach(2);                       // 서보모터 PWM 디지털입출력 2번핀 연결
  
  pinMode(echoPin, INPUT);                  // echoPin 입력
  pinMode(trigPin, OUTPUT);                 // trigPin 출력
  
  pinMode(RightMotor_E_pin, OUTPUT);        // 출력모드로 설정
  pinMode(RightMotor_1_pin, OUTPUT);
  pinMode(RightMotor_2_pin, OUTPUT);
  pinMode(LeftMotor_3_pin, OUTPUT);
  pinMode(LeftMotor_4_pin, OUTPUT);
  pinMode(LeftMotor_E_pin, OUTPUT);
  pinMode(RPin, OUTPUT);
  Serial.begin(9600);                       // PC와의 시리얼 통신 9600bps로 설정
  Serial.println("Welcome Eduino!");
}

void loop() { 

 

  Ultra_d = Ultrasonic();
  Serial.println(Ultra_d);
  motor_role(HIGH, HIGH, motor_s);  // 직진

 
  if(Ultra_d < 250) {
   
    if (Ultra_d < 150) {
      digitalWrite(RPin, HIGH);
      delay(1000);
      digitalWrite(RPin, LOW);
      delay(1000);

   
       
      Serial.println("150 이하.");
      motor_role(LOW, LOW, motor_s); // 후진
      delay(1000);
     
      motor_role(HIGH, HIGH, 0);  // 정지
      
      delay(200);
    }
    else {
      
      motor_role(HIGH, HIGH, 0);  // 정지
     
      delay(200);
      Serial.println("150 이상.");
      val =  Servo_con();
      if (val == 0) {
        Serial.println("우회전.");
       
        motor_role(HIGH, HIGH, 0);  // 정지
       
        delay(500);
        motor_role(LOW, LOW, motor_s);  // 후진
        delay(500);
        motor_role(LOW, HIGH, motor_s);  // 우회전
        delay(800);
      }
      else if (val == 1) {
        Serial.println("좌회전.");
        motor_role(HIGH, HIGH, 0);
        
        delay(500);
        motor_role(LOW, LOW, motor_s);  // 후진
        delay(500);
        motor_role(HIGH, LOW, motor_s);  // 좌회전
        delay(800);
      }
    }
  }
}

void motor_role(int R_motor, int L_motor, int Speed){
   digitalWrite(RightMotor_1_pin, R_motor);
   digitalWrite(RightMotor_2_pin, !R_motor);
   digitalWrite(LeftMotor_3_pin, L_motor);
   digitalWrite(LeftMotor_4_pin, !L_motor);
   
   analogWrite(RightMotor_E_pin, Speed);  // 우측 모터 속도값
   analogWrite(LeftMotor_E_pin, Speed);   // 좌측 모터 속도값  
}

int Ultrasonic(){
  long duration, distance;
  digitalWrite(trigPin, HIGH);      // trigPin에서 초음파 발생(echoPin도 HIGH)        
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);   // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  distance = ((float)(340 * duration) / 1000) / 2; 

  //Serial.print("DIstance:");        // 물체와 초음파 센서간 거리를 표시.        
  //Serial.println(distance);

  return distance;
}

int Servo_con(){
  EduServo.write(30);
  int Ult_30 = Ultrasonic();
  delay(1000);
  EduServo.write(150);
  int Ult_150 = Ultrasonic();
  delay(1000);

  if(Ult_30 > Ult_150){
     val = 1;
  }
  else{
     val = 0;
  }
  EduServo.write(90);
   
  return val;
}
                                                                                                                                                                                                                                                                                                                                                                ܇�l���;  dAj~   �                                      ,��l���;  dAj~   �                                      \��l���;  dAj~   �                                      ؔ�l���;  dAj~   �                      N             �e�l���~�� ��j~   �        ��                            \^�l���� P��~   �        d                             �^�l���x� ���~   �        �                             �^�l���~� `��~   �        �     o.write(150);
  int Ult_150 = Ultrasonic();
  delay(1000);

  if(Ult_30 > Ult_150){
     val = 1;
  }
  else{
     val = 0;
  }
  EduServo.write(90);
   
  return val;
}
