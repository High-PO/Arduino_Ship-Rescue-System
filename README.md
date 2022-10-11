# Arduino Ship Rescue System
## KR Version
### 준비물
Arduino Uno 보드를 활용하여 선박 구조 시스템을 구축하는 코드이다.
사용하는 준비물들은 다음과 같다.
- 펌프모터
- RFID
- 접촉식 수위센서
- 피에조 부저
- 스위치
### 동작설명
1. 스위치를 눌러서 펌프모터를 작동시키면 수조에 물이 찬다.
2. 접촉식 수위센서가 수위를 감지함.
3. 수위가 일정이상으로 올라가게되면 피에조 부저가 울림
4. RFID로 카드를 인식하면 펌프모터가 반대로 작동하여 물이 차지 않게 줄어듬
5. 해당 모든 과정을 ESP32 모듈을 통해서 실시간 웹사이트로 제공한다.
### 회로도
## EN Version
### Supplies
It is a code for constructing a ship rescue system using the Arduino Uno board.
The preparations used are as follows.
- Pump motor
- - RFID
- Contact type water level sensor
- Piezo Buzzer
- Switch
### Operation description
1. When the pump motor is operated by pressing the switch, water fills the tank.
2. Contact type water level sensor detects water level.
3. Piezo buzzer rings when the water level rises above a certain level
4. If the card is recognized by RFID, the pump motor operates in reverse, reducing the water level
5. All applicable processes are provided through the ESP32 module as a real-time website.

