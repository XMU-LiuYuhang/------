#include "stm32f10x.h"


/************************************************
 ALIENTEK ս��STM32F103������ʵ��0
 ����ģ��
 ע�⣬�����ֲ��е��½������½�ʹ�õ�main�ļ� 
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/
#include "headfile.h"




 int main(void)
 {	
	u8 t=0;	
  
  delay_init();	    	 //��ʱ������ʼ��
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
  uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
  LED_Init();					 //��ʼ����LED���ӵ�Ӳ���ӿ�
  LCD_Init();					 //��ʼ��LCD
	Time_Init();				 //��ʼ��ʱ��
	tp_dev.init();			 //��ʼ��������
  TP_Adjust();
  POINT_COLOR=BLUE;    //��������Ϊ��ɫ
	DrawMenu();					 //���Ƴ�ʼ����
  LED_Init();		  	//��ʼ��LED�˿�
	T_Adc_Init();		  		//ADC��ʼ��
  Lsens_Init(); 			//��ʼ������������
  // TIM3_PWM_Init(899,0);	 //??��?????PWM????=72000000/900=80Khz
  flash_init();       //��ʼ��flash	
	 
  while(1)
	{
    Time_run(t);
		Scan_key(Get_keynum(10,160));
    Input_show(input_num);
    Control_time_light();
    Control_light_light();
    Show_light_value();


    if(seasonmenu_flag != 1)
    {
      Show_light();
      temp_run();
    }
    else
    { 
      SetRun();
    }

	}
 }
