#include "../head/LQueue.h"

void menu(int a)
{
    if (a == 1)
    {
        printf("\t---------------------------------\n\t-\t1�����\t\t\t-\n\t-\t2������\t\t\t-\n\t-\t3���������Ƿ�Ϊ��\t-\n");
        printf("\t-\t4���鿴��ͷԪ��\t\t-\n");
        printf("\t-\t5��ȷ�����г���\t\t-\n");
        printf("\t-\t6��˳������Ƿ�����-\n");
        printf("\t-\t7����ն���\t\t-\n");
        printf("\t-\t8�����ٶ���\t\t-\n");
        printf("\t-\t9����������\t\t-\n");
        printf("\t-\t10����ӡ����\t\t-\n");
        printf("\t-\t11���˳�\t\t-\n");
        printf("\t----------------------------------\n");
        printf("�������ѡ��ţ�");
    }
    else if (a == 2)
    {
        printf("\t---------------------------------\n\t-\t1�����\t\t\t-\n\t-\t2������\t\t\t-\n\t-\t3���������Ƿ�Ϊ��\t-\n");
        printf("\t-\t4���鿴��ͷԪ��\t\t-\n");
        printf("\t-\t5��ȷ�����г���\t\t-\n");
        printf("\t-\t6����ն���\t\t-\n");
        printf("\t-\t7�����ٶ���\t\t-\n");
        printf("\t-\t8����������\t\t-\n");
        printf("\t-\t9����ӡ����\t\t-\n");
        printf("\t-\t10���˳�\t\t-\n");
        printf("\t----------------------------------\n");
        printf("�������ѡ��ţ�");
    }
}
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
    return (Q->front == Q->rear? TRUE : FALSE);
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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
