#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define STACK_INIT_SIZE 100    //定义栈的初始大小
#define STACK_INCR_SIZE 10    //定义栈的增长大小

#define MAXSIZE 100    //中缀表达式的长度

typedef struct Data
{
    int flag;    //1为字符，2为浮点数
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
    ElemType *base;    //栈底指针
    ElemType *top;    //栈顶指针
    int stackSize;    //最大容量，这是可修改的
}sqStack;

Status InitStack(sqStack *s);    //初始化操作，建立一个空栈

Status ClearStack(sqStack *s);    //将栈清空

Status StackEmpty(sqStack s);    //若栈存在，返回true，否则返回false

int StackLength(sqStack s);        //返回栈S的元素个数

Status GetTop(sqStack s, ElemType *e);    //若是栈存在且非空，用e返回S的栈顶元素

Status Push(sqStack *s, ElemType e);    // 若是栈存在，则插入新的元素e到栈S中并成为栈顶元素

Status Pop(sqStack *s, ElemType *e);    //若是栈存在且非空，删除栈顶元素，并用e返回其值

Status DestroyStack(sqStack *s);        //若是栈存在，则销毁他

void PrintStack(sqStack s);    //打印所有数据，测试用，会依次将数据出栈

//四则运算需要的函数

Status MatchBrack(char* str);    //匹配括号是否正确

Status RotateStack(sqStack* s);    //将栈中的数据翻转

Status GetMidStack(sqStack *s, char* str);    //获取中缀表达式,将字符串转换到栈中

Status GetBackStack(sqStack *s);    //获取后缀表达式

Status GetBackValue(sqStack *s, double* val);    //获取后缀表达式计算出来的结果
#endif // COMPUTER_H_INCLUDED
