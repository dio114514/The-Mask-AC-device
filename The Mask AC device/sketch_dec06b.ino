#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0,SCL,SDA); //配置构造函数
#define INTERVAL_LCD             20             //定义OLED刷新时间间隔  
unsigned long lcd_time = millis();                 //OLED刷新时间计时器
#include <SoftwareSerial.h>
SoftwareSerial mySerial(13, 12); // RX, TX
char buffer[20];
void setup() {
  Serial.begin(9600);
  mySerial.begin(115200);
  u8g2.begin();
}
void loop() {
 if(mySerial.available()>0)
  {
    if(mySerial.peek()!='\n')   //在没接收到回车换行的条件下
    {
      for(int i=0;i<20;i++)
      {
        buffer[i]=(char)mySerial.read(); 
        }
    }
  }
u8g2.firstPage();
do{
    u8g2.setFont(u8g2_font_wqy12_t_chinese1);
    //u8g2.drawBitmap(60, 10, 4, 32, buffer);
    //u8g2.drawUTF8(0,20,buffer);
  //u8g2.setCursor(0, 20);
  u8g2.drawStr(0,20,buffer);
  // u8g2.print(buffer);
 }while (u8g2.nextPage());
}
