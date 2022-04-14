#include <stdio.h>
#include<stdlib.h>
#include"binary_sort_tree.h"
#include"LinkStack.h"
#include"LQueue.h"

int GetNum()
{
	int i; 		
	while (scanf_s("%d", &i) != 1)
	{
		while (getchar() != '\n');
		printf("�����������������\n");
	}
	while (getchar() != '\n');
	return i;
}

//��ʼ��
Status BST_init(BinarySortTreePtr BSTP)
{
	if ((BSTP->root = (NodePtr)malloc(sizeof(Node))) == NULL)
		return ERROR;
	printf("����������ڵ����ݣ�\n");
	BSTP->root->value = GetNum();
	BSTP->root->left = NULL;
	BSTP->root->right = NULL;
	return SUCCESS;
}

//����
Status BST_insert(BinarySortTreePtr BSTP, ElemType value)
{
	NodePtr temp = BSTP->root;
	NodePtr p = (NodePtr)malloc(sizeof(Node));
	if (p == NULL)
	{
		return ERROR;
	}
	p->value = value;
	p->left = NULL;
	p->right = NULL;
	while (1)
	{
		if (value == temp->value)
		{
			printf("�������������Ѵ��ڸ�����\n");
			return ERROR;
		}
		else if (value < temp->value)					//С������
		{
			if (temp->left)
			{
				temp = temp->left;
			}
			else
			{
				temp->left = p;
				return SUCCESS;
			}
		}
		else											//�������ҿ�
		{
			if (temp->right)
			{
				temp = temp->right;
			}
			else
			{
				temp->right = p;
				return SUCCESS;
			}
		}
	}
}
	
//ɾ��
Status BST_delete(BinarySortTreePtr BSTP, ElemType value)
{
	NodePtr temp = BSTP->root;
	NodePtr pretemp = temp;
	NodePtr L = NULL, R = NULL;
	int flag = 0;		//�����ж��Ǹ�ĸ�����ӻ����Һ���
	while (1)		//��
	{
		if (value == temp->value)				//�ҵ��˽�����һ��ɾ��
		{
			break;
		}
		else if (value < temp->value)			//С������
		{
			if (temp->left)
			{
				pretemp = temp;					//��¼��һ��temp		
				temp = temp->left;
				flag = 1;
			}
			else
			{
				printf("��ö���������û�и�����\n");
				return ERROR;
			}
		}
		else									//�������ҿ�
		{
			if (temp->right)
			{
				pretemp = temp;					//��¼��һ��temp		
				temp = temp->right;
				flag = 2;
			}
			else
			{
				printf("��ö���������û�и�����\n");
				return ERROR;
			}
		}
	}
	L = temp->left;
	R = temp->right;
	free(temp);
	if (R)
	{
		if (flag == 0)		//ɾ���ڵ�Ϊ���ڵ�
			BSTP->root = R;
		else if (flag == 1)
			pretemp->left = R;
		else
			pretemp->right = R;
		while (R->left)
			R = R->left;
		R->left = L;
	}
	else if (L)
	{
		if (flag == 0)
			BSTP->root = R;
		else if (flag == 1)
			pretemp->left = L;
		else
			pretemp->right = L;
	}
	else					//ɾ���ڵ�ΪҶ�ڵ�
	{
		if (flag == 1)
			pretemp->left = NULL;
		else
			pretemp->right = NULL;
	}
	return SUCCESS;
}

//����
Status BST_search(BinarySortTreePtr BSTP, ElemType value)
{
	NodePtr temp = BSTP->root;
	while (1)
	{
		if (value == temp->value)
		{
			return SUCCESS;
		}
		else if (value < temp->value)					//С������
		{
			if (temp->left)
			{
				temp = temp->left;
			}
			else
			{
				return ERROR;
			}
		}
		else											//�������ҿ�
		{
			if (temp->right)
			{
				temp = temp->right;
			}
			else
			{
				return ERROR;
			}
		}
	}
}

//ǰ������ݹ�
Status BST_preorderI(BinarySortTreePtr BSTP, void (*visit)(NodePtr))
{
	NodePtr temp = BSTP->root;
	if (temp == NULL)
		return ERROR;
	visit(temp);
	return SUCCESS;
}

//��������ݹ�
Status BST_inorderI(BinarySortTreePtr BSTP, void (*visit)(NodePtr))
{
	NodePtr temp = BSTP->root;
	if (temp == NULL)
		return ERROR;
	visit(temp);
	return SUCCESS;
}

//��������ݹ�
Status BST_postorderI(BinarySortTreePtr BSTP, void (*visit)(NodePtr))
{
	NodePtr temp = BSTP->root;
	if (temp == NULL)
		return ERROR;
	visit(temp);
	return SUCCESS;
}

//ǰ������ǵݹ�
Status BST_preorderR(BinarySortTreePtr BSTP, void (*visit)(NodePtr))
{

	NodePtr temp = BSTP->root;
	if (temp == NULL)
		return ERROR;
	visit(temp);
	return SUCCESS;
}

//��������ǵݹ�
Status BST_inorderR(BinarySortTreePtr BSTP, void (*visit)(NodePtr))
{

	NodePtr temp = BSTP->root;
	if (temp == NULL)
		return ERROR;
	visit(temp);
	return SUCCESS;
}

