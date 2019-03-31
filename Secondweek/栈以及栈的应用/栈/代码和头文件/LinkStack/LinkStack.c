#include "../head/LinkStack.h"

//��ջ(���������)
Status initLStack(LinkStack *s)
{
    if (!s)
        return ERROR;
    else{
        s->count = 0;
        return SUCCESS;
    }
}   //��ʼ��

Status isEmptyLStack(LinkStack *s)
{
    if (s->count == 0)
        return SUCCESS;
    else return ERROR;
}  //�ж���ջ�Ƿ�Ϊ��

Status getTopLStack(LinkStack *s,ElemType *e)
{
    if (isEmptyLStack(s) == SUCCESS)
        return ERROR;
    else{
        *e = s->top->data;
        return SUCCESS;
    }
}  //�õ�ջ��Ԫ��

Status clearLStack(LinkStack *s)
{
    LinkStackPtr p;
    if (isEmptyLStack(s) == SUCCESS)
        return ERROR;
    else{
        while(s->count != 0){
            p = s->top;
            s->top = s->top->next;
            p->data = 0;
            s->count--;
        }
        return SUCCESS;
    }
}   //���ջ

Status destroyLStack(LinkStack *s)
{
    LinkStackPtr p;
    if (isEmptyLStack(s) == SUCCESS)
        return ERROR;
    else{
        while(s->count != 0){
            p = s->top;
            s->top = s->top->next;
            free(p);
            s->count--;
        }
        return SUCCESS;
    }
}   //����ջ

Status LStackLength(LinkStack *s,int *length)
{
    if (isEmptyLStack(s) == SUCCESS)
        return ERROR;
    else{
        *length = s->count;
        return SUCCESS;
    }
}    //���ջ����

Status pushLStack(LinkStack *s,ElemType data)
{
    LinkStackPtr S = (LinkStackPtr)malloc(sizeof(StackNode));
    S->data = data;
    S->next = s->top;
    s->top = S;
    s->count++;
    return SUCCESS;
}   //��ջ

Status popLStack(LinkStack *s,ElemType *data)
{
    LinkStackPtr p;
    if (isEmptyLStack(s) == SUCCESS)
        return ERROR;
    else{
        *data = s->top->data;
        p = s->top;
        s->top = s->top->next;
        free(p);
        s->count--;
        return SUCCESS;
    }
}   //��ջ
