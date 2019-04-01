#include "../head/linkedList.h"

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	(*L) = (LinkedList)malloc(sizeof(LNode));
	if (!L)
        return ERROR;
    else {
         (*L)->data = 0;
        (*L)->next = NULL;
        return SUCCESS;
    }
}


Status InputList(LinkedList *L)
{
    int i;
    ElemType num;
    LinkedList p,tail,pp;
    printf("创建一个链表: 1.头插法 2.尾插法 \n输入操作选项：");
    scanf(" %d",&i);
     while(1){
 	if(i == 1)
        {
            printf("请输入整数(以 0结束):");
            scanf("%d",&num);
            while( num != 0)
            {
                p = (LinkedList)malloc(sizeof(LNode));
                p->data = num;
                p->next = (*L)->next;
                (*L)->next = p;
                scanf("%d",&num);
            }
            OutputList(L);
 			break;
        }
    else if(i == 2)
        {
            tail = (*L);
            printf("请输入整数(以 0 结束):");
            scanf("%d",&num);
            while(num != 0)
                {
                    p = (LinkedList)malloc(sizeof(LNode));
               		p->data = num;
               		tail->next = p;
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
       	    break;
        }
    else printf("输入有误,请重新输入!\n");
     }
     return SUCCESS;
}

Status OutputList(LinkedList *L)
{
    LinkedList pp;
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

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	q->next = p->next;
    p->next = q;
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    *e = p->data;
	p->data = 0;
	return SUCCESS;
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	ElemType i=0,k=0;
        LinkedList p;
        p = L->next;
        while(p != NULL)
        {
                i++;
                if((p->data) == e)
                {
                    printf("%d\t的位置是%5d\n",e,i);
                    k=1;
                    break;
                }
                p = p->next;
        }
        if(k == 0) printf("要查找的元素不存在!\n");
        return SUCCESS;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    LinkedList p,q,r;
    if ((*L)->next == NULL) return ERROR;
    else {
        p = *L;
        q = (*L)->next;
        (*L)->next = NULL;
        while(q){
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        while(p->next){
            printf("%5d",p->data);
            p = p->next;
        }
        return SUCCESS;
    }
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	LNode *fast,*slow;//快慢指针法？
    fast = slow = (*L)->next;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    LinkedList slow,fast;
	slow=fast=L->next;
    while ( fast && fast->next )
    {
        slow=slow->next;
        fast=fast->next->next;
        if ( slow == fast ) break;
    }
    if (fast==NULL||fast->next==NULL) return ERROR;
    else return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p = *L,q;
    while(p->next!=NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    printf("销毁成功!\n");
}
