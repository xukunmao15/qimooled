#include"KEY.h"
#include"oled.h"
extern uint8_t datashang;
extern uint8_t dataxia;
void Keyinit()
	 {
	 LPC_GPIO3->DIR &=~(1<<0);//将P3.0置为输入
	 LPC_GPIO3->IE |=(1<<0);//允许中断
	 LPC_GPIO3->IS  &=~(1<<0);//边缘触发
	 LPC_GPIO3->IEV  &=~(1<<0);//下降沿触发
		 
   LPC_GPIO3->DIR &=~(1<<1);
	 LPC_GPIO3->IE |=(1<<1);
	 LPC_GPIO3->IS  &=~(1<<1);
	 LPC_GPIO3->IEV  &=~(1<<1);
		 
	 LPC_GPIO3->DIR &=~(1<<2);
	 LPC_GPIO3->IE |=(1<<2);
	 LPC_GPIO3->IS  &=~(1<<2);
	 LPC_GPIO3->IEV  &=~(1<<2);
		 
		  LPC_GPIO3->DIR &=~(1<<3);
	 LPC_GPIO3->IE |=(1<<3);
	 LPC_GPIO3->IS  &=~(1<<3);
	 LPC_GPIO3->IEV  &=~(1<<3);
		 
		  LPC_GPIO3->DIR &=~(1<<4);
	 LPC_GPIO3->IE |=(1<<4);
	 LPC_GPIO3->IS  &=~(1<<4);
	 LPC_GPIO3->IEV  &=~(1<<4);
	 }
	 
	 
	void PIOINT3_IRQHandler()
{
 if((LPC_GPIO3->MIS &(1<<0))==(1<<0))
 {
	    datashang--;
			if(datashang>=40)
			datashang=40;
		OLED_ShowString(0,4,"Tempshang:");
		OLED_ShowNum(70,4,datashang,2,16);
		OLED_ShowCHinese(90,4,0);
			
			
	 LPC_GPIO3->IC =(1<<0);
 }	

 if((LPC_GPIO3->MIS &(1<<1))==(1<<1))
 {
	 dataxia++;
	 if(dataxia<=10)
		 dataxia=10;
	  OLED_ShowString(0,2,"Tempxia:");
		OLED_ShowNum(70,2,dataxia,2,16);
		OLED_ShowCHinese(90,2,0);
	 LPC_GPIO3->IC =(1<<1);
 }	
 
 if((LPC_GPIO3->MIS &(1<<3))==(1<<3))
 {
	 datashang--;
	 if(datashang<=40)
		 datashang=40;
	  OLED_ShowString(0,4,"Tempshang:");
		OLED_ShowNum(70,4,datashang,2,16);
		OLED_ShowCHinese(90,4,0);
	 LPC_GPIO3->IC =(1<<3);
 }	
if((LPC_GPIO3->MIS &(1<<4))==(1<<4))
 {
	    dataxia++;
			if(dataxia>=10)
			dataxia=10;
		OLED_ShowString(0,2,"Tempxia:");
		OLED_ShowNum(70,2,dataxia,2,16);
		OLED_ShowCHinese(90,2,0);
			
			
	 LPC_GPIO3->IC =(1<<4);
 }	 
 if((LPC_GPIO3->MIS &(1<<2))==(1<<2))//如果是P3.2引起的中断
 {
	 OLED_Clear();
	 OLED_ShowCHinese(0,6,5);
	 OLED_ShowCHinese(20,6,6);
	 OLED_ShowCHinese(40,6,7);
	 OLED_ShowCHinese(60,6,8);
   LPC_GPIO3->IC =(1<<2);
 }
}
