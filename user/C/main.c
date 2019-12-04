/************************ (C) COPYRIGHT 2013 yang_yulei ************************
* File Name          : main.cpp
* Author             : yang_yulei
* Date First Issued  : 1/16/2012
* Description        : �������� VC++ 6.0 ��EasyXͼ�ο�(http://www.easyx.cn)
*                      ����˹����
*                      
*                      
********************************************************************************
* History:
*  1/16/2012 : V0.1
* 12/18/2013 : V0.2
********************************************************************************
* 
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "head.h"
#include <windows.h>
#include <dos.h>
 
/* Typedef -------------------------------------------------------------------*/
/* Variables -----------------------------------------------------------------*/
//ȫ�ֱ���-��Ϸ���״̬����(����ʾ��ǰ������Щλ���з���)
//0��ʾû�У�1��ʾ��(��������к����У��γ�һ��Χǽ�������жϷ����Ƿ��ܹ��ƶ�)
char g_gameBoard[Y_ROCK_SQUARE_NUM+2][X_ROCK_SQUARE_NUM+2] = {0} ;
//ͳ�Ʒ���
int  g_score = 0 ; 
//�ȼ�
int  g_grade = 0 ;
 
int  g_rockTypeNum = 0 ; //���ж����ֶ���˹����
RockType rockArray[50] = {(0,0)} ;
 
/*******************************************************************************
* Function Name  : main
* Description    : Main program
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
int
main(void)
{
    //������Ϸ����
    initgraph(WINDOW_WIDTH, WINDOW_HIGH) ; //��ʼ��ͼ�δ���
    cleardevice() ;
    DrawGameGUI() ; 
 
    //ʹ�� API �����޸Ĵ�������
    HWND hWnd = GetHWnd();
    SetWindowText(hWnd, "����˹����");
 
    //��ʼ������
    InitProcParameters() ;
 
    //��Ϸ����
    PlayGame()    ;
    
    closegraph()    ;
    return 0 ;
}

