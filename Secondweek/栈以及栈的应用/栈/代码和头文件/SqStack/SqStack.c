#include "../head/SqStack.h"
#include<stdio.h>

//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)
{
    s->elem = (ElemType *)malloc(sizes*sizeof(int));
    if (!s){
        printf("��ʼ��ʧ�ܣ�");
        return ERROR;
    }
    else{
        s->size = sizes;
        s->top = -1;
        return SUCCESS;
    }
}  //��ʼ��ջ

Status pushStack(SqStack *s,ElemType data){
    if (s->top == s->size - 1){
        return ERROR;
    }
    else{
        s->top++;
        *(s->elem + s->top) = data;
        return SUCCESS;
    }
}  //��ջ

Status popStack(SqStack *s,ElemType *data)
{
    if (s->top == -1){
        return ERROR;
    }
    else {
        *data = *(s->elem + s->top);
        s->top--;
        return SUCCESS;
    }
}   //��ջ

Status getTopStack(SqStack *s,ElemType *e)
{
    if (s->top == -1)
        return ERROR;
    else{
        *e = *(s->elem + s->top);
        return SUCCESS;
    }
}   //�õ�ջ��Ԫ��

Status isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
    if(s->top == -1)
        return ERROR;
    else return SUCCESS;
}

Status stackLength(SqStack *s,int *length)
{
    if (s->top == -1)
        return ERROR;
    else{
        *length = s->top + 1;
        return SUCCESS;
    }
}   //���ջ����

Status clearStack(SqStack *s)
{
    if (s->top == -1)
        return ERROR;
    else{
        while (s->top != -1){
            *(s->elem + s->top) = 0;
            s->top--;
        }
        return SUCCESS;
    }
}   //���ջ

Status destroyStack(SqStack *s)
{
    free(s->elem);
}  //����ջ


