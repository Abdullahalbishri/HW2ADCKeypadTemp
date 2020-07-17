/*
 * HW2ADCKeypadTemp.c
 *
 * Created: 7/16/2020 10:42:32 PM
 * Author : Abdullah Albishri
 */ 

 #include "Temp_Sensor.h"
 #include "LCD.h"
 #include "KeyPad.h"
 #define F_CPU 16000000
 #include <util/delay.h>

 int main(void)
 {
	 
	 uint8 value = 0;
	 uint8 Pass[6]={'1','9','4','5'};//Password
	 uint8 Userinput[6];
	 uint8 CorrectPass=0;
	 unsigned short Index=0; 
	 sint32 Temp = 0;
	 int i=0;
	 LCD_Init();
	 KeyPad_Init();
     LCD_Init();
	 TempSensor_Init();
	 
	 while (1)
	 {
	 if (i<=Index&&CorrectPass!=1)
	 {
	
		 value = KeyPad_GetValue();
		 
		 if(value)
		 {

			 if(value=='#'&& Index!=0)
			 {
			     for (;;i++)
			     {
				   if(Pass[i]!=Userinput[i])
				   {
				   CorrectPass=0;
				   Index=0;i=0;
				   LCD_Clear();LCD_GoTo(0,0);
				   _delay_ms(100);
				   LCD_WriteString("Wrong Password!");
				   _delay_ms(1000);
				   LCD_Clear();LCD_GoTo(0,0);
				   LCD_WriteString("Reenter the Password");
				   _delay_ms(1000);
				   LCD_Clear();LCD_GoTo(0,0);
				   _delay_ms(100);
				   break;
				   }
				   else if (i+1>=Index)
				   {
				   CorrectPass=1;
				   break;
				   }
			     }

				// if(i>Index)
				// {
				// LCD_Clear();LCD_GoTo(0,0);
				// LCD_WriteString("Temp");
				// }
			 }
			 else 
			 {
			 LCD_WriteChar('*');
			 Userinput[Index]=value;
			 Index++;
			 }
		 }
	 }
		 else if(CorrectPass==1)
		 {
		 	TempSensor_Read(&Temp);
		 	
		 	LCD_Clear();
		 	
		 	LCD_WriteInteger(Temp);
		 	
		 	_delay_ms(500);
		 }
		 
       }
}
 