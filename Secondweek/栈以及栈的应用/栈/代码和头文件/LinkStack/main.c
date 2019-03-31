#include<stdio.h>
#include<stdlib.h>
#include "LinkStack.c"
#include "../head/LinkStack.h"
int main(void)
{
    LinkStack s;
    ElemType num,data,e;
    int i,length;
    Status status;
    if (initLStack(&s) == ERROR){
        printf("初始化错误！退出程序！\n");
        exit(-1);
    }
    else printf("链栈初始化成功，键入程序菜单\n");
    while (1){
        printf("\t----------------程序操作菜单--------------------\n\t------------------1、入栈-----------------------\n\t------------------2、出栈-----------------------\n\t------------------3、得到栈顶元素---------------\n\t------------------4、判断栈是否为空-------------\n\t------------------5、检测栈长度-----------------\n\t------------------6、清空栈---------------------\n\t------------------7、销毁栈---------------------\n\t------------------8、退出-----------------------\n\n");
        printf("请输入操作单号：");
        scanf("%d",&i);
        if (i == 1){
                printf("请输入入栈元素（整数）：");
                scanf("%d",&num);
                if (pushLStack(&s,num) == SUCCESS) printf("入栈成功！\n");
        }
        else if (i == 2){
            status = popLStack(&s,&data);
            if (status == SUCCESS) printf("出栈成功，出栈元素为：%d\n",data);
            else if(status == ERROR) printf("栈已空！\n");
        }
        else if (i == 3){
            status = getTopLStack(&s,&e);
            if (status == SUCCESS) printf("栈顶元素为：%d\n",e);
            else if(status == ERROR) printf("栈顶为空！\n");
        }
        else if (i == 4){
            status = isEmptyLStack(&s);
            if (status == SUCCESS) printf("栈为空！\n");
            else if(status == ERROR) printf("栈不为空！\n");
        }
        else if (i == 5){
            status = LStackLength(&s,&length);
            if (status == SUCCESS) printf("栈长度为：%d\n",length);
            else if(status == ERROR) printf("栈为空！\n");
        }
        else if (i == 6){
            status = clearLStack(&s);
            if (status == SUCCESS) printf("栈已清空！\n");
            else if(status == ERROR) printf("栈为空！\n");
        }
        else if (i == 7){
            destroyLStack(&s);
            printf("销毁成功！\n");
            printf("-------------1、重新初始化栈\n-------------2、退出程序\n请输入操作选项：");
            scanf("%d",&i);
                if (i == 1)
                    {
                        if (initLStack(&s) == ERROR)
                        {
                            printf("请重新检查输入！\n");
                            exit(-1);
                        }//初始化操作！
                    }
                if (i == 2) exit(-1);
        }
        else if (i == 8) exit(-1);
        else printf("输入错误，请重新输入！\n");
    }
    return 0;
}
