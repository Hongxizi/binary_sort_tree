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
		printf("输入错误，请重新输入\n");
	}
	while (getchar() != '\n');
	return i;
}

//初始化
Status BST_init(BinarySortTreePtr BSTP)
{
	if ((BSTP->root = (NodePtr)malloc(sizeof(Node))) == NULL)
		return ERROR;
	printf("请先输入根节点数据：\n");
	BSTP->root->value = GetNum();
	BSTP->root->left = NULL;
	BSTP->root->right = NULL;
	return SUCCESS;
}

//插入
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
			printf("二叉排序树中已存在该数据\n");
			return ERROR;
		}
		else if (value < temp->value)					//小于往左看
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
		else											//大于往右看
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
	
//删除
Status BST_delete(BinarySortTreePtr BSTP, ElemType value)
{
	NodePtr temp = BSTP->root;
	NodePtr pretemp = temp;
	NodePtr L = NULL, R = NULL;
	int flag = 0;		//用来判断是父母的左孩子还是右孩子
	while (1)		//找
	{
		if (value == temp->value)				//找到了进入下一步删除
		{
			break;
		}
		else if (value < temp->value)			//小于往左看
		{
			if (temp->left)
			{
				pretemp = temp;					//记录上一个temp		
				temp = temp->left;
				flag = 1;
			}
			else
			{
				printf("这棵二叉排序树没有该数据\n");
				return ERROR;
			}
		}
		else									//大于往右看
		{
			if (temp->right)
			{
				pretemp = temp;					//记录上一个temp		
				temp = temp->right;
				flag = 2;
			}
			else
			{
				printf("这棵二叉排序树没有该数据\n");
				return ERROR;
			}
		}
	}
	L = temp->left;
	R = temp->right;
	free(temp);
	if (R)
	{
		if (flag == 0)		//删除节点为根节点
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
	else					//删除节点为叶节点
	{
		if (flag == 1)
			pretemp->left = NULL;
		else
			pretemp->right = NULL;
	}
	return SUCCESS;
}

//查找
Status BST_search(BinarySortTreePtr BSTP, ElemType value)
{
	NodePtr temp = BSTP->root;
	while (1)
	{
		if (value == temp->value)
		{
			return SUCCESS;
		}
		else if (value < temp->value)					//小于往左看
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
		else											//大于往右看
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

//前序遍历递归
Status BST_preorderI(BinarySortTreePtr BSTP, void (*visit)(NodePtr))
{
	NodePtr temp = BSTP->root;
	if (temp == NULL)
		return ERROR;
	visit(temp);
	return SUCCESS;
}

//中序遍历递归
Status BST_inorderI(BinarySortTreePtr BSTP, void (*visit)(NodePtr))
{
	NodePtr temp = BSTP->root;
	if (temp == NULL)
		return ERROR;
	visit(temp);
	return SUCCESS;
}

//后序遍历递归
Status BST_postorderI(BinarySortTreePtr BSTP, void (*visit)(NodePtr))
{
	NodePtr temp = BSTP->root;
	if (temp == NULL)
		return ERROR;
	visit(temp);
	return SUCCESS;
}

//前序遍历非递归
Status BST_preorderR(BinarySortTreePtr BSTP, void (*visit)(NodePtr))
{

	NodePtr temp = BSTP->root;
	if (temp == NULL)
		return ERROR;
	visit(temp);
	return SUCCESS;
}

//中序遍历非递归
Status BST_inorderR(BinarySortTreePtr BSTP, void (*visit)(NodePtr))
{

	NodePtr temp = BSTP->root;
	if (temp == NULL)
		return ERROR;
	visit(temp);
	return SUCCESS;
}

//后序遍历非递归
Status BST_postorderR(BinarySortTreePtr BSTP, void (*visit)(NodePtr))
{

	NodePtr temp = BSTP->root;
	if (temp == NULL)
		return ERROR;
	visit(temp);
	return SUCCESS;
}

//层次遍历
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
		while (temp->left)      //一直向左，有孩子就进栈
		{
			pushLStack(&Stack, temp->left);
			temp = temp->left;
		}
		popLStack(&Stack, &temp);       //打印最左的孩子
		printf("%d ", temp->value);
		while (temp->right == NULL)     //这时temp是出栈那个，看看有没有右孩子继承父业
		{
			if (popLStack(&Stack, &temp) == ERROR)      //进入while说明没有右孩子，此时temp一家全完了。那就获取从栈新temp；老temp一家相当于新temp的左孩子
				break;          //要是栈为空，出栈失败则结束循环
			printf("%d ", temp->value);
		}
		pushLStack(&Stack, temp->right);        //右孩子继承父业，（最后好像可能进一个NULL）
	} while (temp->right != NULL);
}

Status postorderR(NodePtr temp)
{
	LinkStack Stack = { 0 };
	NodePtr e = NULL;       //记录上一个temp，验证是否走过左右的路
	initLStack(&Stack);
	pushLStack(&Stack, temp);
	while (isEmptyLStack(&Stack))
	{
		getTopLStack(&Stack, &temp);        //获取栈顶给temp
		if (e == temp->right && e != NULL)    //若e为temp的右孩子，说明右孩子已经找过，输出temp（找过右孩子，就一定找过左孩子，可以看作左右孩子都没了，为叶节点）&&(e != NULL)防止根节点没右孩子
		{
			popLStack(&Stack, &temp);
			printf("%d ", temp->value);
			e = temp;       //记录当前temp
			continue;       //重新循环
		}
		if (e != temp->left)        //若e不为temp的左孩子，说明左孩子没找过，找左孩子
		{
			while (temp->left)      //一直往左找
			{
				pushLStack(&Stack, temp->left);
				temp = temp->left;
			}
		}
		e = temp;       //记录当前temp
		if (temp->right)        //如果temp有右孩子，右孩子进栈
		{
			pushLStack(&Stack, temp->right);
		}
		else            //没有右孩子，也没有左孩子，直接出栈，输出（左孩子打印完也看作没了，可以看作叶节点）
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