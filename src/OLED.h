#ifndef __OLED_H
#define __OLED_H
#include "lpc11xx.h"
	  
#define  u8 unsigned char 
#define  u32 unsigned int 
#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����
#define OLED_MODE 0

//sbit OLED_CS=P4^0; //Ƭѡ
//sbit OLED_RST =P3^6;//��λ����ֱ�ӽ�VCC
//sbit OLED_DC =P4^2;//����/�������
//sbit OLED_SCL=P3^7;//ʱ�� D0��SCLK
//sbit OLED_SDIN=P4^3;//D1��MOSI�� ����

#define OLED_CS(a)	if (a)	\
					LPC_GPIO2->DATA |= (1<<0);\
					else		\
					LPC_GPIO2->DATA &= ~(1<<0)

#define OLED_DC(a)	if (a)	\
					LPC_GPIO2->DATA |= (1<<3);\
					else		\
					LPC_GPIO2->DATA &= ~(1<<3)

#define OLED_MOSI(a)	if (a)	\
					LPC_GPIO2->DATA |= (1<<2);\
					else		\
					LPC_GPIO2->DATA &= ~(1<<2)

#define OLED_SCK(a)	if (a)	\
					LPC_GPIO2->DATA |= (1<<1);\
					else		\
					LPC_GPIO2->DATA &= ~(1<<1)



#define OLED_CS_Clr()  OLED_CS(0)
#define OLED_CS_Set()  OLED_CS(1)

#define OLED_RST_Clr() OLED_RST(0)
#define OLED_RST_Set() OLED_RST(1)

#define OLED_DC_Clr() OLED_DC(0)
#define OLED_DC_Set() OLED_DC(1)

#define OLED_SCLK_Clr() OLED_SCK(0)
#define OLED_SCLK_Set() OLED_SCK(1)

#define OLED_SDIN_Clr() OLED_MOSI(0)
#define OLED_SDIN_Set() OLED_MOSI(1)


//OLEDģʽ����
//0:4�ߴ���ģʽ
//1:����8080ģʽ

#define SIZE 16
#define XLevelL		0x02
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    						  
//-----------------OLED�˿ڶ���----------------  					   

		     

//OLED�����ú���
void OLED_WR_Byte(u8 dat,u8 cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);	   							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
void OLED_ShowChar(u8 x,u8 y,u8 chr);       //��ʾ�ַ�
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size2);          //��ʾ���ֱ��� 
void OLED_ShowString(u8 x,u8 y, u8 *p);	         //��ʾ�ַ���	
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowCHinese(u8 x,u8 y,u8 no);         //��ʾ����
#endif  