#include "AQueue.c"
#include "LQueue.c"
int main(void)
{
    int e1,n,i,j,k,type,flag=1;
    char e2;
    long int e3;
    float e4;
    double e5;
    void *elem[5] = {&e1,&e2,&e3,&e4,&e5};
    Status status = TRUE;
    printf("\t-----------ѡ�����-----------\n\t--------1��˳�����-----------\n\t--------2����ʽ����-----------\n##����ѡ�");
    scanf("%d",&n);
    if (n == 1)
    {
        AQueue Q;
        printf("ѡ��˳������������ͣ�1������\t2���ַ���\t3��������\t4��������\t5��double��\n");
        scanf("%d",&type);
        switch (type)
        {
            case 1:Q.length = 4;break;
            case 2:Q.length = 1;break;
            case 3:Q.length = 8;break;
            case 4:Q.length = 4;break;
            case 5:Q.length = 8;break;
            default:{printf("error!\n");exit(-1);}
        }
        InitAQueue(&Q);
        printf("\t-----��ʼ��˳����У�����˵�----\n\n");
        while(1)
        {
            menu(n);
            scanf("%d",&j);
            if (j == 1){
                printf("�������Ԫ�أ�ÿ����һ�����س�������");
                if (IsFullAQueue(&Q) == TRUE) {printf("����������\n");continue;}
                switch (type)
                {
                    case 1:scanf("%d",&e1);if (EnAQueue(&Q,&e1) == FALSE) printf("����������\n"); else printf("��ӳɹ���\n");continue;
                    case 2:getchar();scanf("%c",&e2);if (EnAQueue(&Q,&e2) == FALSE) printf("����������\n");else printf("��ӳɹ���\n");continue;
                    case 3:scanf("%ld",&e3);if (EnAQueue(&Q,&e3) == FALSE) printf("����������\n"); else printf("��ӳɹ���\n");continue;
                    case 4:scanf("%f",&e4);if (EnAQueue(&Q,&e4) == FALSE) printf("����������\n"); else printf("��ӳɹ���\n");continue;
                    case 5:scanf("%lf",&e5);if (EnAQueue(&Q,&e5) == FALSE) printf("����������\n"); else printf("��ӳɹ���\n");continue;
                    default:printf("error!\n");exit(-1);
                }
            }
            else if (j == 2){
                status = DeAQueue(&Q);
                if(status == FALSE) printf("����Ϊ�գ�\n");
                else if (status == TRUE) printf("���ӳɹ���\n");
            }
            else if (j == 3){
                if (IsEmptyAQueue(&Q) == TRUE) printf("��Ϊ�գ�\n");
                else printf("�Ӳ�Ϊ�գ�\n");
            }
            else if (j == 4){
                    GetHeadAQueue(&Q,elem[type+1]);
                    APrint(elem[type+1],type);
                    printf("\n");
            }
            else if (j == 5){
                printf("���г���Ϊ��%d\n",LengthAQueue(&Q));
            }
            else if (j == 6){
                status = IsFullAQueue(&Q);
                if (status == TRUE) printf("˳�����������\n");
                else printf("˳�����δ����\n");
            }
            else if (j == 7){
                ClearAQueue(&Q);
                printf("��������գ�\n");
            }
            else if (j == 8){
                DestoryAQueue(&Q);
                printf("���������٣�\n");
            }
            else if (j == 9){
                printf("δ��ɣ�\n");
            }
            else if (j == 10){
                if (IsEmptyAQueue(&Q) == TRUE) printf("��Ϊ�գ�\n");
                else
                    {
                        flag = 1;
                        i = Q.front+1;
                        while ((i <= (MAXQUEUE - Q.front + Q.rear) % MAXQUEUE) && (flag<10)) {
                        APrint(Q.data[i],type);
                        i = (i + 1) % MAXQUEUE;
                        flag++;
                        }
                        printf("\n");
                    }
            }
            else if (j == 11){
                exit(-1);
            }
            else {
                printf("�����������������룡\n");
            }
        }
    }
    else if (n == 2)
    {
        LQueue Q;
        printf("ѡ����ʽ�����������ͣ�1������\t2���ַ���\t3��������\t4��������\t5��double��\n");
        scanf("%d",&type);
        switch (type)
        {
            case 1:Q.length = 4;break;
            case 2:Q.length = 1;break;
            case 3:Q.length = 8;break;
            case 4:Q.length = 4;break;
            case 5:Q.length = 8;break;
            default:{printf("error!\n");exit(-1);}
        }
        InitLQueue(&Q);
        printf("\t-----��ʼ����ʽ���У�����˵�-----\n\n");
        while(1)
        {
            menu(n);
            scanf("%d",&j);
            if (j == 1){
                printf("�������Ԫ�أ�ÿ����һ�����س�������");
                switch (type)
                {
                    case 1:scanf("%d",&e1);EnLQueue(&Q,&e1);printf("��ӳɹ���\n");continue;
                    case 2:getchar();scanf("%c",&e2);EnLQueue(&Q,&e2);printf("��ӳɹ���\n");continue;
                    case 3:scanf("%ld",&e3);EnLQueue(&Q,&e3);printf("��ӳɹ���\n");continue;
                    case 4:scanf("%f",&e4);EnLQueue(&Q,&e4);printf("��ӳɹ���\n");continue;
                    case 5:scanf("%lf",&e5);EnLQueue(&Q,&e5);printf("��ӳɹ���\n");continue;
                    default:printf("error!\n");exit(-1);
                }
            }
            else if (j == 2){
                status = DeLQueue(&Q);
                if(status == FALSE) printf("����Ϊ�գ�\n");
                else if (status == TRUE) printf("���ӳɹ���\n");
            }
            else if (j == 3){
                if (IsEmptyLQueue(&Q) == TRUE) printf("��Ϊ�գ�\n");
                else printf("�Ӳ�Ϊ�գ�\n");
            }
            else if (j == 4){
                GetHeadLQueue(&Q,elem[type+1]);
                APrint(elem[type+1],type);
                printf("\n");
            }
            else if (j == 5){
                printf("���г���Ϊ��%d\n",LengthLQueue(&Q));
            }
            else if (j == 6){
                ClearLQueue(&Q);
                printf("��������գ�\n");
            }
            else if (j == 7){
                DestoryLQueue(&Q);
                printf("���������٣�\n");
            }
            else if (j == 8){
                printf("δ��ɣ�\n");
            }
            else if (j == 9){
                if (IsEmptyLQueue(&Q) == TRUE) printf("��Ϊ�գ�\n");
                else
                    {
                        Node* p = (void *)malloc(Q.length);
                        p = Q.front->next;
                        while (p != NULL) {
                            APrint(p->data,type);
                            p = p->next;
                        }
                        printf("\n");
                    }
            }
            else if (j == 10){
                exit(-1);
            }
            else {
                printf("�����������������룡\n");
            }
         }
    }
    return 0;
}
