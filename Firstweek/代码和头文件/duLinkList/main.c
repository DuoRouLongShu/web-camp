#include<stdio.h>
#include "duLinkedList.c"
int main(void)
{
    DuLinkedList L,q,p;
    Status status;
    int i,j,k,location;
    ElemType e,Insertnum;
    status = InitList_DuL(&L);
    if (status == SUCCESS) printf("已初始化一个双向链表，创建双向链表\n");
    else if (status == ERROR) {
        printf("初始化错误，退出程序！\n");
        exit(-1);
    }
    inputList_DuL(&L);
     while (1){
        printf(" 1.结点前插入\n 2.结点后插入\n 3.删除\n 4.注销\n 5.退出\n");
        printf("请输入操作单号：");
        scanf("%d",&i);
        if (i == 1){
            p = L->next;
            k = 0;
            printf("请输入结点前插入的位置和插入的数:");
            scanf("%d%d",&location,&Insertnum);
            q = (DuLinkedList )malloc(sizeof(DuLNode));
            q->data = Insertnum;
            do{
                    k ++;
                    if(k == location)
                    {
                        InsertBeforeList_DuL(p,q);
                        break;
                    }
                    p = p->next;
            }while(p != NULL);
            OutputList_DuL(&L);
        }
        else if (i == 2){
            p = L->next;
            k = 0;
            printf("请输入结点后插入的位置和插入的数:");
            scanf("%d%d",&location,&Insertnum);
            q = (DuLinkedList )malloc(sizeof(DuLNode));
            q->data = Insertnum;
            do{
                    k ++;
                    if(k == location)
                    {
                        InsertAfterList_DuL(p,q);
                        break;
                    }
                    p = p->next;
            }while(p != NULL);
            OutputList_DuL(&L);
        }
        else if (i == 3){
            printf("输入想要删除的结点：");
            scanf("%d",&j);
            p = L->next;
            k = 0;
            do{
                    k ++;
                    if(k == j)
                    {
                        DeleteList_DuL(p,&e);
                        break;
                    }
                    p = p->next;
            }while(p != NULL);
            printf("被删除元素为：%d\n新链表为",e);
            OutputList_DuL(&L);
        }
        else if(i == 4){
            DestroyList_DuL(&L);
            exit(-1);
        }
        else if (i == 5) exit(-1);
        else printf("输入错误，请重新输入！\n");
    }
    return 0;
}


