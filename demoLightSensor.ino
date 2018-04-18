void setup() {
  Serial.begin(9600);  //Mở cổng Serial để giap tiếp | tham khảo Serial
}
 
void loop() {
  int value = analogRead(A1);   //đọc giá trị điện áp ở chân A1 - chân cảm biến
                                //(value luôn nằm trong khoảng 0-1023)
  Serial.println(value);        //xuất ra giá trị vừa đọc
  
  
  //-----------------------------------------------------
  delay(1000);           //đợi 1 giây để bạn kịp tháy serial - (optional)
}

//Cảm biến sẽ chênh lệch giá trị 200 khi có thay đổi ánh sáng => chênh lệch giá trị khoảng 200 thì báo cháy luôn
