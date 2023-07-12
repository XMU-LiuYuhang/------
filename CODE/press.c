#include "press.h"
#include "headfile.h"

//����״̬����
//x,y:��ʼ����
//keyx:�������,0~15,������,���ϵ���,0,1,2,3,4,5,6,7,8
//sta:0,�ɿ�;1,����.
void py_key_staset(u16 x,u16 y,u8 keyx,u8 sta)
{                  
        if(keyx>19)return;
	
        if(sta)
					Fill_key(keyx);//��������
        else 
					Fill_white(keyx);//�����ɿ�
					POINT_COLOR=BLUE;
		DrawKeyboard(10,160,300,310);
}

//����ֵ��0-15
u8 Get_keynum(u16 x,u16 y)
{	
	u16 i,j;
	static u8 key_x=0;//0,û���κΰ�������
	u8 key=0;
	tp_dev.scan(0); 		 
	if(tp_dev.sta&TP_PRES_DOWN)  //������������
	{	
		for(i=0;i<5;i++)
		{
			for(j=0;j<4;j++)
			{
				if((tp_dev.x[0]>x+j*key_width_real)&&(tp_dev.x[0]<x+j*key_width_real + key_width_real)&&
					(tp_dev.y[0]>y+i*key_height_real)&&(tp_dev.y[0]<y+i*key_height_real + key_height_real))
				{
					key=i*4+j+1;
					break;
				}
			}
		}
	if(key)
	{
		if(key_x==key)
		{
		key=0;//������ϴΰ��µİ�����ͬ,�򲻴���
		}
		else
		{
			py_key_staset(x,y,key_x-1,0);
			key_x = key;
			py_key_staset(x,y,key_x-1,1);
		}
	}
	}
	else if(key_x)
	{
		py_key_staset(x,y,key_x-1,0);//�ɿ�����
		key_x = 0;
	}
	return key; 
}

//������ɫ����
//x,y:�ڼ��еڼ���
void Fill_key(u8 keyx)
{
	POINT_COLOR=GREEN;
	switch(keyx)
	{	
		case 0:LCD_Fill(key_x0+10,key_y0+10,key_x0+10+key_width,key_y0+10+key_height,GREEN);break;
		case 1:LCD_Fill(key_x0+2*10+key_width,key_y0+10,key_x0+2*10+2*key_width,key_y0+10+key_height,GREEN);break;
		case 2:LCD_Fill(key_x0+3*10+2*key_width,key_y0+10,key_x0+3*10+3*key_width,key_y0+10+key_height,GREEN);break;
		case 3:LCD_Fill(key_x0+4*10+3*key_width,key_y0+10,key_x0+4*10+4*key_width,key_y0+10+key_height,GREEN);break;

		case 4:LCD_Fill(key_x0+10,key_y0+2*10+key_height,key_x0+10+key_width,key_y0+2*10+2*key_height,GREEN);break;
		case 5:LCD_Fill(key_x0+2*10+key_width,key_y0+2*10+key_height,key_x0+2*10+2*key_width,key_y0+2*10+2*key_height,GREEN);break;
		case 6:LCD_Fill(key_x0+3*10+2*key_width,key_y0+2*10+key_height,key_x0+3*10+3*key_width,key_y0+2*10+2*key_height,GREEN);break;
		case 7:LCD_Fill(key_x0+4*10+3*key_width,key_y0+2*10+key_height,key_x0+4*10+4*key_width,key_y0+2*10+2*key_height,GREEN);break;

		case 8:LCD_Fill(key_x0+10,key_y0+3*10+2*key_height,key_x0+10+key_width,key_y0+3*10+3*key_height,GREEN);break;
		case 9:LCD_Fill(key_x0+2*10+key_width,key_y0+3*10+2*key_height,key_x0+2*10+2*key_width,key_y0+3*10+3*key_height,GREEN);break;
		case 10:LCD_Fill(key_x0+3*10+2*key_width,key_y0+3*10+2*key_height,key_x0+3*10+3*key_width,key_y0+3*10+3*key_height,GREEN);break;
		case 11:LCD_Fill(key_x0+4*10+3*key_width,key_y0+3*10+2*key_height,key_x0+4*10+4*key_width,key_y0+3*10+3*key_height,GREEN);break;

		case 12:LCD_Fill(key_x0+10,key_y0+4*10+3*key_height,key_x0+10+key_width,key_y0+4*10+4*key_height,GREEN);break;
		case 13:LCD_Fill(key_x0+2*10+key_width,key_y0+4*10+3*key_height,key_x0+2*10+2*key_width,key_y0+4*10+4*key_height,GREEN);break;
		case 14:LCD_Fill(key_x0+3*10+2*key_width,key_y0+4*10+3*key_height,key_x0+3*10+3*key_width,key_y0+4*10+4*key_height,GREEN);break;
		case 15:LCD_Fill(key_x0+4*10+3*key_width,key_y0+4*10+3*key_height,key_x0+4*10+4*key_width,key_y0+4*10+4*key_height,GREEN);break;

		case 16:LCD_Fill(key_x0+10,key_y0+5*10+4*key_height,key_x0+10+key_width,key_y0+5*10+5*key_height,GREEN);break;
		case 17:LCD_Fill(key_x0+2*10+key_width,key_y0+5*10+4*key_height,key_x0+2*10+2*key_width,key_y0+5*10+5*key_height,GREEN);break;
		case 18:LCD_Fill(key_x0+3*10+2*key_width,key_y0+5*10+4*key_height,key_x0+3*10+3*key_width,key_y0+5*10+5*key_height,GREEN);break;
		case 19:LCD_Fill(key_x0+4*10+3*key_width,key_y0+5*10+4*key_height,key_x0+4*10+4*key_width,key_y0+5*10+5*key_height,GREEN);break;

		default:break;
	}
}

