#ifndef _LIGHT_H_
#define _LIGHT_H_
#include "headfile.h"

extern int summer_begin_month;//����ʱ��ʼ�·�
extern int summer_end_month;//����ʱ�����·�
extern int summer_begin_day;//����ʱ��ʼ����
extern int summer_end_day;//����ʱ��������

extern int summer_begin_hour;//�ļ�·�ƿ���Сʱ
extern int summer_end_hour;//�ļ�·�ƹر�Сʱ
extern int summer_begin_min;//�ļ�·�ƿ�������
extern int summer_end_min;//�ļ�·�ƹرշ���

extern int winter_begin_hour;//����·�ƿ���Сʱ
extern int winter_end_hour;//����·�ƹر�Сʱ
extern int winter_begin_min;//����·�ƿ�������
extern int winter_end_min;//����·�ƹرշ���

extern int season_flag;//���ڱ�־λ 0Ϊ����ʱ��1Ϊ����ʱ 

extern light_flag;//·�ƿ��ر�־λ 0Ϊ�أ�1Ϊ��

void Show_light();
void Show_light_value();
void Control_time_light();
void Control_light_light();
void Light_up();
void Light_down();

#endif /* _LIGHT_H_ */