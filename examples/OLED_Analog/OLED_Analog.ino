////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// สามารถเข้ามาดูข้อมูลการใช้งานได้ที่ : https://sites.google.com/site/klsrobotcenter/lab-0-library-lotus-mega-bot
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <LotusMegaBot.h> // ผนวกLibrary LotusMegaBot.h

void setup() {
set();  // เรียกฟังก์ชันการใช้งานพื้นฐาน
}

void loop() {
oleddel(); // ฟังก์ชันลบหน้าจอ OLED
oledlnp(0,0,1,"Analog0 =",inA(0)); // แสดงผลอักษรที่เริ่มต้นที่ตำแหน่งพิกเซล x=0  y=0 ขนาดตัวอักษร 1 point แสดงข้อความ Analog 0 = ค่าที่วัดได้ที่พอร์ต A0 หากมีอักษรอื่นมาเพิ่มให้ขึ้นบรรทัดถัดไปln
oledlnp("Analog1 =",inA(1)); // แสดงข้อความ Analog 1 = ค่าที่วัดได้ที่พอร์ต A1
oledlnp("Analog2 =",inA(2)); // แสดงข้อความ Analog 1 = ค่าที่วัดได้ที่พอร์ต A1
oledplay(); // ฟังก์ชันแสดงข้อความที่หน้าจอ OLED
delay(100);
}