//��ɫ��亯��
void Fill_white(u8 keyx)
{
	POINT_COLOR=WHITE;
	switch(keyx)
	{	
		case 0:LCD_Fill(key_x0+10,key_y0+10,key_x0+10+key_width,key_y0+10+key_height,WHITE);break;
		case 1:LCD_Fill(key_x0+2*10+key_width,key_y0+10,key_x0+2*10+2*key_width,key_y0+10+key_height,WHITE);break;
		case 2:LCD_Fill(key_x0+3*10+2*key_width,key_y0+10,key_x0+3*10+3*key_width,key_y0+10+key_height,WHITE);break;
		case 3:LCD_Fill(key_x0+4*10+3*key_width,key_y0+10,key_x0+4*10+4*key_width,key_y0+10+key_height,WHITE);break;

		case 4:LCD_Fill(key_x0+10,key_y0+2*10+key_height,key_x0+10+key_width,key_y0+2*10+2*key_height,WHITE);break;
		case 5:LCD_Fill(key_x0+2*10+key_width,key_y0+2*10+key_height,key_x0+2*10+2*key_width,key_y0+2*10+2*key_height,WHITE);break;
		case 6:LCD_Fill(key_x0+3*10+2*key_width,key_y0+2*10+key_height,key_x0+3*10+3*key_width,key_y0+2*10+2*key_height,WHITE);break;
		case 7:LCD_Fill(key_x0+4*10+3*key_width,key_y0+2*10+key_height,key_x0+4*10+4*key_width,key_y0+2*10+2*key_height,WHITE);break;

		case 8:LCD_Fill(key_x0+10,key_y0+3*10+2*key_height,key_x0+10+key_width,key_y0+3*10+3*key_height,WHITE);break;
		case 9:LCD_Fill(key_x0+2*10+key_width,key_y0+3*10+2*key_height,key_x0+2*10+2*key_width,key_y0+3*10+3*key_height,WHITE);break;
		case 10:LCD_Fill(key_x0+3*10+2*key_width,key_y0+3*10+2*key_height,key_x0+3*10+3*key_width,key_y0+3*10+3*key_height,WHITE);break;
		case 11:LCD_Fill(key_x0+4*10+3*key_width,key_y0+3*10+2*key_height,key_x0+4*10+4*key_width,key_y0+3*10+3*key_height,WHITE);break;

		case 12:LCD_Fill(key_x0+10,key_y0+4*10+3*key_height,key_x0+10+key_width,key_y0+4*10+4*key_height,WHITE);break;
		case 13:LCD_Fill(key_x0+2*10+key_width,key_y0+4*10+3*key_height,key_x0+2*10+2*key_width,key_y0+4*10+4*key_height,WHITE);break;
		case 14:LCD_Fill(key_x0+3*10+2*key_width,key_y0+4*10+3*key_height,key_x0+3*10+3*key_width,key_y0+4*10+4*key_height,WHITE);break;
		case 15:LCD_Fill(key_x0+4*10+3*key_width,key_y0+4*10+3*key_height,key_x0+4*10+4*key_width,key_y0+4*10+4*key_height,WHITE);break;

		case 16:LCD_Fill(key_x0+10,key_y0+5*10+4*key_height,key_x0+10+key_width,key_y0+5*10+5*key_height,WHITE);break;
		case 17:LCD_Fill(key_x0+2*10+key_width,key_y0+5*10+4*key_height,key_x0+2*10+2*key_width,key_y0+5*10+5*key_height,WHITE);break;
		case 18:LCD_Fill(key_x0+3*10+2*key_width,key_y0+5*10+4*key_height,key_x0+3*10+3*key_width,key_y0+5*10+5*key_height,WHITE);break;
		case 19:LCD_Fill(key_x0+4*10+3*key_width,key_y0+5*10+4*key_height,key_x0+4*10+4*key_width,key_y0+5*10+5*key_height,WHITE);break;

		default:break;
	}
}

