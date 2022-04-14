#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LQueue.h" 

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	LQNode* head = (LQNode*)malloc(sizeof(LQNode));
	while (head == NULL)
	{
		head = (Node*)malloc(sizeof(Node));
	}
	Q->front =  head;
	Q->rear = head;
	head->next = NULL;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
//void DestoryLQueue(LQueue *Q)
//{
//	LQNode* p = Q->front;
//	while (p)
//	{
//		Q->front = p->next;
//		free(p);
//		p = Q->front;
//	}
//	Q->rear = NULL;
//	Q->length = 0;
//	detimes = 0;
//}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if (Q->front == Q->rear)
		return FALSE;			//Ϊ�շ���0
	else
		return TRUE;			//��Ϊ�շ���1
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue* Q, LQNode** e)
{
	if (!IsEmptyLQueue(Q))
		return FALSE;
	*e = Q->front->next->data;		//�޸�
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
//int LengthLQueue(LQueue *Q)
//{
//	return Q->length;
//}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue* Q, NodePtr data)
{
	LQNode* p = (LQNode*)malloc(sizeof(LQNode));
	if (p == NULL)
		return FALSE;
	p->data = data;		//�޸�
	Q->rear->next = p;
	Q->rear = p;
	Q->length++;
	p->next = NULL;
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
	if (!IsEmptyLQueue(Q))
		return FALSE;
	LQNode* p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	Q->length--; 
	detimes++;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
//void ClearLQueue(LQueue *Q)
//{
//	LQNode* p = Q->front->next;
//	while (p)
//	{
//		Q->front->next = p->next;
//		free(p);
//		p = Q->front->next;
//	}	
//	Q->rear = Q->front;
//	Q->length = 0;
//	detimes = 0;
//}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
//Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
//{
//	LQNode* p = Q->front->next;
//	if (IsEmptyLQueue(Q))
//		return FALSE;
//	while (p) 
//	{
//		foo(p->data);
//		p = p->next;
//	}
//	printf("\n");
//	return TRUE;
//}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
//void LPrint(void *q)
//{
//	 int pprint = detimes;
//	if (datatype[pprint] == 'i')
//	{
//		printf("%d  ", *(int*)q);
//		pprint++;
//	}
//	else if (datatype[pprint] == 'd')
//	{
//		printf("%.2f  ", *(double*)q);
//		pprint++;
//	}
//	else if (datatype[pprint] == 'c')
//	{
//		printf("%c  ", *(char*)q);
//		pprint++;
//	}
//}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
// LQUEUE_H_INCLUDED


