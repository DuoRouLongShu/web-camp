#include "../head/SqStack.h"
#include<stdio.h>

//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)
{
    s->elem = (ElemType *)malloc(sizes*sizeof(int));
    if (!s){
        printf("初始化失败！");
        return ERROR;
    }
    else{
        s->size = sizes;
        s->top = -1;
        return SUCCESS;
    }
}  //初始化栈

Status pushStack(SqStack *s,ElemType data){
    if (s->top == s->size - 1){
        return ERROR;
    }
    else{
        s->top++;
        *(s->elem + s->top) = data;
        return SUCCESS;
    }
}  //入栈

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
}   //出栈

Status getTopStack(SqStack *s,ElemType *e)
{
    if (s->top == -1)
        return ERROR;
    else{
        *e = *(s->elem + s->top);
        return SUCCESS;
    }
}   //得到栈顶元素

Status isEmptyStack(SqStack *s)   //判断栈是否为空
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
}   //检测栈长度

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
}   //清空栈

Status destroyStack(SqStack *s)
{
    free(s->elem);
}  //销毁栈


