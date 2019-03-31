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
    printf("׼����ʼ��˳��洢ջ��������˳��洢ջ�ĳ��� size=");
    scanf("%d",&size);
    if (initStack(&s,size) == 0)
    {
        printf("�����¼�����룡\n");
        exit(-1);
    }//��ʼ��������
    while (1){
        printf("\t----------------��������˵�--------------------\n\t------------------1����ջ-----------------------\n\t------------------2����ջ-----------------------\n\t------------------3���õ�ջ��Ԫ��---------------\n\t------------------4���ж�ջ�Ƿ�Ϊ��-------------\n\t------------------5�����ջ����-----------------\n\t------------------6�����ջ---------------------\n\t------------------7������ջ---------------------\n\t------------------8���˳�-----------------------\n\n");
        printf("������������ţ�");
        scanf("%d",&i);
        if (i == 1){
            if(s.top == size-1) printf("ջ������\n");
            else {
                printf("��������ջԪ�أ���������");
                scanf("%d",&num);
                if (pushStack(&s,num) == SUCCESS) printf("��ջ�ɹ���\n");
            }
        }
        else if (i == 2){
            status = popStack(&s,&data);
            if (status == SUCCESS) printf("��ջ�ɹ�����ջԪ��Ϊ��%d\n",data);
            else if(status == ERROR) printf("ջ�ѿգ�\n");
        }
        else if (i == 3){
            status = getTopStack(&s,&e);
            if (status == SUCCESS) printf("ջ��Ԫ��Ϊ��%d\n",e);
            else if(status == ERROR) printf("ջ��Ϊ�գ�\n");
        }
        else if (i == 4){
            status = isEmptyStack(&s);
            if (status == SUCCESS) printf("ջ��Ϊ�գ�\n");
            else if(status == ERROR) printf("ջΪ�գ�\n");
        }
        else if (i == 5){
            status = stackLength(&s,&length);
            if (status == SUCCESS) printf("ջ����Ϊ��%d\n",length);
            else if(status == ERROR) printf("ջΪ�գ�\n");
        }
        else if (i == 6){
            status = clearStack(&s);
            if (status == SUCCESS) printf("ջ����գ�\n");
            else if(status == ERROR) printf("ջΪ�գ�\n");
        }
        else if (i == 7){
            destroyStack(&s);
            printf("���ٳɹ���\n");
            printf("-------------1�����³�ʼ��ջ\n-------------2���˳�����\n���������ѡ�");
            scanf("%d",&i);
                if (i == 1)
                    {
                        if (initStack(&s,size) == 0)
                        {
                            printf("�����¼�����룡\n");
                            exit(-1);
                        }//��ʼ��������
                        continue;
                    }
                    if (i == 2) exit(-1);
        }
        else if (i == 8) exit(-1);
        else printf("����������������룡\n");
    }
    return 0;
}
