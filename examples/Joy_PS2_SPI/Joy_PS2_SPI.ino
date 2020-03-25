////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// สามารถเข้ามาดูข้อมูลการใช้งานได้ที่ : https://sites.google.com/site/klsrobotcenter/lab-0-library-lotus-mega-bot
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Servo.h>
#include <PS2X_lib.h> 
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftwareSerial.h>
Adafruit_SSD1306 OLED(-1);                           
///////////////////////////////////////////////////////////////////////////////
#define PS2_DAT        32      // ขา DAT   เป็นขา 32
#define PS2_CMD        33      // ขา CMD   เป็นขา 33 
#define PS2_SEL        34      // ขา CS    เป็นขา 34 
#define PS2_CLK        35      // ขา CLK   เป็นขา 35 
///////////////////////////////////////////////////////////////////////////////
PS2X ps2x;

int snd = 52; // ให้ snd คือพอร์ต 52 ใช้สำหรับฟังก์ชันเสียง                                      
////////////////ตั้งค่าพอร์ตเซอร์โว//////////////////////////
int ss1 = 24;  // เปิดใช้งาน s1 ที่พอร์ต 24
int ss2 = 25;  // เปิดใช้งาน s1 ที่พอร์ต 25
int ss3 = 26;  // เปิดใช้งาน s1 ที่พอร์ต 26
int ss4 = 27;  // เปิดใช้งาน s1 ที่พอร์ต 27
int ss5 = 28;  // เปิดใช้งาน s1 ที่พอร์ต 28
int ss6 = 29;  // เปิดใช้งาน s1 ที่พอร์ต 29
int ss7 = 30;  // เปิดใช้งาน s1 ที่พอร์ต 30
int ss8 = 31;  // เปิดใช้งาน s1 ที่พอร์ต 31
Servo sv1;     // ประกาศการใช้งาน sv1
Servo sv2;     // ประกาศการใช้งาน sv2
Servo sv3;     // ประกาศการใช้งาน sv3
Servo sv4;     // ประกาศการใช้งาน sv4
Servo sv5;     // ประกาศการใช้งาน sv5
Servo sv6;     // ประกาศการใช้งาน sv6
Servo sv7;     // ประกาศการใช้งาน sv7
Servo sv8;     // ประกาศการใช้งาน sv8
////////////ตั้งค่าพอร์ตมอเตอร์////////////////////
/////////////////////////////////
#define DL1  9  // กำหนดสัญญาณดิจิตอลซ้ายที่ 1 พอร์ต 9
#define DL2  8  // กำหนดสัญญาณดิจิตอลซ้ายที่ 2 พอร์ต 8
#define PWML 2  /// กำหนดสัญญาณ PWM ซ้ายพอร์ต 2
//////////////////////////////////
#define DR1  11  /// กำหนดสัญญาณดิจิตอลขวาที่ 1 พอร์ต 11
#define DR2  10  /// กำหนดสัญญาณดิจิตอลขวาที่ 2 พอร์ต 10
#define PWMR 3 /// กำหนดสัญญาณ PWM ขวาพอร์ต 3
/////////////////////////////////////////////////
/////// ช่อง B //////////////////////////////////
#define DL1b  13  // กำหนดสัญญาณดิจิตอลซ้ายที่ 1 พอร์ต 13
#define DL2b  12  // กำหนดสัญญาณดิจิตอลซ้ายที่ 2 พอร์ต 12
#define PWMLb 4  /// กำหนดสัญญาณ PWM ซ้ายพอร์ต 4
//////////////////////////////////
#define DR1b  15  /// กำหนดสัญญาณดิจิตอลขวาที่ 1 พอร์ต 15
#define DR2b  14  /// กำหนดสัญญาณดิจิตอลขวาที่ 2 พอร์ต 14
#define PWMRb 5 /// กำหนดสัญญาณ PWM ขวาพอร์ต 5
/////// ช่อง c //////////////////////////////////
#define DL1c  17  // กำหนดสัญญาณดิจิตอลซ้ายที่ 1 พอร์ต 17
#define DL2c  16  // กำหนดสัญญาณดิจิตอลซ้ายที่ 2 พอร์ต 16
#define PWMLc 6  /// กำหนดสัญญาณ PWM ซ้ายพอร์ต 6
//////////////////////////////////
#define DR1c  23  /// กำหนดสัญญาณดิจิตอลขวาที่ 1 พอร์ต 23
#define DR2c  22  /// กำหนดสัญญาณดิจิตอลขวาที่ 2 พอร์ต 22
#define PWMRc 7 /// กำหนดสัญญาณ PWM ขวาพอร์ต 7

