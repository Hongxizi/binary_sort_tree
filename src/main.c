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
			printf("�������������0-9��ָ��\n");
			i = GetRight(0);
		}
		if (flag == 0 && i != 0)
		{
			printf("������δ��ʼ�������ȳ�ʼ��\n");
			system("pause");
			continue;
		}
		switch (i)
		{
		case 0:
		{
			flag = BST_init(&Tree);
			if (flag)
				printf("��ʼ���ɹ�\n");
			else
				printf("��ʼ��ʧ��\n");
			break;
		}
		case 1:
		{
			printf("������Ҫ�����ֵ��\n");
			value = GetRight(0);
			if (BST_insert(&Tree, value))
				printf("����ɹ�\n");
			else
				printf("����ʧ��\n");
			break;
		}
		case 2:
		{
			printf("������Ҫɾ����ֵ��\n");
			value = GetRight(0);
			if (BST_delete(&Tree, value))
				printf("����ɹ�\n");
			else
				printf("����ʧ��\n"); 
			break;
		}
		case 3:
		{
			printf("������Ҫ���ҵ�ֵ��\n");
			value = GetRight(0);
			if (BST_search(&Tree, value))
			{
				printf("����������д��ڸ�����\n");
			}
			else
			{
				printf("����������в����ڸ�����\n");
			}
			break;
		}
		case 4:
		{
			visit = preorderI;
			if (BST_preorderI(&Tree, visit))
			{
				printf("\nǰ������ɹ�\n");
			}
			else
			{
				printf("ǰ�����ʧ��\n");
			}
			break;
		}
		case 5:
		{
			visit = inorderI;
			if (BST_inorderI(&Tree, visit))
			{
				printf("\n��������ɹ�\n");
			}
			else
			{
				printf("�������ʧ��\n");
			}
			break;
		}
		case 6:
		{
			visit = postorderI;
			if (BST_postorderI(&Tree, visit))
			{
				printf("\n��������ɹ�\n");
			}
			else
			{
				printf("�������ʧ��\n");
			}
			break;
		}
		case 7:
		{
			visit = preorderR;
			if (BST_preorderR(&Tree, visit))
			{
				printf("\nǰ������ɹ�\n");
			}
			else
			{
				printf("ǰ�����ʧ��\n");
			}
			break;
		}
		case 8:
		{
			visit = inorderR;
			if (BST_inorderR(&Tree, visit))
			{
				printf("\n��������ɹ�\n");
			}
			else
			{
				printf("�������ʧ��\n");
			}
			break;
		}
		case 9:
		{
			visit = postorderR;
			if (BST_postorderR(&Tree, visit))
			{
				printf("\n��������ɹ�\n");
			}
			else
			{
				printf("�������ʧ��\n");
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
		while (ret != 1 || (swi && i < 0))			//swi�൱��һ�����أ���swiΪ1ʱ���ؿ��������ж�i�Ƿ�С��0����swiΪ0ʱ�����ж�
		{
			while (getchar() != '\n');
			printf("�����������������\n");
			ret = scanf_s("%d", &i);
		}
		while (getchar() != '\n');
		return i;
	}

	void menu()
	{
		printf("---------------------\n");
		printf("0.��ʼ��\n");
		printf("1.����\n");
		printf("2.ɾ��\n");
		printf("3.����\n");
		printf("4.ǰ��������ݹ飩\n");
		printf("5.����������ݹ飩\n");
		printf("6.����������ݹ飩\n");
		printf("7.ǰ��������ǵݹ飩\n");
		printf("8.����������ǵݹ飩\n");
		printf("9.����������ǵݹ飩\n");
		printf("---------------------\n");
		printf("������˵�ָ�\n");
	}