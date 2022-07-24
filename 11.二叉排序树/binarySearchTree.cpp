#include "binarySearchTree.h"

TreeNode* bstSearch(TreeNode* T, int data)
{
	if (T)
	{
		if (T->data == data)
		{
			return T;
		}
		else if (data < T->data) 
		{
			return bstSearch(T->lchild, data);
		}
		else 
		{
			return bstSearch(T->rchild, data);
		}
	}
	else
	{
		return NULL;
	}
}

void bstInsert(TreeNode** T, int data)
{
	if (*T == NULL) 
	{
		*T = (TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data = data;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
	}
	else if (data == (*T)->data) 
	{
		return;
	}
	else if (data < (*T)->data)
	{
		bstInsert(&((*T)->lchild), data);
	}
	else
	{
		bstInsert(&((*T)->rchild), data);
	}
}

void preOrder(TreeNode* T) 
{
	if (T) 
	{
		printf("%d ", T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}
void inOrder(TreeNode* T)
{
	if (T)
	{
		preOrder(T->lchild);
		printf("%d ", T->data);
		preOrder(T->rchild);
	}
}


void test01()
{
	TreeNode* T = NULL;
	int nums[6] = { 4, 5, 19, 23, 2, 8 };
	for (int i = 0; i < 6; i++) 
	{
		bstInsert(&T, nums[i]);
	}
	preOrder(T);
	printf("\n");
	inOrder(T);
	printf("\n");
}

int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;

}