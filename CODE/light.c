#include "light.h"
#include "headfile.h"

// ·�ƿ���״ָ̬ʾ
void Show_light()
{
    if(LED0 == 0)
    {		
        LCD_ShowString(160,48,48,16,16,"ON ");
    }
    else
    {
        LCD_ShowString(160,48,48,16,16,"OFF");
    }

    if(LED1 == 0)
    {
        LCD_ShowString(250,48,48,16,16,"ON ");
    }
    else
    {
        LCD_ShowString(250,48,48,16,16,"OFF");
    }
}


int summer_begin_month = 6;//����ʱ��ʼ�·�
int summer_end_month = 9;//����ʱ�����·�
int summer_begin_day = 1;//����ʱ��ʼ����
int summer_end_day = 1;//����ʱ��������

int summer_begin_hour = 19;//·�ƿ���Сʱ
int summer_end_hour = 5;//·�ƹر�Сʱ
int summer_begin_min = 30;//·�ƿ�������
int summer_end_min = 30;//·�ƹرշ���

int winter_begin_hour = 18;//·�ƿ���Сʱ
int winter_end_hour = 6;//·�ƹر�Сʱ
int winter_begin_min = 30;//·�ƿ�������
int winter_end_min = 30;//·�ƹرշ���


int season_flag = 0;//���ڱ�־λ 0Ϊ����ʱ��1Ϊ����ʱ

u8 adcx; //����������ֵ
void Show_light_value()
{   
    if(mode_flag != 2)
    {
        // �ǹ���ģʽ�²�ִ��
        return;
    }
    adcx=Lsens_Get_Val();
    LCD_ShowxNum(90,135,adcx,3,16,0);
    LCD_ShowString(12,135,128,16,16,"LightValue:");
}


int light_flag = 0;//·�ƿ��ر�־λ 0Ϊ�أ�1Ϊ��
// �����ƽ�������
void Light_up()
{
    int i = 0;
    for(i = 0;i <= 300;i++)
    {   
        delay_ms(10);
        TIM_SetCompare1(TIM3,i);
    }
    light_flag = 1;
}

// �����ƽ���
void Light_down()
{
    int i = 0;
    for(i = 300;i >= 0;i--)
    {
        TIM_SetCompare1(TIM3,i);
        delay_ms(10);
    }
    light_flag = 0;
}


// ����ģʽ����ͣ�߼�
void Control_light_light()
{
    if(mode_flag != 2)
    {
        // �ǹ���ģʽ�²�ִ��
        return;
    }

    if(adcx < 30)
    {
        // ����
        LED0 = 0;
        LED1 = 0;
    }
    else
    {
        // �ر�
        LED0 = 1;
        LED1 = 1;
    }
}

// ʱ��ģʽ����ͣ�߼�
void Control_time_light()
{
    if(mode_flag != 0)
    {
        // ��ʱ��ģʽ�²�ִ��
        return;
    }

    if(season_flag == 0)
    {
        //����ʱ
        if(summer_end_hour > summer_begin_hour )
        {
            //����ʱ����24��ǰ
            if( (calendar.hour > summer_begin_hour && calendar.hour < summer_end_hour) || (calendar.hour == summer_begin_hour && calendar.min >= summer_begin_min) || (calendar.hour == summer_end_hour && calendar.min <= summer_end_min) )
            {
                // ����
                LED0 = 0;
                LED1 = 0;
            }
            else
            {
                // �ر�
                LED0 = 1;
                LED1 = 1;
            }
            
        }
        else if (summer_begin_hour == summer_end_hour)
        {
            // ��ʼʱ��ͽ���ʱ����ͬ
            if(calendar.hour == summer_begin_hour && calendar.min >= summer_begin_min && calendar.min <= summer_end_min)
            {
                // ����
                LED0 = 0;
                LED1 = 0;
            }
            else
            {
                // �ر�
                LED0 = 1;
                LED1 = 1;
            }
        }
        else
        {
            // ����ʱ����24���
            if( (calendar.hour > summer_begin_hour || calendar.hour < summer_end_hour) || (calendar.hour == summer_begin_hour && calendar.min >= summer_begin_min) || (calendar.hour == summer_end_hour && calendar.min <= summer_end_min) )
            {
                // ����
                LED0 = 0;
                LED1 = 0;
            }
            else
            {
                // �ر�
                LED0 = 1;
                LED1 = 1;
            }
        }
    }
    else
    {
        // ����ʱ
        if(winter_end_hour > winter_begin_hour )
        {
            //����ʱ����24��ǰ
            if( (calendar.hour > winter_begin_hour && calendar.hour < winter_end_hour) || (calendar.hour == winter_begin_hour && calendar.min >= winter_begin_min) || (calendar.hour == winter_end_hour && calendar.min <= winter_end_min) )
            {
                // ����
                LED0 = 0;
                LED1 = 0;
            }
            else
            {
                // �ر�
                LED0 = 1;
                LED1 = 1;
            }
            
        }
        else if (winter_begin_hour == winter_end_hour)
        {
            // ��ʼʱ��ͽ���ʱ����ͬ
            if(calendar.hour == winter_begin_hour && calendar.min >= winter_begin_min && calendar.min <= winter_end_min)
            {
                // ����
                LED0 = 0;
                LED1 = 0;
            }
            else
            {
                // �ر�
                LED0 = 1;
                LED1 = 1;
            }
        }
        else
        {
            // ����ʱ����24���
            if( (calendar.hour > winter_begin_hour || calendar.hour < winter_end_hour) || (calendar.hour == winter_begin_hour && calendar.min >= winter_begin_min) || (calendar.hour == winter_end_hour && calendar.min <= winter_end_min) )
            {
                // ����
                LED0 = 0;
                LED1 = 0;
            }
            else
            {
                // �ر�
                LED0 = 1;
                LED1 = 1;
            }
        }
    }


}
