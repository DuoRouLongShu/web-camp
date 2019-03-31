#include<stdio.h>
#include<stdlib.h>
#include "SqStack.c"
#include "../head/SqStack.h"
int main(void)
{
    SqStack s;
    ElemType size,num,data,e;
    int i,length;
    Status status;
    printf("准备初始化顺序存储栈，请输入顺序存储栈的长度 size=");
    scanf("%d",&size);
    if (initStack(&s,size) == 0)
    {
        printf("请重新检查输入！\n");
        exit(-1);
    }//初始化操作！
    while (1){
        printf("\t----------------程序操作菜单--------------------\n\t------------------1、入栈-----------------------\n\t------------------2、出栈-----------------------\n\t------------------3、得到栈顶元素---------------\n\t------------------4、判断栈是否为空-------------\n\t------------------5、检测栈长度-----------------\n\t------------------6、清空栈---------------------\n\t------------------7、销毁栈---------------------\n\t------------------8、退出-----------------------\n\n");
        printf("请输入操作单号：");
        scanf("%d",&i);
        if (i == 1){
            if(s.top == size-1) printf("栈已满！\n");
            else {
                printf("请输入入栈元素（整数）：");
                scanf("%d",&num);
                if (pushStack(&s,num) == SUCCESS) printf("入栈成功！\n");
            }
        }
        else if (i == 2){
            status = popStack(&s,&data);
            if (status == SUCCESS) printf("出栈成功，出栈元素为：%d\n",data);
            else if(status == ERROR) printf("栈已空！\n");
        }
        else if (i == 3){
            status = getTopStack(&s,&e);
            if (status == SUCCESS) printf("栈顶元素为：%d\n",e);
            else if(status == ERROR) printf("栈顶为空！\n");
        }
        else if (i == 4){
            status = isEmptyStack(&s);
            if (status == SUCCESS) printf("栈不为空！\n");
            else if(status == ERROR) printf("栈为空！\n");
        }
        else if (i == 5){
            status = stackLength(&s,&length);
            if (status == SUCCESS) printf("栈长度为：%d\n",length);
            else if(status == ERROR) printf("栈为空！\n");
        }
        else if (i == 6){
            status = clearStack(&s);
            if (status == SUCCESS) printf("栈已清空！\n");
            else if(status == ERROR) printf("栈为空！\n");
        }
        else if (i == 7){
            destroyStack(&s);
            printf("销毁成功！\n");
            printf("-------------1、重新初始化栈\n-------------2、退出程序\n请输入操作选项：");
            scanf("%d",&i);
                if (i == 1)
                    {
                        if (initStack(&s,size) == 0)
                        {
                            printf("请重新检查输入！\n");
                            exit(-1);
                        }//初始化操作！
                        continue;
                    }
                    if (i == 2) exit(-1);
        }
        else if (i == 8) exit(-1);
        else printf("输入错误，请重新输入！\n");
    }
    return 0;
}
