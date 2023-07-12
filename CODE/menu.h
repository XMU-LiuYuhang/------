#ifndef _MENU_H_
#define _MENU_H_
#include "stm32f10x.h"


extern int mode_flag; //ģʽ��־λ 0Ϊʱ����ƣ�1Ϊ�ֶ����ƣ�2Ϊ���߿���
extern int seasonmenu_flag; //���ڲ˵���־λ 0Ϊ����ʾ��1Ϊ��ʾ

void ChangeMode();
void DrawMenu();
void DrawTimeMenu();
void DrawLightMenu();
void DrawManualMenu();
void DrawLight(u16 x,u16 y);
void DrawKeyboard(u16 x,u16 y,u16 w,u16 h);
void DrawKey(u16 x,u16 y,u16 w,u16 h,u8 *str);
void DrawSeasonMenu();
void SetRun();


#endif // _MENU_H_