//////////////////////////////////////////////
int servo_x = 90;   // ตัวแปรสำหรับเก็บองศาของเซอร์โวที่ใช้หนีบวัตถุ
int servo_y = 90;   // ตัวแปรสำหรับเก็บองศาของเซอร์โวที่ใช้ยกแขนจับ

boolean isR1 = false; // สภานะของปุ่ม R1
boolean isR2 = false; // สภานะของปุ่ม R2
boolean isL1 = false; // สภานะของปุ่ม L1
boolean isL2 = false; // สภานะของปุ่ม L2


 
/////////////////แสดงโลโก้โลตัส อาดุยบอท/////////////////////////
const unsigned char logo [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 
0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 
0x62, 0x40, 0x01, 0x00, 0x24, 0x82, 0x08, 0x0a, 0x18, 
0x6f, 0xc0, 0x07, 0x80, 0x7f, 0xef, 0xdf, 0x3f, 0xd8, 
0x63, 0x80, 0x3f, 0xf8, 0xee, 0x67, 0x06, 0x70, 0xc8, 
0x63, 0x00, 0x1f, 0xf0, 0xce, 0x63, 0x04, 0x70, 0xd8, 
0x63, 0x80, 0x3e, 0xf8, 0x06, 0x07, 0x86, 0x3e, 0x18, 
0x63, 0x80, 0x78, 0x78, 0x0e, 0x07, 0x0c, 0x1f, 0xd8, 
0x63, 0x00, 0xfc, 0x3e, 0x0e, 0x03, 0x06, 0x0b, 0xe8, 
0x63, 0x86, 0x38, 0x78, 0x0e, 0x07, 0x04, 0x60, 0xf8, 
0x63, 0x8c, 0x3f, 0xf8, 0x06, 0x03, 0x8c, 0x70, 0xe8, 
0x67, 0xfc, 0x3f, 0xf0, 0x0f, 0x03, 0xdc, 0x7d, 0xd8, 
0x6f, 0xb8, 0x3f, 0xf8, 0x1f, 0x01, 0xf0, 0x2f, 0x98, 
0x60, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x08, 
0x60, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 
0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 
0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 
0x60, 0x87, 0xe7, 0xc7, 0x37, 0x7e, 0x1e, 0x3f, 0x18, 
0x61, 0x86, 0x67, 0x73, 0x33, 0x33, 0x33, 0x6d, 0x18, 
0x63, 0xc6, 0x32, 0x33, 0x23, 0x13, 0x61, 0x8c, 0x88, 
0x63, 0xc7, 0xe6, 0x33, 0x32, 0x3e, 0x61, 0x8c, 0x18, 
0x63, 0xe6, 0xc3, 0x32, 0x13, 0x33, 0x63, 0x8c, 0x18, 
0x66, 0x66, 0x66, 0x33, 0x23, 0x33, 0x31, 0x8c, 0x08, 
0x66, 0x77, 0x77, 0xe3, 0xe7, 0x3f, 0x3f, 0x1c, 0x18, 
0x64, 0x40, 0x11, 0x00, 0x04, 0x48, 0x04, 0x02, 0x18, 
0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 
0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/////////////////////////////////////////////////////////////////////
void setup()
{  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C); // กำหนดแอดเดรสของพอร์ตจอเป็น 0x3C (for the 128x64)
   ////////กำหนดสัญญาณทุกขาเป็น OUTPUT /////////
  OLED.begin(SSD1306_SWITCHCAPVCC,0x3C); // initialize with the I2C addr 0x3C (for the 128x64)
  OLED.clearDisplay();
  OLED.drawBitmap(40,20,logo,70,32,1);  //40,20 is x,y coordinates and 70,32 พิกเซล is image size
  OLED.display();
////////กำหนดสัญญาณทุกขาเป็น OUTPUT ///////////////
  pinMode(DL1, OUTPUT);
  pinMode(DL2, OUTPUT);
  pinMode(PWML, OUTPUT);
  pinMode(DR1, OUTPUT);
  pinMode(DR2, OUTPUT);
  pinMode(PWMR, OUTPUT);
  ////////////////////////////
  pinMode(DL1b, OUTPUT);
  pinMode(DL2b, OUTPUT);
  pinMode(PWMLb, OUTPUT);
  pinMode(DR1b, OUTPUT);
  pinMode(DR2b, OUTPUT);
  pinMode(PWMRb, OUTPUT);
  //////////////////////
    pinMode(DL1c, OUTPUT);
  pinMode(DL2c, OUTPUT);
  pinMode(PWMLc, OUTPUT);
  pinMode(DR1c, OUTPUT);
  pinMode(DR2c, OUTPUT);
  pinMode(PWMRc, OUTPUT);
 /////////////////// กำหนดค่าเซอร์โวแต่ละตัว ////////////////////////
 sv1.attach(ss1); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv1
  sv2.attach(ss2); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv2
  sv3.attach(ss3); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv3
  sv4.attach(ss4); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv4
  sv5.attach(ss5); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv5
  sv6.attach(ss6); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv6
  sv7.attach(ss7); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv7
  sv8.attach(ss8); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv8
  
  while(true)      // วนรอบเพื่อเชื่อมต่อจอย PS2
  {
    // กำหนดขาที่จะเชื่อมต่กับ PS2 Controller โดยมีการเก็บค่าที่ส่งกลับมาเป็น Integer เพื่อรู้ได้ว่าเชื่อมต่อได้หรือไม่
    int error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);
    if(error == 0)                               // หากเชื่อมต่อได้ (Error = 0)
    {
       tone(3,900,100);delay(200);tone(3,1100,100);break;   //ส่งเสียงแล้วออกจากวนรอบ
    } 
    delay(300);                                  // วนรอบทุกๆ0.3 วินาทีกรณีที่เชื่อมต่อไม่ติด
  }
}
void loop()
{
  ps2x.read_gamepad(false, false);               // อ่านข้อมูล PS2 Controller
  if(ps2x.Button(PSB_R1))                        // R1 ถูกกด
    isR1 = true;                                 // isR1 เป็น True
  else                                           // R1 ไม่ถูกกด
    isR1 = false;                                // isR1 เป็น False
    
  if(ps2x.Button(PSB_R2))                        // R2 ถูกกด 
    isR2 = true;                                 // isR2 เป็น True
  else                                           // R2 ไม่ถูกกด
    isR2 = false;                                // isR2 เป็น False
    
  if(ps2x.Button(PSB_L1))                        // L1 ถูกกด 
    isL1 = true;                                 // isL1 เป็น True
  else                                           // L1 ไม่ถูกกด
    isL1 = false;                                // isL1 เป็น False
    
  if(ps2x.Button(PSB_L2))                        // L2 ถูกกด 
    isL2 = true;                                 // isL2 เป็น True
  else                                           // L2 ไม่ถูกกด
    isL2 = false;                                // isL2 เป็น False
    
  if(ps2x.Button(PSB_TRIANGLE))                  // เมื่อปุ่มสามเหลี่ยมถูกกด
  { sv1.write(-1); // ผ่อนเซอร์โวทั้งสองตัว
    sv2.write(-1);

  } 
  
  if(ps2x.Button(PSB_PAD_UP))                    // ถ้าปุ่มขึ้นถูกกด
    RUN(100,100);                                // วิ่งตรง
  else if(ps2x.Button(PSB_PAD_DOWN))             // ถ้าปุ่มลงถูกกด
    RUN(-100,-100);                              // ถอยหลัง
  else if(ps2x.Button(PSB_PAD_LEFT))             // ถ้าปุ่มซ้ายถูกกด
    RUN(-100,100);                               // เลี้ยวซ้าย
  else if(ps2x.Button(PSB_PAD_RIGHT))            // ถ้าปุ่มขวาถูกกด
    RUN(100,-100);                               // เลี้ยวขวา
  else                                           // นอกเหนือจากทุกกรณี
    RUN(0,0);                                    // มอเตอร์หยุด

 //////////////////////////////หนีบ-อ้า////////////////////////////////////////////////// 
  if(isR1)                                       // isR1 ถูกกด : หนีบวัตถุ
  {  
    servo_x += 5;                                // เพิ่มขึ้นทีละ 5 องศา
    servo_x = (servo_x > 90) ? 90 : servo_x;     // เซอร์โวสูงสุดแค่ 90 องศา
    sv1.write(servo_x);                          // ค่าในการทำงานของเซอร์โวเท่ากับ Servo_x ปัจจุบัน  
  } 
  else if(isR2)                                  // เมื่อสถานะของ isR2 เป็น True (ถูกกด) : ปล่อยวัตถุ
  {
    servo_x -= 5;                                // องศาของเซอร์โวลดลง 2 องศา
    servo_x = (servo_x < 0) ? 0 : servo_x;       // ให้ค่าองศาของเซอร์โวต่ำสุดแค่ 40 องศา
    sv1.write(servo_x);                          // ค่าในการทำงานของเซอร์โวเท่ากับ Servo_x ปัจจุบัน
  } 
  ////////////////////////////ยก-ลง//////////////////////////////////////////////////////
  else if(isL1)                                  //  isL1 (ถูกกด) : แขนกลลดระดับ
  {
    servo_y += 5;                               // เพิ่มขึ้นทีละ 5 องศา
    servo_y = (servo_y > 90) ? 90 : servo_y;    // เซอร์โวสูงสุดแค่ 90 องศา
    sv2.write(servo_y);                         // ค่าในการทำงานของเซอร์โวเท่ากับ Servo_y ปัจจุบัน
  } 
  else if(isL2)                                // isL2 (ถูกกด) : แขนกลยกขึ้น
  {
    servo_y -= 5;                              // ลดทีละ 5 องศา
    servo_y = (servo_y < 0) ? 0 : servo_y;     // เซอร์โวต่ำสุดได้แค่ 0 องศา
    sv2.write(servo_y);                        // ค่าในการทำงานของเซอร์โวเท่ากับ Servo_y ปัจจุบัน
  }
  
  delay(50);                                  // หน่วงเวลา 50 มิลลิวินาที
}
/////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////
void RUN(int ml , int mr){runa(ml,mr);runb(ml,mr);runc(ml,mr); } // คำสั่งควบคุมมอเตอร์ทั้ง 6 ช่อง
///////////////////////////////////////////////////////////////////
void run(int spr, int spl)   // ประกาศฟังก์ชัน run(กำลังมอเตอร์ซ้าาย,กำลังมอเตอร์ขวา);
{ if (spl > 0)
  {   
    digitalWrite(DL1, LOW);
    digitalWrite(DL2, HIGH);
    analogWrite(PWML, spl);
  }
else if (spl < 0)
  {
    digitalWrite(DL1, HIGH);
    digitalWrite(DL2, LOW);
    analogWrite(PWML, -spl);
  }      
else
  {             
    digitalWrite(DL1, LOW);
    digitalWrite(DL2, LOW);
    analogWrite(PWML, -255);
  }
///////////////////////////////////////////////
if (spr > 0)
  {     
    digitalWrite(DR1, LOW);
    digitalWrite(DR2, HIGH);
    analogWrite(PWMR, spr);
  }
else if (spr < 0)
  {
    digitalWrite(DR1, HIGH);
    digitalWrite(DR2, LOW);
    analogWrite(PWMR, -spr);
  }
else
  {
    digitalWrite(DR1, LOW);
    digitalWrite(DR2, LOW);
    analogWrite(PWMR, -255);
  }}
  void runa(int spra, int spla)   // ประกาศฟังก์ชัน run(กำลังมอเตอร์ซ้าาย,กำลังมอเตอร์ขวา);
{ if (spla > 0)
  {   
    digitalWrite(DL1, LOW);
    digitalWrite(DL2, HIGH);
    analogWrite(PWML, spla);
  }
else if (spla < 0)
  {
    digitalWrite(DL1, HIGH);
    digitalWrite(DL2, LOW);
    analogWrite(PWML, -spla);
  }      
else
  {             
    digitalWrite(DL1, LOW);
    digitalWrite(DL2, LOW);
    analogWrite(PWML, -255);
  }
///////////////////////////////////////////////
if (spra > 0)
  {     
    digitalWrite(DR1, LOW);
    digitalWrite(DR2, HIGH);
    analogWrite(PWMR, spra);
  }
else if (spra < 0)
  {
    digitalWrite(DR1, HIGH);
    digitalWrite(DR2, LOW);
    analogWrite(PWMR, -spra);
  }
else
  {
    digitalWrite(DR1, LOW);
    digitalWrite(DR2, LOW);
    analogWrite(PWMR, -255);
  }}
