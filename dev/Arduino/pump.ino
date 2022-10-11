int IN1 = 2; //IN1을 2번핀으로
int IN2 = 3; //IN2을 3번핀으로
int button = 4; //버튼을 4번 핀으로

 void setup(){
  pinMode(IN1,OUTPUT); //IN1을 OUTPUT으로 
  pinMode(IN2,OUTPUT); //IN2을 OUTPUT으로 
  pinMode(button, INPUT); //BUTTON을 INPUT으로
 }
 void loop(){
  if(digitalRead(button)==HIGH) //만약 버튼의 값이 HIGH라면
  {
    digitalWrite(IN1, HIGH); //정방향회전
    digitalWrite(IN2, LOW);
  }
  else{ //그밖에
    digitalWrite(IN1,LOW); //멈춤
    digitalWrite(IN2,LOW);
    
  }
}