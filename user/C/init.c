/************************ (C) COPYRIGHT 2013 yang_yulei ************************
* File Name          : init.cpp
* Author             : yang_yulei
* Date First Issued  : 12/18/2013
* Description        :
*
********************************************************************************
*
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "head.h"

/* Variables -----------------------------------------------------------------*/
extern char g_gameBoard[][X_ROCK_SQUARE_NUM + 2] ;
extern int  g_rockTypeNum ;
extern RockType rockArray[] ;

/* Function prototypes -------------------------------------------------------*/
static int ReadRockShape(void) ;
static unsigned int ShapeStr2uInt(char *const);

/*******************************************************************************
* Function Name  : InitProcParameters
* Description    : ����ʽ��ʼ������Ϸǰ����ʼ��һЩ������g_gameBoard
                   �������ļ��ж�ȡϵͳ�ж���˹�������״
* Be called      : main
* Input          : None
* Output         : g_gameBoard rockArray
* Return         : None
*******************************************************************************/
//��ʼ���������
int InitProcParameters(void)
{
    int  i ;

    //��ʼ����Ϸ��(�������ά�����������1,����Χǽ,�����жϱ߽�)
    for (i = 0; i < X_ROCK_SQUARE_NUM + 2; i++)
    {
        g_gameBoard[0][i] = 1 ;
        g_gameBoard[Y_ROCK_SQUARE_NUM + 1][i] = 1 ;
    }
    for (i = 0; i < Y_ROCK_SQUARE_NUM + 2; i++)
    {
        g_gameBoard[i][0] = 1 ;
        g_gameBoard[i][X_ROCK_SQUARE_NUM + 1] = 1 ;
    }

    //�������ļ��ж�ȡ��Ϸ�����з������״����
    ReadRockShape() ;

    return 0 ;
}

/*******************************************************************************
* Function Name  : ReadRockShape
* Description    : �������ļ��ж�ȡϵͳ�ж���˹�������״ ������¼��rockArray��
* Be called      : InitProcParameters
* Input          : rockshape.ini
* Output         : rockArray
* Return         : �ɹ�����0 ʧ�ܷ���1
*******************************************************************************/
int ReadRockShape(void)
{
    FILE *fp ;
    int  i = 0 ;
    int  len = 0 ;
    int  rockArrayIdx = 0 ;
    int  shapeNumPerRock = 0 ; //һ�ַ������̬��Ŀ(���ڼ��㷽���nextRockIndex)

    char rdBuf[128] ;
    char rockShapeBitsStr[128] = {0};

    unsigned int  shapeBits = 0 ;

    g_rockTypeNum  = 0 ;

    //�������ļ� ���ж�ȡ�������״
    fp = fopen(".\\rockshape.ini", "r") ;
    if (fp == NULL)
    {
        perror("open file error!\n") ;
        return 1 ;
    }

    while (fgets(rdBuf, 128, fp) != NULL)
    {
        len = strlen(rdBuf) ;
        rdBuf[len - 1] = '\0' ;

        switch (rdBuf[0])
        {
            case '@':
            case '#':
                strcat(rockShapeBitsStr, rdBuf) ;
                break ;

            case 0 : //һ�������ȡ����
                shapeBits = ShapeStr2uInt(rockShapeBitsStr) ;
                rockShapeBitsStr[0] = 0 ;
                shapeNumPerRock++ ;
                rockArray[rockArrayIdx].rockShapeBits = shapeBits ;
                rockArray[rockArrayIdx].nextRockIndex = rockArrayIdx + 1 ;
                rockArrayIdx++ ;
                g_rockTypeNum++ ; //��¼����������ȫ�ֱ���+1
                break ;

            case '-'://һ�ַ����ȡ����(������nextRockIndexֵ)
                rockArray[rockArrayIdx - 1].nextRockIndex = rockArrayIdx - shapeNumPerRock ;
                shapeNumPerRock = 0 ;
                break ;

            default :
                break ;
        }
    }//while()

    return 0 ;
}

/*******************************************************************************
* Function Name  : ShapeStr2uInt
* Description    : �������ļ��е�����������״���ַ��� ת��Ϊ unsigned int��
* Be called      :
* Input          : shapeStr ����������״���ַ���(���ļ��ж�ȡ��)
* Output         : None
* Return         : unsigned int�͵ķ�����״����(�����16λ��ʾ)
*******************************************************************************/
unsigned int ShapeStr2uInt(char *const shapeStr)
{
    unsigned int  shapeBitsRet = 0 ;
    char *p = shapeStr ;

    for (p += 15; p >= shapeStr; p--)
    {
        if (*p == '@')
        {
            shapeBitsRet |= ((unsigned int)1 << (&shapeStr[15] - p)) ;
        }
    }

    return shapeBitsRet ;
}

