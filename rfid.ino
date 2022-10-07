#include <SPI.h>
#include <MFRC522.h>
 
const int RST_PIN = 9;
const int SS_PIN = 10;
 
MFRC522 mfrc522(SS_PIN, RST_PIN);   // MFRC522 인스턴스
 
byte CardUidByte[4] = {0x76, 0xA8, 0x9F, 0xBB}; //card UID
boolean state = false; //Servo Motor 상태값
 
const int TONEPIN = 6;
 
void setup() {
  Serial.begin(9600);  
  while (!Serial);     
  SPI.begin();         //SPI 시작
  mfrc522.PCD_Init();  //MFRC522 card 초기화
  Serial.println(F("Warning: this example clears your mifare UID, use with care!"));
  delay(50);
}
 
void loop() {
  // 새 카드 확인
  if ( ! mfrc522.PICC_IsNewCardPresent()) return; 
  // 카드 읽기
  if ( ! mfrc522.PICC_ReadCardSerial()) return;
  //읽은 Card UID와 등록된 Card UID가 일치하는 확인
  if (mfrc522.uid.uidByte[0] == CardUidByte[0] && mfrc522.uid.uidByte[1] == CardUidByte[1] &&
        mfrc522.uid.uidByte[2] == CardUidByte[2] && mfrc522.uid.uidByte[3] == CardUidByte[3] ){    
    state=!state;
    if(state == true){
      Serial.println("Open");
      //카드 확인 메세지 음
      tone(TONEPIN ,523,1000/8);
      delay(1000/4*1.30);             
      noTone(TONEPIN );            
      delay(1000);
    }
    else{
      Serial.println("Close");
      //카드 확인 메세지 음
      tone(TONEPIN ,523,1000/8);
      delay(1000/4*1.30);             
      noTone(TONEPIN );  
      delay(1000);
    }
    delay(2000);
   }  
}