//��������ǵݹ�
Status BST_postorderR(BinarySortTreePtr BSTP, void (*visit)(NodePtr))
{

	NodePtr temp = BSTP->root;
	if (temp == NULL)
		return ERROR;
	visit(temp);
	return SUCCESS;
}

//��α���
Status BST_levelOrder(BinarySortTreePtr BSTP, void (*visit)(NodePtr))
{
	NodePtr temp = BSTP->root;
	if (temp)
	{
		visit(temp);
		return SUCCESS;
	}
	else
		return ERROR;
}

Status preorderI(NodePtr temp)
{
	if (temp == NULL)
	{
		return SUCCESS;
	}
	printf("%d ", temp->value);
	preorderI(temp->left);
	preorderI(temp->right);
	return SUCCESS;
}

Status inorderI(NodePtr temp)
{
	if (temp == NULL)
	{
		return SUCCESS;
	}
	inorderI(temp->left);
	printf("%d ", temp->value);
	inorderI(temp->right);
	return SUCCESS;
}

Status postorderI(NodePtr temp)
{
	if (temp == NULL)
	{
		return SUCCESS;
	}
	postorderI(temp->left);
	postorderI(temp->right);
	printf("%d ", temp->value);
	return SUCCESS;
}

Status preorderR(NodePtr temp)
{
	LinkStack Stack = { 0 };
	initLStack(&Stack);
	pushLStack(&Stack, temp);
	while (isEmptyLStack(&Stack))
	{
		popLStack(&Stack, &temp);
		printf("%d ", temp->value);
		if (temp->right)
		{
			pushLStack(&Stack, temp->right);
		}
		if (temp->left)
		{
			pushLStack(&Stack, temp->left);
		}
	}
}

Status inorderR(NodePtr temp)
{
	LinkStack Stack = { 0 };
	initLStack(&Stack);
	pushLStack(&Stack, temp);
	do
	{
		getTopLStack(&Stack, &temp);
		while (temp->left)      //һֱ�����к��Ӿͽ�ջ
		{
			pushLStack(&Stack, temp->left);
			temp = temp->left;
		}
		popLStack(&Stack, &temp);       //��ӡ����ĺ���
		printf("%d ", temp->value);
		while (temp->right == NULL)     //��ʱtemp�ǳ�ջ�Ǹ���������û���Һ��Ӽ̳и�ҵ
		{
			if (popLStack(&Stack, &temp) == ERROR)      //����while˵��û���Һ��ӣ���ʱtempһ��ȫ���ˡ��Ǿͻ�ȡ��ջ��temp����tempһ���൱����temp������
				break;          //Ҫ��ջΪ�գ���ջʧ�������ѭ��
			printf("%d ", temp->value);
		}
		pushLStack(&Stack, temp->right);        //�Һ��Ӽ̳и�ҵ������������ܽ�һ��NULL��
	} while (temp->right != NULL);
}

Status postorderR(NodePtr temp)
{
	LinkStack Stack = { 0 };
	NodePtr e = NULL;       //��¼��һ��temp����֤�Ƿ��߹����ҵ�·
	initLStack(&Stack);
	pushLStack(&Stack, temp);
	while (isEmptyLStack(&Stack))
	{
		getTopLStack(&Stack, &temp);        //��ȡջ����temp
		if (e == temp->right && e != NULL)    //��eΪtemp���Һ��ӣ�˵���Һ����Ѿ��ҹ������temp���ҹ��Һ��ӣ���һ���ҹ����ӣ����Կ������Һ��Ӷ�û�ˣ�ΪҶ�ڵ㣩&&(e != NULL)��ֹ���ڵ�û�Һ���
		{
			popLStack(&Stack, &temp);
			printf("%d ", temp->value);
			e = temp;       //��¼��ǰtemp
			continue;       //����ѭ��
		}
		if (e != temp->left)        //��e��Ϊtemp�����ӣ�˵������û�ҹ���������
		{
			while (temp->left)      //һֱ������
			{
				pushLStack(&Stack, temp->left);
				temp = temp->left;
			}
		}
		e = temp;       //��¼��ǰtemp
		if (temp->right)        //���temp���Һ��ӣ��Һ��ӽ�ջ
		{
			pushLStack(&Stack, temp->right);
		}
		else            //û���Һ��ӣ�Ҳû�����ӣ�ֱ�ӳ�ջ����������Ӵ�ӡ��Ҳ����û�ˣ����Կ���Ҷ�ڵ㣩
		{
			popLStack(&Stack, &temp);
			printf("%d ", temp->value);
		}
	}
	return SUCCESS;

}

Status levelOrder(NodePtr temp)
{
	LQueue Queue = { 0 };
	InitLQueue(&Queue);
	EnLQueue(&Queue, temp);
	while (IsEmptyLQueue(&Queue))
	{
		GetHeadLQueue(&Queue, &temp);
		if (temp->left)
		{
			EnLQueue(&Queue, temp->left);
		}
		if (temp->right)
		{
			EnLQueue(&Queue, temp->right);
		}
		DeLQueue(&Queue);
		printf("%d ", temp->value);
	}
}