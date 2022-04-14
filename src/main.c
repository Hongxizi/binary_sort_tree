#include <stdio.h>
#include<stdlib.h>
#include"binary_sort_tree.h"


//int main() 
//{
//    BinarySortTree Tree = { 0 };
//    BST_init(&Tree);
//    BST_insert(&Tree, 13);
//    BST_insert(&Tree, 2);
//    BST_insert(&Tree, 5);
//    BST_insert(&Tree, 3);
//    BST_insert(&Tree, 45);
//    BST_insert(&Tree, 43);
//    //BST_delete(&Tree, 5);
//
//    //int i = BST_search(&Tree, 5);
//    //printf("%d", i);
//
//    void* visit = preorderI;
//    BST_preorderI(&Tree, visit);
//    printf("\n");
//    visit = inorderI;
//    BST_inorderI(&Tree, visit);
//    printf("\n");
//    visit = postorderI;
//    BST_postorderI(&Tree, visit);
//    printf("\n");
//
//    printf("\n");
//
//    visit = preorderR;
//    BST_preorderR(&Tree, visit);
//    printf("\n");
//    visit = inorderR;
//    BST_inorderI(&Tree, visit);
//    printf("\n");
//    visit = postorderR;
//    BST_postorderR(&Tree, visit);
//    printf("\n");
//
//    printf("\n");
//
//    visit = levelOrder;
//    BST_levelOrder(&Tree, visit);
//    printf("\n");
//    return 0;
//}

int GetRight(int swi);
void menu();


int main()
{
	BinarySortTree Tree = { 0 };
	int i;
	int flag = 0;
	int value = 0;
	void* visit = NULL;
	while (1)
	{
		system("cls");
		menu();
		i = GetRight(0);
		while (i > 9 || i < 0)
		{
			printf("输入错误，请输入0-9的指令\n");
			i = GetRight(0);
		}
		if (flag == 0 && i != 0)
		{
			printf("二叉树未初始化，请先初始化\n");
			system("pause");
			continue;
		}
		switch (i)
		{
		case 0:
		{
			flag = BST_init(&Tree);
			if (flag)
				printf("初始化成功\n");
			else
				printf("初始化失败\n");
			break;
		}
		case 1:
		{
			printf("请输入要插入的值：\n");
			value = GetRight(0);
			if (BST_insert(&Tree, value))
				printf("插入成功\n");
			else
				printf("插入失败\n");
			break;
		}
		case 2:
		{
			printf("请输入要删除的值：\n");
			value = GetRight(0);
			if (BST_delete(&Tree, value))
				printf("插入成功\n");
			else
				printf("插入失败\n"); 
			break;
		}
		case 3:
		{
			printf("请输入要查找的值：\n");
			value = GetRight(0);
			if (BST_search(&Tree, value))
			{
				printf("排序二叉树中存在该数据\n");
			}
			else
			{
				printf("排序二叉树中不存在该数据\n");
			}
			break;
		}
		case 4:
		{
			visit = preorderI;
			if (BST_preorderI(&Tree, visit))
			{
				printf("\n前序遍历成功\n");
			}
			else
			{
				printf("前序遍历失败\n");
			}
			break;
		}
		case 5:
		{
			visit = inorderI;
			if (BST_inorderI(&Tree, visit))
			{
				printf("\n中序遍历成功\n");
			}
			else
			{
				printf("中序遍历失败\n");
			}
			break;
		}
		case 6:
		{
			visit = postorderI;
			if (BST_postorderI(&Tree, visit))
			{
				printf("\n后序遍历成功\n");
			}
			else
			{
				printf("后序遍历失败\n");
			}
			break;
		}
		case 7:
		{
			visit = preorderR;
			if (BST_preorderR(&Tree, visit))
			{
				printf("\n前序遍历成功\n");
			}
			else
			{
				printf("前序遍历失败\n");
			}
			break;
		}
		case 8:
		{
			visit = inorderR;
			if (BST_inorderR(&Tree, visit))
			{
				printf("\n中序遍历成功\n");
			}
			else
			{
				printf("中序遍历失败\n");
			}
			break;
		}
		case 9:
		{
			visit = postorderR;
			if (BST_postorderR(&Tree, visit))
			{
				printf("\n后序遍历成功\n");
			}
			else
			{
				printf("后序遍历失败\n");
			}
			break;
		}
		}
		system("pause");
	}
	return 0;
}

	int GetRight(int swi)
	{
		int ret;
		int i;
		ret = scanf_s("%d", &i);
		while (ret != 1 || (swi && i < 0))			//swi相当于一个开关，当swi为1时开关开启，需判断i是否小于0；当swi为0时则不用判断
		{
			while (getchar() != '\n');
			printf("输入错误，请重新输入\n");
			ret = scanf_s("%d", &i);
		}
		while (getchar() != '\n');
		return i;
	}

	void menu()
	{
		printf("---------------------\n");
		printf("0.初始化\n");
		printf("1.插入\n");
		printf("2.删除\n");
		printf("3.查找\n");
		printf("4.前序遍历（递归）\n");
		printf("5.中序遍历（递归）\n");
		printf("6.后序遍历（递归）\n");
		printf("7.前序遍历（非递归）\n");
		printf("8.中序遍历（非递归）\n");
		printf("9.后序遍历（非递归）\n");
		printf("---------------------\n");
		printf("请输入菜单指令：\n");
	}