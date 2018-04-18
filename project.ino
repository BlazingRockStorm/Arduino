#define led 13

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);  //Mở cổng Serial để giap tiếp | tham khảo Serial
}

int checkFire(int x, int y){
  if(x<=y){
    return 1;
  } else {
    return 0;  
  }
}

void alarm(int sensor1,int sensor2,int sensor3){
  if (checkFire(400, sensor1)==1){
    digitalWrite(led,HIGH);
    Serial.println("Có cháy");
  } else if (checkFire(sensor2, 300)==1){
    digitalWrite(led,HIGH);
    Serial.println("Có cháy");
  } else if (checkFire(sensor3, 720)==1){
    digitalWrite(led,HIGH);
    Serial.println("Có cháy");
  } else {
    digitalWrite(led,LOW);
  }
}

void loop() {
  int gasSensor = analogRead(A0);
  int lightSensor = analogRead(A1);   //đọc giá trị điện áp ở chân A1 - chân cảm biến
  int heatSensor = analogRead(A2);
                                //(value luôn nằm trong khoảng 0-1023)
//  Serial.println(checkFire(gasSensor, 400));        //xuất ra giá trị vừa đọc 
//  Serial.println(checkFire(90, lightSensor));        //xuất ra giá trị vừa đọc 
//  Serial.println(checkFire(heatSensor, 500));
//  Serial.println(heatSensor);
  Serial.println(lightSensor);
  //-----------------------------------------------------
  delay(1000);           //đợi 1 giây để bạn kịp tháy serial - (optional)
  alarm(gasSensor,lightSensor,heatSensor);
}

//Cảm biến sẽ chênh lệch giá trị 200 khi có thay đổi ánh sáng => chênh lệch giá trị khoảng 200 thì báo cháy luôn