//�˷�����
int pow(int x,int y)
{	
	int i = 0;
	int result = 1;
	
	if(y == 0)
	{
		return 0;
	}

	for(i = 0;i < y;i++)
	{
		result *= x;
	}
	return result;
}

//������ʾ����
void Input_show(u32 num)
{	
	if(mode_flag != 0)
	{
		return;
	}
	if(seasonmenu_flag == 1)
	{
		LCD_ShowNum(240,105,num,5,16);
	}
	else
	{
		LCD_ShowNum(150,105,num,5,16);
	}

}

u32 input_num = 0; //���������
int input_times = 0; //�������
int choose_flag = 0; //ѡ���־ 0~5 ��Ӧ������ʱ����
int choose_season_flag = 0;
u16 flash_data[18] = {0}; //��ŵ��籣����Ϣ
//��ֵɨ�躯��
void Scan_key(u8 keyx)
{
	switch(keyx)
	{
		case 1: 
			if(mode_flag == 0)
			{//ʱ��ģʽ
				choose_flag++;
				if(choose_flag == 6)
				{
					choose_flag = 0;
				}
			}
			if(mode_flag == 1)
			{//�ֶ�ģʽ
				// LCD_Clear(WHITE);
				// LCD_Fill(160,45,185,61,WHITE);
				if(LED0 == 0)
				{
					LED0 = 1;
					// LCD_ShowString(160,48,32,16,16,"ON");
				}
				else
				{
					LED0 = 0;
					// LCD_ShowString(160,48,48,16,16,"OFF");
				}
			}
			if(season_flag == 1)
			{
				choose_season_flag++;
				if(choose_season_flag == 12)
				{
					choose_season_flag = 0;
				}
			}
			break;	
		case 2:
			if(mode_flag == 0)
			{
				DrawSeasonMenu();
			}
			if(mode_flag == 1)
			{//�ֶ�ģʽ
				// LCD_Clear(WHITE);
				LCD_Fill(250,45,275,61,WHITE);
				if(LED1 == 0)
				{
					LED1 = 1;
					LCD_ShowString(250,48,32,16,16,"ON");
				}
				else
				{
					LED1 = 0;
					LCD_ShowString(250,48,48,16,16,"OFF");
				}
			}
			break;	
		case 3: ChangeMode();break; //�ı�ģʽ
		case 4: flash_change();STMFLASH_Write(FLASH_SAVE_ADDR,flash_data,sizeof(flash_data));break; //��ǰ��Ϣд��flash
		case 5: input_num = 1+input_num*10;input_times++;break;
		case 6: input_num = 2+input_num*10;input_times++;break;
		case 7: input_num = 3+input_num*10;input_times++;break;

		case 8: input_num = 0; input_times = 0;break;

		case 9: input_num = 4+input_num*10;input_times++;break;
		case 10: input_num = 5+input_num*10;input_times++;break;
		case 11: input_num = 6+input_num*10;input_times++;break;

		case 12: input_num /= 10;input_times--;break;

		case 13: input_num = 7+input_num*10;input_times++;break;
		case 14: input_num = 8+input_num*10;input_times++;break;
		case 15: input_num = 9+input_num*10;input_times++;break;

		case 16: 
				if(mode_flag == 0)
				{
					//ʱ��ģʽ
					if(seasonmenu_flag == 0)
					{
						switch(choose_flag)
						{	
							case 0: RTC_Set(input_num,calendar.w_month,calendar.w_date,calendar.hour,calendar.min,calendar.sec);break;
							case 1: RTC_Set(calendar.w_year,input_num,calendar.w_date,calendar.hour,calendar.min,calendar.sec);break;
							case 2: RTC_Set(calendar.w_year,calendar.w_month,input_num,calendar.hour,calendar.min,calendar.sec);break;
							case 3: RTC_Set(calendar.w_year,calendar.w_month,calendar.w_date,input_num,calendar.min,calendar.sec);break;
							case 4: RTC_Set(calendar.w_year,calendar.w_month,calendar.w_date,calendar.hour,input_num,calendar.sec);break;
							case 5: RTC_Set(calendar.w_year,calendar.w_month,calendar.w_date,calendar.hour,calendar.min,input_num);break;
						}
					}
					else
					{
						switch(choose_season_flag)
						{
							case 0: summer_begin_month = input_num;break;
							case 1: summer_begin_day = input_num;break;
							case 2: summer_end_month = input_num;break;
							case 3: summer_end_day = input_num;break;
							case 4: summer_begin_hour = input_num;break;
							case 5: summer_begin_min = input_num;break;
							case 6: summer_end_hour = input_num;break;
							case 7: summer_end_min = input_num;break;
							case 8: winter_begin_hour = input_num;break;
							case 9: winter_begin_min = input_num;break;
							case 10: winter_end_hour = input_num;break;
							case 11: winter_end_min = input_num;break;

						}
					}

					
				}
		case 17: break;
		case 18: input_num *= 10;input_times++;break;
		case 19: break;
		case 20: seasonmenu_flag = 0;DrawTimeMenu();break;
	}
}

