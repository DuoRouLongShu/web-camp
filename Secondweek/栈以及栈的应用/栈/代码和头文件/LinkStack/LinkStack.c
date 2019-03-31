#include "../head/LinkStack.h"

//链栈(基于链表的)
Status initLStack(LinkStack *s)
{
    if (!s)
        return ERROR;
    else{
        s->count = 0;
        return SUCCESS;
    }
}   //初始化

Status isEmptyLStack(LinkStack *s)
{
    if (s->count == 0)
        return SUCCESS;
    else return ERROR;
}  //判断链栈是否为空

Status getTopLStack(LinkStack *s,ElemType *e)
{
    if (isEmptyLStack(s) == SUCCESS)
        return ERROR;
    else{
        *e = s->top->data;
        return SUCCESS;
    }
}  //得到栈顶元素

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
}   //清空栈

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
}   //销毁栈

Status LStackLength(LinkStack *s,int *length)
{
    if (isEmptyLStack(s) == SUCCESS)
        return ERROR;
    else{
        *length = s->count;
        return SUCCESS;
    }
}    //检测栈长度

Status pushLStack(LinkStack *s,ElemType data)
{
    LinkStackPtr S = (LinkStackPtr)malloc(sizeof(StackNode));
    S->data = data;
    S->next = s->top;
    s->top = S;
    s->count++;
    return SUCCESS;
}   //入栈

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
}   //出栈
