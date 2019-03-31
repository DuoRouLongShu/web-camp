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
        printf("��ʼ�������˳�����\n");
        exit(-1);
    }
    else printf("��ջ��ʼ���ɹ����������˵�\n");
    while (1){
        printf("\t----------------��������˵�--------------------\n\t------------------1����ջ-----------------------\n\t------------------2����ջ-----------------------\n\t------------------3���õ�ջ��Ԫ��---------------\n\t------------------4���ж�ջ�Ƿ�Ϊ��-------------\n\t------------------5�����ջ����-----------------\n\t------------------6�����ջ---------------------\n\t------------------7������ջ---------------------\n\t------------------8���˳�-----------------------\n\n");
        printf("������������ţ�");
        scanf("%d",&i);
        if (i == 1){
                printf("��������ջԪ�أ���������");
                scanf("%d",&num);
                if (pushLStack(&s,num) == SUCCESS) printf("��ջ�ɹ���\n");
        }
        else if (i == 2){
            status = popLStack(&s,&data);
            if (status == SUCCESS) printf("��ջ�ɹ�����ջԪ��Ϊ��%d\n",data);
            else if(status == ERROR) printf("ջ�ѿգ�\n");
        }
        else if (i == 3){
            status = getTopLStack(&s,&e);
            if (status == SUCCESS) printf("ջ��Ԫ��Ϊ��%d\n",e);
            else if(status == ERROR) printf("ջ��Ϊ�գ�\n");
        }
        else if (i == 4){
            status = isEmptyLStack(&s);
            if (status == SUCCESS) printf("ջΪ�գ�\n");
            else if(status == ERROR) printf("ջ��Ϊ�գ�\n");
        }
        else if (i == 5){
            status = LStackLength(&s,&length);
            if (status == SUCCESS) printf("ջ����Ϊ��%d\n",length);
            else if(status == ERROR) printf("ջΪ�գ�\n");
        }
        else if (i == 6){
            status = clearLStack(&s);
            if (status == SUCCESS) printf("ջ����գ�\n");
            else if(status == ERROR) printf("ջΪ�գ�\n");
        }
        else if (i == 7){
            destroyLStack(&s);
            printf("���ٳɹ���\n");
            printf("-------------1�����³�ʼ��ջ\n-------------2���˳�����\n���������ѡ�");
            scanf("%d",&i);
                if (i == 1)
                    {
                        if (initLStack(&s) == ERROR)
                        {
                            printf("�����¼�����룡\n");
                            exit(-1);
                        }//��ʼ��������
                    }
                if (i == 2) exit(-1);
        }
        else if (i == 8) exit(-1);
        else printf("����������������룡\n");
    }
    return 0;
}
