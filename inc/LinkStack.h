#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include"binary_sort_tree.h"

//typedef enum Status 
//{
//    ERROR = 0, 
//	SUCCESS = 1
//} Status;

typedef NodePtr ElemType1;

typedef struct StackNode
{
	ElemType1 data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//��ջ
Status initLStack(LinkStack *s);//��ʼ��ջ
Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack* s, ElemType1* e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack *s);//���ջ
Status destroyLStack(LinkStack *s);//����ջ
Status LStackLength(LinkStack* s, ElemType* length);//���ջ����
Status pushLStack(LinkStack* s, ElemType1 data);//��ջ
Status popLStack(LinkStack* s, ElemType1* data);//��ջ


#endif 
