#include<stdio.h>
#include<stdlib.h>
#include "linkedList.c"
int main(void)
{
    LinkedList L,p,q;
    Status status;
    int location,Insertnum,k=0,i,j=0;
    ElemType e;
    status = InitList(&L);
    if (status == SUCCESS) printf("已初始化一个单向链表，键入操作菜单\n");
    else if (status == ERROR) {
        printf("初始化错误，退出程序！\n");
        exit(-1);
    }
    InputList(&L);
    while (1){
        printf(" 1.插入\n 2.删除\n 3.查找\n 4.找到单链表中点\n 5.判断成环\n 6.反转单链表偶数节点(未完成)\n 7.反转\n 8.注销\n 9.退出\n");
        printf("请输入操作单号：");
        scanf("%d",&i);
        if (i == 1){
            p = L;
            k = 0;
            printf("请输入插入的位置和插入的数:");
            scanf("%d%d",&location,&Insertnum);
            q = (LinkedList )malloc(sizeof(LNode));
            q->data = Insertnum;
            do{
                    k ++;
                    if(k == location)
                    {
                        InsertList(p,q);
                        break;
                    }
                    p = p->next;
            }while(p != NULL);
            OutputList(&L);
        }
        else if (i == 2){
            printf("输入想要删除的结点：");
            scanf("%d",&j);
            p = L->next;
            k = 0;
            do{
                    k ++;
                    if(k == j)
                    {
                        DeleteList(p,&e);
                        break;
                    }
                    p = p->next;
            }while(p != NULL);
            printf("被删除元素为：%d\n新链表为",e);
            OutputList(&L);
        }
        else if (i == 3){
            printf("请输入你想查找的数：");
            scanf("%d",&e);
            SearchList(L,e);
        }
        else if(i == 4){
            printf("链表中点为：%d",FindMidNode(&L)->data);
            printf("\n");
        }
        else if(i == 5){
            status = IsLoopList(L);
            if (status == ERROR) printf("不成环！\n");
            else if (status == SUCCESS) printf("成环!\n");
        }
        else if (i == 7){
            ReverseList(&L);
            printf("\n");
        }
        else if(i == 8){
            DestroyList(&L);
            exit(-1);
        }
        else if (i == 9) exit(-1);
        else printf("输入错误，请重新输入！\n");
    }
    return 0;
}
