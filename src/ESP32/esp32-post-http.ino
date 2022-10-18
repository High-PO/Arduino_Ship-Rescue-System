#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <HttpClient.h>
// const char* ssid = "wi_cne_class_S";    //wift 아이디
// const char* password =  "0132s220420!";    // wifi 비번 
const char* ssid = "CLIT";    //wift 아이디
const char* password =  "wifipassword";    // wifi 비번 
const char* serverName = "http://ip:8080/ui"; // 웹서버주소

IPAddress hostIp(00, 000, 000, 000);  //웹서버의 ip 주소
int SERVER_PORT = 8080;  // 웹서버 포트 번호
WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);   // 와이파이 접속
 
  while (WiFi.status() != WL_CONNECTED) { //Check for the connection
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
}

void loop() {
  int wcheck = 0;
  while(wcheck < 1){
    value = analogRead(ANALOG_PIN); // esp32에서 읽은 co2 값을 value에 저장한다.
    HTTPClient http;   
    http.begin("http://ip:8080/ui");  //Specify destination for HTTP request
    http.addHeader("Content-Type",  "application/x-www-form-urlencoded");   //Specify content-type header,  Json형식의 타입이다.
    //http.addHeader("Content-Type",  "application/json");   //Specify content-type header,  Json형식의 타입이다.
      if(value > 580){
        char* Wvalue = "Warring";
        String httpRequestData = "value="+String(Wvalue);  // 가장 중요한 Json 데이터를 입력하는 부분이다  = 의 왼쪽이 key값 오른쪽이 value 값이고 &를 기준으로 쌍이 나뉘어진다.
        Serial.println(httpRequestData); //시리얼 모니터에 Json 형식의 데이터를 찍어준다.
        int httpResponseCode = http.POST(httpRequestData);   //Send the actual POST request
      
        if(httpResponseCode>0){ // 잘 전송되었으면
          String response = http.getString();                       //Get the response to the request
          Serial.println(httpResponseCode);   //Print return code
          Serial.println(response);           //Print request answer
        }else{
          Serial.print("Error on sending POST: ");
          Serial.println(httpResponseCode);  
        }
        http.end();  //Free resources
        }
      else{
        char* Svalue = "Safe";
        String httpRequestData = "value="+String(Svalue);  // 가장 중요한 Json 데이터를 입력하는 부분이다  = 의 왼쪽이 key값 오른쪽이 value 값이고 &를 기준으로 쌍이 나뉘어진다.
        Serial.println(httpRequestData); //시리얼 모니터에 Json 형식의 데이터를 찍어준다.
        int httpResponseCode = http.POST(httpRequestData);   //Send the actual POST request
      
        if(httpResponseCode>0){ // 잘 전송되었으면
          String response = http.getString();                       //Get the response to the request
          Serial.println(httpResponseCode);   //Print return code
          Serial.println(response);           //Print request answer
        }else{
          Serial.print("Error on sending POST: ");
          Serial.println(httpResponseCode);  
        }
        http.end();  //Free resources
        }    
    delay(100000);  //Send a request every 10 seconds
  }
}