//////// ผนวกไลบรารี่ ////////////
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MechaQMC5883.h>
MechaQMC5883 qmc;
Adafruit_SSD1306 OLED(-1);
#include <Servo.h> // ผนวกไลบรารี่
/////////////////////////////////
///////////ตั้งชื่อพอร์ตต่างๆ///////////////////
int button =  53; /// กำหนดปุ่มกดสวิตซ์ขา 53
int snd = 52; // ให้ snd คือพอร์ต 52 ใช้สำหรับฟังก์ชันเสียง
int vr = 15;    /// analog vr port 15
///////////////////////////////////////////////
int s0 ; 
int s1 ;
int s2 ;
int s3 ;
int s4 ; 
int s5 ; 
int s6 ; 
int s7 ; 
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
#define DL1  9  // กำหนดสัญญาณดิจิตอลซ้ายที่ 1 พอร์ต 9
#define DL2  8  // กำหนดสัญญาณดิจิตอลซ้ายที่ 2 พอร์ต 8
#define PWML 2  /// กำหนดสัญญาณ PWM ซ้ายพอร์ต 2
//////////////////////////////////
#define DR1  11  /// กำหนดสัญญาณดิจิตอลขวาที่ 1 พอร์ต 11
#define DR2  10  /// กำหนดสัญญาณดิจิตอลขวาที่ 2 พอร์ต 10
#define PWMR 3 /// กำหนดสัญญาณ PWM ขวาพอร์ต 3
/////////////////////////////////////////////////
/////// ช่อง B //////////////////////////////////
#define DL1b  13  // กำหนดสัญญาณดิจิตอลซ้ายที่ 1 พอร์ต 9
#define DL2b  12  // กำหนดสัญญาณดิจิตอลซ้ายที่ 2 พอร์ต 8
#define PWMLb 4  /// กำหนดสัญญาณ PWM ซ้ายพอร์ต 2
//////////////////////////////////
#define DR1b  15  /// กำหนดสัญญาณดิจิตอลขวาที่ 1 พอร์ต 11
#define DR2b  14  /// กำหนดสัญญาณดิจิตอลขวาที่ 2 พอร์ต 10
#define PWMRb 5 /// กำหนดสัญญาณ PWM ขวาพอร์ต 3
/////// ช่อง c //////////////////////////////////
#define DL1c  17  // กำหนดสัญญาณดิจิตอลซ้ายที่ 1 พอร์ต 9
#define DL2c  16  // กำหนดสัญญาณดิจิตอลซ้ายที่ 2 พอร์ต 8
#define PWMLc 6  /// กำหนดสัญญาณ PWM ซ้ายพอร์ต 2
//////////////////////////////////
#define DR1c  23  /// กำหนดสัญญาณดิจิตอลขวาที่ 1 พอร์ต 11
#define DR2c  22  /// กำหนดสัญญาณดิจิตอลขวาที่ 2 พอร์ต 10
#define PWMRc 7 /// กำหนดสัญญาณ PWM ขวาพอร์ต 3
///////////////////////////////////////////////////////////////////////
/////////////////ตั้งค่าพอร์ต Analog ด้านหน้า//////////////
#define A0 600 // ค่ากลางเซนเซอร์ A0 (ซ้ายสุด)
#define A1 600 // ค่ากลางเซนเซอร์ A1 (ซ้ายกลาง)
#define A2 600 // ค่ากลางเซนเซอร์ A2 (ขวากลาง)
#define A3 600 // ค่ากลางเซนเซอร์ A3 (ขวาสุด)
///////////////////ตั้งค่าพอร์ต Analog ด้านหลัง////////////////////////////////
#define A4 600 // ค่ากลางเซนเซอร์ A0 (หลังซ้ายสุด)
#define A5 600// ค่ากลางเซนเซอร์ A1 (หลังซ้ายกลาง)
#define A6 600 // ค่ากลางเซนเซอร์ A2 (หลังขวากลาง)
#define A7 600 // ค่ากลางเซนเซอร์ A3 (หลังขวาสุด)
//////////////////////////////////////////////////////////
void analogs()
{
  s0 = analogRead(0);
  s1 = analogRead(1);
  s2 = analogRead(2);
  s3 = analogRead(3);
  s4 = analogRead(4);
  s5 = analogRead(5);
  s6 = analogRead(6);
  s7 = analogRead(7);
}
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT); // ตั้งค่าขา 2 เป็น INPUT
  pinMode(32,INPUT); pinMode(33,INPUT); pinMode(34,INPUT); pinMode(35,INPUT); pinMode(36,INPUT); pinMode(37,INPUT); pinMode(38,INPUT);
  pinMode(39,INPUT); pinMode(40,INPUT); pinMode(41,INPUT); pinMode(42,INPUT); pinMode(43,INPUT); pinMode(44,INPUT); pinMode(45,INPUT);
  pinMode(46,INPUT); pinMode(47,INPUT); pinMode(48,INPUT); pinMode(49,INPUT); pinMode(50,INPUT); pinMode(51,INPUT);  pinMode(53,INPUT);
  tone(snd,900,50);delay(150);tone(snd,900,50);
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
  ////////////////////////////
  OLED.begin(SSD1306_SWITCHCAPVCC,0x3C); // กำหนดแอดเดรสของพอร์ตจอเป็น 0x3C (for the 128x64)
  pinMode(button, INPUT); // ตั้งค่าขา button เป็น INPUT
  sv1.attach(ss1); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv1
  sv2.attach(ss2); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv2
  sv3.attach(ss3); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv3
  sv4.attach(ss4); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv4
  sv5.attach(ss5); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv5
  sv6.attach(ss6); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv6
  sv7.attach(ss7); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv7
  sv8.attach(ss8); // เรียกใช้งานเตรียมตอบสนองเซอร์โว sv8
  qmc.init();
  sv_set();
}
void loop() {
  int sw = digitalRead(button);     // ให้ sw อ่านค่า digital จากพอร์ต 2(button)
  int nob = analogRead(vr);          // ให้ nob เทียบเท่าค่า A7
  int menu = map(nob,0,1023,0,12);  // เทียบอัตราส่วนของพอร์ต A7 จาก 0-1023 เพื่อทำเป็นเมนู 0-12 
  OLED.clearDisplay();              // ล้างค่าหน้าจอ
  OLED.setTextColor(WHITE,BLACK);   //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(0,0);       // เซตตำแหน่ง 0,0
  OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.print("    ");         // วรรค
  OLED.println(menu);        // แสดงค่า Menu ที่ได้จากการ map nob ให้เหลือ 0-12
  OLED.setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.println("  LOTUS MEGA BOT");     // พิมพ์คำว่า KLS ROBOT CENTER
  OLED.print("  ");                      // วรรค
  OLED.println("LOTUS ARDUIBOT");     // พิมพ์คำว่า www.kls.ac.th
  OLED.print("        "); 
  OLED.println(nob);                     // แสดงค่าที่อ่านได้จาก nob หรือ Analog7
  OLED.display();
  //////////////////////////////////////////////////////
   if (menu == 0){OLED.setTextSize(2);OLED.println(" Analog Ck"); OLED.display();}
   if (menu == 1){OLED.setTextSize(2);OLED.println(" Servo  Ck"); OLED.display();}
   if (menu == 2){OLED.setTextSize(2);OLED.println("Digital Ck"); OLED.display();}
   if (menu == 3){OLED.setTextSize(2);OLED.println("Compass Ck"); OLED.display();}
   if (menu == 4){OLED.setTextSize(2);OLED.println(" Motor  Ck"); OLED.display();}
  /////////////////////////////////////////////////////
  if ((sw == 0) and (menu == 0))
  { 
   beep(); sensor ();
  }
  if ((sw == 0) and (menu == 1))
  {
   beep(); sv_knob();
  }
  if ((sw == 0) and (menu == 2))
  { 
   beep(); menu2();
  }
  if ((sw == 0) and (menu == 3))
  {
   beep(); menu3();
  }
  if ((sw == 0) and (menu == 4))
  {
   beep(); menu4();
  }
  if ((sw == 0) and (menu == 5))
  {
   beep();menu5();
  }
  if ((sw == 0) and (menu == 6))
  {
   beep();menu6();
  }
  if ((sw == 0) and (menu == 7))
  {
   menu7();beep();
  }
  if ((sw == 0) and (menu == 8))
  {
   beep();menu8();
  }
  if ((sw == 0) and (menu == 9))
  {
   beep();menu9();
  }
  if ((sw == 0) and (menu == 10))
  {
   beep();menu10();
  }
  if ((sw == 0) and (menu == 11))
  {
   beep();menu11();
  }
  if ((sw == 0) and (menu == 12))
  {
   beep();menu12();
  }
  delay(100);
}
void sensor (){
  while (1) {
      /////////// ตั้งค่าเซนเซอร์ตามการอ่านพอร์ตอนาล็อก S0,S1,S2,S3
  int s0 = analogRead(0);int s1 = analogRead(1);int s2 = analogRead(2);int s3 = analogRead(3);
  int s4 = analogRead(4);int s5 = analogRead(5);int s6 = analogRead(6);int s7 = analogRead(7);
  int s8 = analogRead(8);int s9 = analogRead(9);int s10 = analogRead(10);int s11 = analogRead(11);
  int s12 = analogRead(12);int s13 = analogRead(13);int s14 = analogRead(14);int s15 = analogRead(15);
 ////////////////////////////////////////////////////////
 
  OLED.clearDisplay();
  OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(0,0);       // เซตตำแหน่ง 0,0
 // OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
 // OLED.println("ROBOT CLUB");      // แสดงค่าข้อความ ROBOT CLUB
  OLED.setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 1
  
  OLED.print("    A0="); OLED.print(s0);  // แสดงค่าเซนเซอร์ S0
  OLED.print(" A1="); OLED.println(s1);  // แสดงค่าเซนเซอร์ S1
  
  OLED.print("    A2="); OLED.print(s2);  // แสดงค่าเซนเซอร์ S2
  OLED.print(" A3="); OLED.println(s3);  // แสดงค่าเซนเซอร์ S3
  
  OLED.print("    A4="); OLED.print(s4);  // แสดงค่าเซนเซอร์ S4
  OLED.print(" A5="); OLED.println(s5);  // แสดงค่าเซนเซอร์ S5
  
  OLED.print("    A6="); OLED.print(s6);  // แสดงค่าเซนเซอร์ S6
  OLED.print(" A7="); OLED.println(s7);  // แสดงค่าเซนเซอร์ S7
  
    OLED.print("    A8="); OLED.print(s8);  // แสดงค่าเซนเซอร์ S0
  OLED.print(" A9="); OLED.println(s9);  // แสดงค่าเซนเซอร์ S1
  
  OLED.print("  A10="); OLED.print(s10);  // แสดงค่าเซนเซอร์ S2
  OLED.print(" A11="); OLED.println(s11);  // แสดงค่าเซนเซอร์ S3
  
  OLED.print("  A12="); OLED.print(s12);  // แสดงค่าเซนเซอร์ S4
  OLED.print(" A13="); OLED.println(s13);  // แสดงค่าเซนเซอร์ S5
  
  OLED.print("  A14="); OLED.print(s14);  // แสดงค่าเซนเซอร์ S6
  OLED.print(" A15="); OLED.print(s15);  // แสดงค่าเซนเซอร์ S7
  
  OLED.display();
  delay(100);  // เปลี่ยนค่าเซนเซอร์ทุก 0.1 วินาที
}}
void digi (){
  

  while (1) {
      int D32 = digitalRead(32);int D33 = digitalRead(33);int D34 = digitalRead(34);int D35 = digitalRead(35);int D36 = digitalRead(36);
  int D37 = digitalRead(37);int D38 = digitalRead(38);int D39 = digitalRead(39);int D40 = digitalRead(40);int D41 = digitalRead(41);
  int D42 = digitalRead(42);int D43 = digitalRead(43);int D44 = digitalRead(44);int D45 = digitalRead(45);int D46 = digitalRead(46);
  int D47 = digitalRead(47);int D48 = digitalRead(48);int D49 = digitalRead(49);int D50 = digitalRead(50);int D51 = digitalRead(51);
  int D53 = digitalRead(53);
  OLED.clearDisplay();
  OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(0,0);       // เซตตำแหน่ง 0,0
  OLED.setTextSize(1);        // เซตขนาดอักษรมีขนาดเป็น 1  
  OLED.print(" 32=");OLED.print(D32);OLED.print(" 33=");OLED.print(D33);OLED.print(" 34=");OLED.print(D34);OLED.print(" 35=");OLED.println(D35);
  OLED.print(" 36=");OLED.print(D36);OLED.print(" 37=");OLED.print(D37);OLED.print(" 38=");OLED.print(D38);OLED.print(" 39=");OLED.println(D39);
  OLED.print(" 40=");OLED.print(D40);OLED.print(" 41=");OLED.print(D41);OLED.print(" 42=");OLED.print(D42);OLED.print(" 43=");OLED.println(D43); 
  OLED.print(" 44=");OLED.print(D44);OLED.print(" 45=");OLED.print(D45);OLED.print(" 44=");OLED.print(D44);OLED.print(" 47=");OLED.println(D47); 
  OLED.print(" 48=");OLED.print(D48);OLED.print(" 49=");OLED.print(D49);OLED.print(" 50=");OLED.print(D50);OLED.print(" 51=");OLED.println(D51); 
  OLED.print(" 53=");OLED.print(D53);
  OLED.display();
  delay(100);  // เปลี่ยนค่าเซนเซอร์ทุก 0.1 วินาที
}}
////////////////////////////////////////////////////////
void sv_knob() {
  while(true){
  int vr = analogRead(15);  // กำหนดตัวแปรจำนวนเต็มอ่านค่าอนาล็อกที่พอร์ต 7
  int nob = map(vr, 0, 1023, 0, 180); // ทำการ map อัตราส่วนจากสัญญาณ analog 0-1023 เป็น 0-180
  OLED.clearDisplay();    // เคลียร์หน้าจอ oled
  OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
  OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
  OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 2
  OLED.print("SV1-8=");     // พิมพ์คำว่า SV1 = 
  OLED.println(nob);     // นำค่า nob มาแสดงใน oled
  OLED.display();        // เปิดฟังก์ชันแสดงผล
  sv1.write(nob);        // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
  sv2.write(nob);        // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
  sv3.write(nob);        // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
  sv4.write(nob);        // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
  sv5.write(nob);        // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
  sv6.write(nob);        // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
  sv7.write(nob);        // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
  sv8.write(nob);        // สั่งเซอร์โวมอเตอร์ให้หมุนไปตามค่าองศาที่ทำการ nob ไว้
 // delay(50);             // หน่วงเวลา 0.05 วินาที
}}
////////// เข็มทิศ ////////////////////////////////
void compass()
{
  while (true) {
    int x, y, z;
    int azimuth;
    qmc.read(&x, &y, &z, &azimuth);
    analogs();
    OLED.clearDisplay();
    OLED.setTextColor(WHITE, BLACK);  //สีอักษรเป็นสีขาว ,พื้นหลังดำ
    OLED.setCursor(0, 0);       // เซตตำแหน่ง 0,0
    OLED.setTextSize(2);        // เซตขนาดอักษรมีขนาดเป็น 1
     OLED.println("  ");
    OLED.print(" Azi = "); OLED.println(azimuth);
    OLED.display();
    delay(50);
  }
}
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
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
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

