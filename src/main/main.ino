#include <SPI.h>
#include <MFRC522.h>
byte CardUidByte[4] = {0x76, 0xA8, 0x9F, 0xBB}; // Blue Keyring Card UID
const int RST_PIN = 9; //
const int SS_PIN = 10;
const int TONEPIN = 6;
int IN1 = 2; //IN1을 2번핀으로
int IN2 = 3; //IN2을 3번핀으로
MFRC522 mfrc522(SS_PIN, RST_PIN);
boolean state = false; //Servo Motor 상태값
void setup() {
  Serial.begin(9600); 오승진 죽었으면... 죽어라 에휫 승진이 내일 뒷통수 조심해..... 현서 보러 가야징
  while (!Serial);
  SPI.begin();         //SPI 시작
  mfrc522.PCD_Init();  //MFRC522 card 초기화
  Serial.println(F("Warning: this example clears your mifare UID, use with care!"));
  delay(50);
}
void loop() {
  int level = analogRead(A0);  // A0포트에 연결되어있느 수위센서의 신호를 측정
  if (level > 580){ //만약 수위센서에 580이상의 값이 입력된다.
    Serial.println("Warring");   // 시리얼 모니터로 "Warring"이라는 문구를 출력한다.
    tone(TONEPIN ,523,1000/8); // 비프음이 울리게한다.
    delay(1000/4*1.30); // 딜레이를 준다.
  }
  // 새 카드 확인
  if ( ! mfrc522.PICC_IsNewCardPresent()) return;
  // 카드 읽기
  if ( ! mfrc522.PICC_ReadCardSerial()) return;
  //읽은 Card UID와 등록된 Card UID가 일치하는 확인
  if (mfrc522.uid.uidByte[0] == CardUidByte[0] && mfrc522.uid.uidByte[1] == CardUidByte[1] &&
        mfrc522.uid.uidByte[2] == CardUidByte[2] && mfrc522.uid.uidByte[3] == CardUidByte[3] ){
    state=!state;
    if(state == true){
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      Serial.println("Open");
      delay(1000);
      // //카드 확인 메세지 음
      // noTone(TONEPIN);
      // delay(1000);
    }
    else{
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      delay(1000);
    }
  }
}