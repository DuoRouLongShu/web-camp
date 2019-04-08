#include"../head/AQueue.h"

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
    for (int i = 0;i < MAXQUEUE;i ++ )
        Q->data[i] = (void *)malloc(Q->length);
    Q->front = 0;
    Q->rear = 0;
}

/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
    int i;
    for (i = 0;i<MAXQUEUE;i ++ )
        free(Q->data[i]);
}

/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
    return((Q->rear+1)%MAXQUEUE == Q->front?TRUE : FALSE);
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
    return((Q->front == Q->rear?TRUE : FALSE));
}

/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
    if (Q->front == Q->rear)
        return FALSE;
    else
    {
        int i = Q->front;
        i = (i + 1) % MAXQUEUE;
        memcpy(e,Q->data[i],Q->length);
        return TRUE;
    }
}

/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
    return (Q->rear-Q->front+MAXQUEUE)%MAXQUEUE;
}

/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data)
{
    if ((Q->rear+1)%MAXQUEUE == Q->front)
        return FALSE;
    else
    {
        Q->rear = (Q->rear+1) % MAXQUEUE;
        memcpy(Q->data[Q->rear],data,Q->length);
        return TRUE;
    }
}

/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
    if (Q->front == Q->rear)
        return FALSE;
    else
    {
        Q->front = (Q->front+1) % MAXQUEUE;
        return TRUE;
    }
}

/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}

/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{

}

/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q,int size)
{
    if (size == 1)
		printf("%d\t", *(int *)q);
    if (size == 2)
		printf("%c\t", *(char *)q);
    if (size == 3)
		printf("%ld\t", *(long int *)q);
    if (size == 4)
		printf("%f\t", *(float *)q);
    if (size == 5)
		printf("%lf\t", *(double *)q);
}
