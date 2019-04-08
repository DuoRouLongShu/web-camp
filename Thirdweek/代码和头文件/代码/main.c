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
    printf("\t-----------选择队列-----------\n\t--------1、顺序队列-----------\n\t--------2、链式队列-----------\n##输入选项：");
    scanf("%d",&n);
    if (n == 1)
    {
        AQueue Q;
        printf("选择顺序队列数据类型：1、整型\t2、字符型\t3、长整型\t4、浮点型\t5、double型\n");
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
        printf("\t-----初始化顺序队列，键入菜单----\n\n");
        while(1)
        {
            menu(n);
            scanf("%d",&j);
            if (j == 1){
                printf("输入入队元素，每输入一个按回车结束：");
                if (IsFullAQueue(&Q) == TRUE) {printf("队列已满！\n");continue;}
                switch (type)
                {
                    case 1:scanf("%d",&e1);if (EnAQueue(&Q,&e1) == FALSE) printf("队列已满！\n"); else printf("入队成功！\n");continue;
                    case 2:getchar();scanf("%c",&e2);if (EnAQueue(&Q,&e2) == FALSE) printf("队列已满！\n");else printf("入队成功！\n");continue;
                    case 3:scanf("%ld",&e3);if (EnAQueue(&Q,&e3) == FALSE) printf("队列已满！\n"); else printf("入队成功！\n");continue;
                    case 4:scanf("%f",&e4);if (EnAQueue(&Q,&e4) == FALSE) printf("队列已满！\n"); else printf("入队成功！\n");continue;
                    case 5:scanf("%lf",&e5);if (EnAQueue(&Q,&e5) == FALSE) printf("队列已满！\n"); else printf("入队成功！\n");continue;
                    default:printf("error!\n");exit(-1);
                }
            }
            else if (j == 2){
                status = DeAQueue(&Q);
                if(status == FALSE) printf("队列为空！\n");
                else if (status == TRUE) printf("出队成功！\n");
            }
            else if (j == 3){
                if (IsEmptyAQueue(&Q) == TRUE) printf("队为空！\n");
                else printf("队不为空！\n");
            }
            else if (j == 4){
                    GetHeadAQueue(&Q,elem[type+1]);
                    APrint(elem[type+1],type);
                    printf("\n");
            }
            else if (j == 5){
                printf("队列长度为：%d\n",LengthAQueue(&Q));
            }
            else if (j == 6){
                status = IsFullAQueue(&Q);
                if (status == TRUE) printf("顺序队列已满！\n");
                else printf("顺序队列未满！\n");
            }
            else if (j == 7){
                ClearAQueue(&Q);
                printf("队列已清空！\n");
            }
            else if (j == 8){
                DestoryAQueue(&Q);
                printf("队列已销毁！\n");
            }
            else if (j == 9){
                printf("未完成！\n");
            }
            else if (j == 10){
                if (IsEmptyAQueue(&Q) == TRUE) printf("队为空！\n");
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
                printf("输入有误，请重新输入！\n");
            }
        }
    }
    else if (n == 2)
    {
        LQueue Q;
        printf("选择链式队列数据类型：1、整型\t2、字符型\t3、长整型\t4、浮点型\t5、double型\n");
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
        printf("\t-----初始化链式队列，键入菜单-----\n\n");
        while(1)
        {
            menu(n);
            scanf("%d",&j);
            if (j == 1){
                printf("输入入队元素，每输入一个按回车结束：");
                switch (type)
                {
                    case 1:scanf("%d",&e1);EnLQueue(&Q,&e1);printf("入队成功！\n");continue;
                    case 2:getchar();scanf("%c",&e2);EnLQueue(&Q,&e2);printf("入队成功！\n");continue;
                    case 3:scanf("%ld",&e3);EnLQueue(&Q,&e3);printf("入队成功！\n");continue;
                    case 4:scanf("%f",&e4);EnLQueue(&Q,&e4);printf("入队成功！\n");continue;
                    case 5:scanf("%lf",&e5);EnLQueue(&Q,&e5);printf("入队成功！\n");continue;
                    default:printf("error!\n");exit(-1);
                }
            }
            else if (j == 2){
                status = DeLQueue(&Q);
                if(status == FALSE) printf("队列为空！\n");
                else if (status == TRUE) printf("出队成功！\n");
            }
            else if (j == 3){
                if (IsEmptyLQueue(&Q) == TRUE) printf("队为空！\n");
                else printf("队不为空！\n");
            }
            else if (j == 4){
                GetHeadLQueue(&Q,elem[type+1]);
                APrint(elem[type+1],type);
                printf("\n");
            }
            else if (j == 5){
                printf("队列长度为：%d\n",LengthLQueue(&Q));
            }
            else if (j == 6){
                ClearLQueue(&Q);
                printf("队列已清空！\n");
            }
            else if (j == 7){
                DestoryLQueue(&Q);
                printf("队列已销毁！\n");
            }
            else if (j == 8){
                printf("未完成！\n");
            }
            else if (j == 9){
                if (IsEmptyLQueue(&Q) == TRUE) printf("队为空！\n");
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
                printf("输入有误，请重新输入！\n");
            }
         }
    }
    return 0;
}
