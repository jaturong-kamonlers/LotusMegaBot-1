#ifndef LotusMegaServo_h
#define LotusMegaServo_h
////////////////////////////////////////////
//////  www.lotus-arduibot.com   //////////
///////////////////////////////////////////
#include "Servo.h"
// flags for function set
#define _lotus_servo1 24
#define _lotus_servo2 25
#define _lotus_servo3 26
#define _lotus_servo4 27
#define _lotus_servo5 28
#define _lotus_servo6 29
#define _lotus_servo7 30
#define _lotus_servo8 31

Servo lotus_servo1;
Servo lotus_servo2;
Servo lotus_servo3;
Servo lotus_servo4;
Servo lotus_servo5;
Servo lotus_servo6;
Servo lotus_servo7;
Servo lotus_servo8;

#ifndef ALL
#define ALL 100
#endif

void servo(uint8_t servo,int16_t angle)
{
  if (servo==ALL)
  {
    if (angle==-1)
	{
	  lotus_servo1.detach();
	  lotus_servo2.detach();
	  lotus_servo3.detach();
	  lotus_servo4.detach();
	  lotus_servo5.detach();
	  lotus_servo6.detach();
	  lotus_servo7.detach();
	  lotus_servo8.detach();   
	}
	else
	{
      if (!(lotus_servo1.attached()))
	  {
		lotus_servo1.attach(_lotus_servo1);
	  }
	  lotus_servo1.write(angle);

      if (!(lotus_servo2.attached()))
	  {
		lotus_servo2.attach(_lotus_servo2);
	  }
	 lotus_servo2.write(angle);

      if (!(lotus_servo3.attached()))
	  {
		lotus_servo3.attach(_lotus_servo3);
	  }
	  lotus_servo3.write(angle);
	  if (!(lotus_servo4.attached()))
	  {
		lotus_servo4.attach(_lotus_servo4);
	  }
	  lotus_servo4.write(angle);  
	  if (!(lotus_servo5.attached()))
	  {
		lotus_servo5.attach(_lotus_servo5);
	  }
	  lotus_servo5.write(angle);
	  if (!(lotus_servo6.attached()))
	  {
		lotus_servo6.attach(_lotus_servo6);
	  }
	  lotus_servo6.write(angle); 
	  if (!(lotus_servo7.attached()))
	  {
		lotus_servo7.attach(_lotus_servo7);
	  }
	  lotus_servo7.write(angle); 
	  if (!(lotus_servo8.attached()))
	  {
		lotus_servo8.attach(_lotus_servo8);
	  }
	  lotus_servo8.write(angle);   
	}
  }
  
  if (servo==1)
  {
    if (angle==-1)
	{
	 lotus_servo1.detach();
	}
	else
	{
      if (!(lotus_servo1.attached()))
	  {
		lotus_servo1.attach(_lotus_servo1);
	  }
	  lotus_servo1.write(angle);
	}
  }
  
  if (servo==2)
  {
    if (angle==-1)
	{
	 lotus_servo2.detach();
	}
	else
	{
      if (!(lotus_servo2.attached()))
	  {
		lotus_servo2.attach(_lotus_servo2);
	  }
	 lotus_servo2.write(angle);
	}
  }
  
  if (servo==3)
  {
    if (angle==-1)
	{
	 lotus_servo3.detach();
	}
	else
	{
      if (!(lotus_servo3.attached()))
	  {
		lotus_servo3.attach(_lotus_servo3);
	  }
	  lotus_servo3.write(angle);
	}
  }

 
  if (servo==4)
  {
    if (angle==-1)
	{
	 lotus_servo4.detach();
	}
	else
	{
      if (!(lotus_servo4.attached()))
	  {
		lotus_servo4.attach(_lotus_servo4);
	  }
	  lotus_servo4.write(angle);
	}
  }

 
  if (servo==5)
  {
    if (angle==-1)
	{
	 lotus_servo5.detach();
	}
	else
	{
      if (!(lotus_servo5.attached()))
	  {
		lotus_servo5.attach(_lotus_servo5);
	  }
	  lotus_servo5.write(angle);
	}
  }

 
  if (servo==6)
  {
    if (angle==-1)
	{
	 lotus_servo6.detach();
	}
	else
	{
      if (!(lotus_servo6.attached()))
	  {
		lotus_servo6.attach(_lotus_servo6);
	  }
	  lotus_servo6.write(angle);
	}
  }

 
  if (servo==7)
  {
    if (angle==-1)
	{
	 lotus_servo7.detach();
	}
	else
	{
      if (!(lotus_servo7.attached()))
	  {
		lotus_servo7.attach(_lotus_servo7);
	  }
	  lotus_servo7.write(angle);
	}
  }


 
  if (servo==8)
  {
    if (angle==-1)
	{
	 lotus_servo8.detach();
	}
	else
	{
      if (!(lotus_servo8.attached()))
	  {
		lotus_servo8.attach(_lotus_servo8);
	  }
	  lotus_servo8.write(angle);
	}
  }
}

void sv1(int16_t angle){lotus_servo1.attach(_lotus_servo1);lotus_servo1.write(angle);}
void sv2(int16_t angle){lotus_servo2.attach(_lotus_servo2);lotus_servo2.write(angle);}
void sv3(int16_t angle){lotus_servo3.attach(_lotus_servo3);lotus_servo3.write(angle);}
void sv4(int16_t angle){lotus_servo4.attach(_lotus_servo4);lotus_servo4.write(angle);}
void sv5(int16_t angle){lotus_servo5.attach(_lotus_servo5);lotus_servo5.write(angle);}
void sv6(int16_t angle){lotus_servo6.attach(_lotus_servo6);lotus_servo6.write(angle);}
void sv7(int16_t angle){lotus_servo7.attach(_lotus_servo7);lotus_servo7.write(angle);}
void sv8(int16_t angle){lotus_servo8.attach(_lotus_servo8);lotus_servo8.write(angle);}


//////////
#endif
