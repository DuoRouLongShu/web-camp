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
    if (status == SUCCESS) printf("�ѳ�ʼ��һ������������������˵�\n");
    else if (status == ERROR) {
        printf("��ʼ�������˳�����\n");
        exit(-1);
    }
    InputList(&L);
    while (1){
        printf(" 1.����\n 2.ɾ��\n 3.����\n 4.�ҵ��������е�\n 5.�жϳɻ�\n 6.��ת������ż���ڵ�(δ���)\n 7.��ת\n 8.ע��\n 9.�˳�\n");
        printf("������������ţ�");
        scanf("%d",&i);
        if (i == 1){
            p = L;
            k = 0;
            printf("����������λ�úͲ������:");
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
            printf("������Ҫɾ���Ľ�㣺");
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
            printf("��ɾ��Ԫ��Ϊ��%d\n������Ϊ",e);
            OutputList(&L);
        }
        else if (i == 3){
            printf("������������ҵ�����");
            scanf("%d",&e);
            SearchList(L,e);
        }
        else if(i == 4){
            printf("�����е�Ϊ��%d",FindMidNode(&L)->data);
            printf("\n");
        }
        else if(i == 5){
            status = IsLoopList(L);
            if (status == ERROR) printf("���ɻ���\n");
            else if (status == SUCCESS) printf("�ɻ�!\n");
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
        else printf("����������������룡\n");
    }
    return 0;
}