/////////////////////////////ฟังก์ชันมอเตอร์///////////////////////////////////
/////////////////////////////ฟังก์ชันมอเตอร์///////////////////////////////////
void runb(int sprb, int splb)   // ประกาศฟังก์ชัน run(กำลังมอเตอร์ซ้าาย,กำลังมอเตอร์ขวา);
{ if (splb > 0)
  {
  digitalWrite(DL1b, LOW);
  digitalWrite(DL2b, HIGH);
  analogWrite(PWMLb, splb);
  }
else if (splb < 0)
  {
    digitalWrite(DL1b, HIGH);
    digitalWrite(DL2b, LOW);
    analogWrite(PWMLb, -splb);
  }
else
  {
    digitalWrite(DL1b, LOW);
    digitalWrite(DL2b, LOW);
    analogWrite(PWMLb, -255);
  }
  //////////////////////////////////////
if (sprb > 0)
  {
    digitalWrite(DR1b, LOW);
    digitalWrite(DR2b, HIGH);
    analogWrite(PWMRb, sprb);
  }
else if (sprb < 0)
  {
    digitalWrite(DR1b, HIGH);
    digitalWrite(DR2b, LOW);
    analogWrite(PWMRb, -sprb);
  }
else
  {
    digitalWrite(DR1b, LOW);
    digitalWrite(DR2b, LOW);
    analogWrite(PWMRb, -255);
  }}

//////////////////////////////////////ฟ
void runc(int sprc, int splc)   // ประกาศฟังก์ชัน run(กำลังมอเตอร์ซ้าาย,กำลังมอเตอร์ขวา);
{ if (splc > 0)
  {
    digitalWrite(DL1c, LOW);
    digitalWrite(DL2c, HIGH);
    analogWrite(PWMLc, splc);
  }
else if (splc < 0)
  {
    digitalWrite(DL1c, HIGH);
    digitalWrite(DL2c, LOW);
    analogWrite(PWMLc, -splc);
    }
else
  {
    digitalWrite(DL1c, LOW);
    digitalWrite(DL2c, LOW);
    analogWrite(PWMLc, -255);
  }
  //////////////////////////////////////
if (sprc > 0)
  {
    digitalWrite(DR1c, LOW);
    digitalWrite(DR2c, HIGH);
    analogWrite(PWMRc, sprc);
  }
else if (sprc < 0)
  {
    digitalWrite(DR1c, HIGH);
    digitalWrite(DR2c, LOW);
    analogWrite(PWMRc, -sprc);
  }
else
  {
    digitalWrite(DR1c, LOW);
    digitalWrite(DR2c, LOW);
    analogWrite(PWMRc, -255);
  }}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