//////////////////////////////////////
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
void sv_set()   // เซตเซอร์โว
{ sv1.write(67);delay(1000);
  sv2.write(35);delay(1000);
  }  
///////////////////////////////////////////////////////////////////////////////
void beep(){tone(snd, 1200, 50);}
/////////////////////////////////////////////
void motor(){ 
  OLED.clearDisplay();OLED.setCursor(0,0);OLED.setTextSize(2);OLED.println("ALL MOTOR ");OLED.display();
  RUN(100,100);delay(2000);RUN(0,0);beep();delay(1000);
  RUN(-100,100);delay(2000);RUN(0,0);beep();delay(1000);
  RUN(100,-100);delay(2000);RUN(0,0);beep();delay(1000);
  RUN(-100,-100);delay(2000);RUN(0,0);beep();delay(1000);

  OLED.clearDisplay();OLED.setCursor(0,0);OLED.setTextSize(2);OLED.println(" MOTOR A ");OLED.display();
  runa(100,100);delay(2000);runa(0,0);beep();delay(1000);
  runa(-100,100);delay(2000);runa(0,0);beep();delay(1000);
  runa(100,-100);delay(2000);runa(0,0);beep();delay(1000);
  runa(-100,-100);delay(2000);runa(0,0);beep();delay(1000);

  OLED.clearDisplay();OLED.setCursor(0,0);OLED.setTextSize(2);OLED.println(" MOTOR B ");OLED.display();
  runb(100,100);delay(2000);runb(0,0);beep();delay(1000);
  runb(-100,100);delay(2000);runb(0,0);beep();delay(1000);
  runb(100,-100);delay(2000);runb(0,0);beep();delay(1000);
  runb(-100,-100);delay(2000);runb(0,0);beep();delay(1000); 

  OLED.clearDisplay();OLED.setCursor(0,0);OLED.setTextSize(2);OLED.println(" MOTOR C ");OLED.display();
  runc(100,100);delay(2000);runc(0,0);beep();delay(1000);
  runc(-100,100);delay(2000);runc(0,0);beep();delay(1000);
  runc(100,-100);delay(2000);runc(0,0);beep();delay(1000);
  runc(-100,-100);delay(2000);runc(0,0);beep();delay(1000);
  }
