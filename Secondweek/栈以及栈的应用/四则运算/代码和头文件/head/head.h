#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define STACK_INIT_SIZE 100    //����ջ�ĳ�ʼ��С
#define STACK_INCR_SIZE 10    //����ջ��������С

#define MAXSIZE 100    //��׺���ʽ�ĳ���

typedef struct Data
{
    int flag;    //1Ϊ�ַ���2Ϊ������
    union
    {
        double num;
        char sign;
    }number;
}data;

typedef data ElemType;
typedef int Status;

typedef struct
{
    ElemType *base;    //ջ��ָ��
    ElemType *top;    //ջ��ָ��
    int stackSize;    //������������ǿ��޸ĵ�
}sqStack;

Status InitStack(sqStack *s);    //��ʼ������������һ����ջ

Status ClearStack(sqStack *s);    //��ջ���

Status StackEmpty(sqStack s);    //��ջ���ڣ�����true�����򷵻�false

int StackLength(sqStack s);        //����ջS��Ԫ�ظ���

Status GetTop(sqStack s, ElemType *e);    //����ջ�����ҷǿգ���e����S��ջ��Ԫ��

Status Push(sqStack *s, ElemType e);    // ����ջ���ڣ�������µ�Ԫ��e��ջS�в���Ϊջ��Ԫ��

Status Pop(sqStack *s, ElemType *e);    //����ջ�����ҷǿգ�ɾ��ջ��Ԫ�أ�����e������ֵ

Status DestroyStack(sqStack *s);        //����ջ���ڣ���������

void PrintStack(sqStack s);    //��ӡ�������ݣ������ã������ν����ݳ�ջ

//����������Ҫ�ĺ���

Status MatchBrack(char* str);    //ƥ�������Ƿ���ȷ

Status RotateStack(sqStack* s);    //��ջ�е����ݷ�ת

Status GetMidStack(sqStack *s, char* str);    //��ȡ��׺���ʽ,���ַ���ת����ջ��

Status GetBackStack(sqStack *s);    //��ȡ��׺���ʽ

Status GetBackValue(sqStack *s, double* val);    //��ȡ��׺���ʽ��������Ľ��
#endif // COMPUTER_H_INCLUDED
