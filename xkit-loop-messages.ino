#include <Time.h>
#define BETWEEN 30000

String message;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(100);
    
}

void loop() {
  
  sigfox(String(millis(), HEX));
  delay(BETWEEN);
}
void sigfox(String message){
  if (message.length() % 2 == 1){
    message = "0"+message;
  }
  Serial.println(message);
  Serial.println("AT$RC");delay(100);
  Serial.print("AT$SF=");
  Serial.println(message);
}
