#include "../head/LQueue.h"

void menu(int a)
{
    if (a == 1)
    {
        printf("\t---------------------------------\n\t-\t1、入队\t\t\t-\n\t-\t2、出队\t\t\t-\n\t-\t3、检查队列是否为空\t-\n");
        printf("\t-\t4、查看队头元素\t\t-\n");
        printf("\t-\t5、确定队列长度\t\t-\n");
        printf("\t-\t6、顺序队列是否已满-\n");
        printf("\t-\t7、清空队列\t\t-\n");
        printf("\t-\t8、销毁队列\t\t-\n");
        printf("\t-\t9、遍历函数\t\t-\n");
        printf("\t-\t10、打印队列\t\t-\n");
        printf("\t-\t11、退出\t\t-\n");
        printf("\t----------------------------------\n");
        printf("输入操作选项号：");
    }
    else if (a == 2)
    {
        printf("\t---------------------------------\n\t-\t1、入队\t\t\t-\n\t-\t2、出队\t\t\t-\n\t-\t3、检查队列是否为空\t-\n");
        printf("\t-\t4、查看队头元素\t\t-\n");
        printf("\t-\t5、确定队列长度\t\t-\n");
        printf("\t-\t6、清空队列\t\t-\n");
        printf("\t-\t7、销毁队列\t\t-\n");
        printf("\t-\t8、遍历函数\t\t-\n");
        printf("\t-\t9、打印队列\t\t-\n");
        printf("\t-\t10、退出\t\t-\n");
        printf("\t----------------------------------\n");
        printf("输入操作选项号：");
    }
}
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    p->next = NULL;
    Q->front = p;
    Q->rear = p;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
    if (IsEmptyLQueue(Q))
		return;
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
    return (Q->front == Q->rear? TRUE : FALSE);
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
    if (IsEmptyLQueue(Q) == TRUE)
        return FALSE;
    else
    {
        memcpy(e,Q->front->next->data,Q->length);
        return TRUE;
    }
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
    Node *p;
    int l;
    p = Q->front;
    for (l=0;p != Q->rear;l++)
        p = p->next;
    return l;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data)
{
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    p->data = (void*)malloc(Q->length);
    memcpy(p->data,data,Q->length);
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
    Node *p;
    if (IsEmptyLQueue(Q) == TRUE)
        return FALSE;
    p = Q->front->next;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->front = Q->rear;
    free(p);
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
    Node *p,*q;
	Q->rear = Q->front;
	p = Q->front->next;
	while (NULL != p) {
		q = p;
		p = p->next;
		free(q);
	}
}
