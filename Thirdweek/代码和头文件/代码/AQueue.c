#include"../head/AQueue.h"

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
    return((Q->rear+1)%MAXQUEUE == Q->front?TRUE : FALSE);
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
    return((Q->front == Q->rear?TRUE : FALSE));
}

/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
    return (Q->rear-Q->front+MAXQUEUE)%MAXQUEUE;
}

/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}

/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{

}

/**
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
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
