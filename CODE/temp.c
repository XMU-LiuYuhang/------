#include "temp.h"

void temp_run()
{   
    static short temp = 00.00;
    LCD_ShowString(12,85,200,16,16,"Temperature:");
    temp=Get_Temprate();	//�����¶�ֵ
    if(temp<0)
    {
        temp=-temp;
        LCD_ShowString(2*8,105,16,16,16,"-");	//��ֵ
    }else LCD_ShowString(2*8,105,16,16,16," ");	//��ֵ		
    LCD_ShowxNum(24,105,temp/100,2,16,0);		//С����ǰ
    LCD_ShowString(40,105,16,16,16,".");                    //С����
    LCD_ShowxNum(45,105,temp%100,2,16, 0X80);	//С�����
    LCD_ShowString(62,105,16,16,16,"C");		//��λ
}