#include<stdio.h>
#include "duLinkedList.c"
int main(void)
{
    DuLinkedList L,q,p;
    Status status;
    int i,j,k,location;
    ElemType e,Insertnum;
    status = InitList_DuL(&L);
    if (status == SUCCESS) printf("�ѳ�ʼ��һ��˫����������˫������\n");
    else if (status == ERROR) {
        printf("��ʼ�������˳�����\n");
        exit(-1);
    }
    inputList_DuL(&L);
     while (1){
        printf(" 1.���ǰ����\n 2.�������\n 3.ɾ��\n 4.ע��\n 5.�˳�\n");
        printf("������������ţ�");
        scanf("%d",&i);
        if (i == 1){
            p = L->next;
            k = 0;
            printf("��������ǰ�����λ�úͲ������:");
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
            printf("�������������λ�úͲ������:");
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
            printf("������Ҫɾ���Ľ�㣺");
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
            printf("��ɾ��Ԫ��Ϊ��%d\n������Ϊ",e);
            OutputList_DuL(&L);
        }
        else if(i == 4){
            DestroyList_DuL(&L);
            exit(-1);
        }
        else if (i == 5) exit(-1);
        else printf("����������������룡\n");
    }
    return 0;
}