//���籣����Ϣˢ��
void flash_change()
{	
	int i;
	flash_data[0] = calendar.w_year;
	flash_data[1] = calendar.w_month;
	flash_data[2] = calendar.w_date;
	flash_data[3] = calendar.hour;
	flash_data[4] = calendar.min;
	flash_data[5] = calendar.sec;
	flash_data[6] = summer_begin_month;
	flash_data[7] = summer_begin_day;
	flash_data[8] = summer_end_month;
	flash_data[9] = summer_end_day;
	flash_data[10] = summer_begin_hour;
	flash_data[11] = summer_begin_min;
	flash_data[12] = summer_end_hour;
	flash_data[13] = summer_end_min;
	flash_data[14] = winter_begin_hour;
	flash_data[15] = winter_begin_min;
	flash_data[16] = winter_end_hour;
	flash_data[17] = winter_end_min;
}

u16 flash_data_temp[18] = {0};
//���籣����Ϣ��ʼ��
void flash_init()
{	
	int i = 0;
	STMFLASH_Read(FLASH_SAVE_ADDR,flash_data_temp,sizeof(flash_data_temp));
	RTC_Set(flash_data_temp[0],flash_data_temp[1],flash_data_temp[2],flash_data_temp[3],flash_data_temp[4],flash_data_temp[5]);
	summer_begin_month = flash_data_temp[6];
	summer_begin_day = flash_data_temp[7];
	summer_end_month = flash_data_temp[8];
	summer_end_day = flash_data_temp[9];
	summer_begin_hour = flash_data_temp[10];
	summer_begin_min = flash_data_temp[11];
	summer_end_hour = flash_data_temp[12];
	summer_end_min = flash_data_temp[13];
	winter_begin_hour = flash_data_temp[14];
	winter_begin_min = flash_data_temp[15];
	winter_end_hour = flash_data_temp[16];
	winter_end_min = flash_data_temp[17];
}