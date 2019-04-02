#include "../head/duLinkedList.h"
#include<stdlib.h>
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    (*L) = (DuLinkedList)malloc(sizeof(DuLNode));
	if (!L)
        return ERROR;
    else {
         (*L)->data = 0;
        (*L)->prior = NULL;
        (*L)->next = NULL;
        return SUCCESS;
    }
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList p = *L,q;
    while(p->next!=NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    printf("销毁成功!\n");
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    p->prior->next = q;
    q->next = p;
    q->prior = p->prior;
    p->prior = q;
    return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    q->next = p->next;
    p->next = q;
    q->prior = q->next->prior;
    q->next->prior = q;
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    *e = p->data;
	p->data = 0;
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {

}

Status inputList_DuL(DuLinkedList *L)
{
    DuLinkedList tail,p,pp;
    ElemType num;
    tail = (*L);
            printf("请输入整数(以 0 结束):");
            scanf("%d",&num);
            while(num != 0)
                {
                    p = (DuLinkedList)malloc(sizeof(DuLNode));
               		p->data = num;
               		tail->next = p;
               		p->prior = tail;
                	tail = p;
                	scanf("%d",&num);
       		    }
        	tail->next = NULL;
        	pp =  (*L)->next;
        	printf("操作结果是:");
       		while(pp != NULL)
        	{
                printf("%5d",pp->data);
                pp = pp->next;
        	}
        	printf("\n");
        	return SUCCESS;
}

Status OutputList_DuL(DuLinkedList *L)
{
    DuLinkedList pp;
    pp = (*L)->next;
            printf("操作结果是:");
             while(pp != NULL)
            {
                printf("%5d",pp->data);
                pp = pp->next;
            }
            printf("\n");
    return SUCCESS;
}
