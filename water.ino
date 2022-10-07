void setup() {
  Serial.begin(9600); //시리얼 모니터를 시작합니다.
}

void loop() {
  int level = analogRead(A0);  // 수분센서의 신호를 측정합니다.
  if (level > 580){
    Serial.println("Warring");   //시리얼 모니터에 값을 출력합니다.
  }
}