/////////////////////////////////////////////
void P()
{ while (1) { 
    int s0 = analogRead(0); int s1 = analogRead(1); int s2 = analogRead(2); int s3 = analogRead(3);
    
    if (((s1 > A1) and (s2 > A2))) {run(100, 100);}

    if (s0 < A0) {run(20, 100);}
    if (s1 < A1) {run(30, 100);}
    if (s2 < A2) {run(100, 30);}
    if (s3 < A3) {run(100, 20);}
                                         
    if (((s0 < A0) and (s1 < A1)) or ((s1 < A1) and (s2 < A2)) or ((s2 < A2) and (s3 < A3))) 
    { run(100, 100); delay(120);  run(0, 0); delay(80);
      beep();  break;
}
}
}
void B()
{ while (1) { 
    int s4 = analogRead(4); int s5 = analogRead(5); int s6 = analogRead(6); int s7 = analogRead(7);
    
    if (((s5 > A5) and (s6 > A6))) {run(-100, -100);}

    if (s4 < A4) {run(-10, -100);}
    if (s5 < A5) {run(-30, -100);}
    if (s6 < A6) {run(-100, -30);}
    if (s7 < A7) {run(-100, -10);}
                                         
    if (((s4 < A4) and (s5 < A5)) or ((s5 < A5) and (s6 < A6)) or ((s6 < A6) and (s7 < A7))) 
    { run(-100, -100); delay(120);  run(0, 0); delay(80);
      beep();  break;
}
}
}
/////////////////////////เลี้ยวซ้าย///////////////////////////////////////////
void L0(){while (1){analogs();run(-100,100);if(s0<A0){run(0,0);break;}}} //S0
void L1(){while (1){analogs();run(-100,100);if(s1<A1){run(0,0);break;}}} //S1
void L2(){while (1){analogs();run(-100,100);if(s2<A2){run(0,0);break;}}} //S2
void L3(){while (1){analogs();run(-100,100);if(s3<A3){run(0,0);break;}}} //S3
//////////////////////เลี้ยวขวา//////////////////////////////////////////
void R0(){while (1){analogs();run(100,-100);if(s0<A0){run(0,0);break;}}} //S0
void R1(){while (1){analogs();run(100,-100);if(s1<A1){run(0,0);break;}}} //S1
void R2(){while (1){analogs();run(100,-100);if(s2<A2){run(0,0);break;}}} //S2
void R3(){while (1){analogs();run(100,-100);if(s3<A3){run(0,0);break;}}} //S3
//////////////////////////////////////////////////////////////////////////////////
void L(){L0(); L1();delay(80);beep();}
void R(){R3(); R2();delay(80);beep();}
/////////////////////////////////////////////////////////////////////////////////////
void menu2()   /// code 2 ที่นี่
{
digi ();
}
void menu3()   /// code 3 ที่นี่
{
compass();
}
void menu4()   /// code 4 ที่นี่
{
motor();
}
void menu5()   /// code 5 ที่นี่
{
run(-255,255);
}
void menu6()   /// code 6 ที่นี่
{ 
  
}
void menu7()   /// code 7 ที่นี่
{
  
}
void menu8()   /// code 8 ที่นี่
{
  
}
void menu9()   /// code 9 ที่นี่
{
  
}
void menu10()   /// code 10 ที่นี่
{
  
}
void menu11()   /// code 11 ที่นี่
{
  
}
void menu12()   /// code 12 ที่นี่
{
  
}
