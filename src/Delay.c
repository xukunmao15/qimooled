#include"Delay.h"
static volatile unsigned int ticks;
void Delay(uint32_t ulTime)  //������ʱ
{
	uint32_t i;
	i=0;
	while(ulTime--)
	{
		for(i=0;i<5000;i++);
	}
}
void delay_ms(int ms)       //��ʱ������(ϵͳʱ�ӵ���ʱ)
{
    SysTick->CTRL &= ~(1 << 2);      
    SysTick->LOAD = 25000*ms-1;            
    SysTick->VAL = 0;           //����ǰֵ����
    SysTick->CTRL = ((1<<1) | (1<<0));          //ʹ���жϣ�����ϵͳ���Ķ�ʱ��
    while(!ticks);              //�ȴ���ʱʱ�䵽��ticks = 1
    ticks = 0;              //����
    SysTick->CTRL = 0;          //ֹͣϵͳ���Ķ�ʱ��
}
void SysTick_Handler(void)          //ϵͳ���Ķ�ʱ���жϷ��������˺�����startup_LPC11xx.s�п��ҵ���
{
    ticks++;        //��1��ʾ��ʱ��ʱ�䵽��
}