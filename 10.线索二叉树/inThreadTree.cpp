#include "inThreadTree.h"
//////////////////////////////////////////////////////////////////////////
//�������
void createTree(TreeNode** T, char* data, int* index)
{
	char ch;
	ch = data[*index];
	*index += 1;
	if (ch == '#') {
		// ��ʱΪ�սڵ�
		*T = NULL;
	}
	else {
		// ��ʱ��Ϊ��
		*T = (TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		(*T)->ltag = 0;
		(*T)->rtag = 0;
		// �������������߼�һ�£����еݹ�
		createTree(&((*T)->lchild), data, index);
		// �������������߼�һ�£����еݹ�
		createTree(&((*T)->rchild), data, index);
	}
}

void inThreadTree(TreeNode* T, TreeNode** pre)
{
	if (T)
	{
		inThreadTree(T->lchild, pre);

		if (T->lchild == NULL)
		{
			T->ltag = 1;
			T->lchild = *pre;
		}
		if (*pre != NULL && (*pre)->rchild == NULL)
		{
			(*pre)->rtag = 1;
			(*pre)->rchild = T;
		}
		*pre = T;
		inThreadTree(T->rchild, pre);
	}
}

TreeNode* getFirst_in(TreeNode* T)
{
	while (T->ltag == 0)
		T = T->lchild;
	return T;
}

TreeNode* getNext_in(TreeNode* node)
{
	if (node->rtag == 1)
		return node->rchild;
	else
		return getFirst_in(node->rchild);
}



void test01()
{
	TreeNode* T;
	TreeNode* pre = NULL;
	int index = 0;
	char * data = "ABD##E##C##";
	createTree(&T, data, &index);
	inThreadTree(T, &pre);
	pre->rtag = 1;
	pre->rchild = NULL;
	for (TreeNode* node = getFirst_in(T); node != NULL; node = getNext_in(node))
	{
		printf("%c ", node->data);
	}
	printf("\n");
}
//////////////////////////////////////////////////////////////////////////

void preThreadTree(TreeNode* T, TreeNode** pre) 
{
	if (T) {
		if (T->lchild == NULL) 
		{
			T->ltag = 1;
			T->lchild = *pre;
		}
		if (*pre != NULL && (*pre)->rchild == NULL)
		{
			(*pre)->rtag = 1;
			(*pre)->rchild = T;
		}
		*pre = T;
		if (T->ltag == 0)
			preThreadTree(T->lchild, pre);
		preThreadTree(T->rchild, pre);
	}
}
TreeNode* getNext_pre(TreeNode* node)
{
	if (node->rtag == 1 || node->ltag == 1)
		return node->rchild;
	else
		return node->lchild;
}

void test02()
{
	TreeNode* T;
	TreeNode* pre = NULL;
	int index = 0;
	char * data = "ABD##E##C##";
	createTree(&T, data, &index);
	preThreadTree(T, &pre);
	pre->rtag = 1;
	pre->rchild = NULL;
	for (TreeNode* node = T; node != NULL; node = getNext_pre(node))
	{
		printf("%c ", node->data);
	}
	printf("\n");
}

//////////////////////////////////////////////////////////////////////////
//�������������
void createTree_post(TreeNode** T, char* data, int* index, TreeNode* parent)
{
	char ch;
	ch = data[*index];
	*index += 1;
	if (ch == '#')
	{
		// ��ʱΪ�սڵ�
		*T = NULL;
	}
	else 
	{
		// ��ʱ��Ϊ��
		*T = (TreeNode*)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		(*T)->ltag = 0;
		(*T)->rtag = 0;
		(*T)->parent = parent;
		// �������������߼�һ�£����еݹ�
		createTree_post(&((*T)->lchild), data, index, *T);
		// �������������߼�һ�£����еݹ�
		createTree_post(&((*T)->rchild), data, index, *T);
	}
}

void postThreadTree(TreeNode* T, TreeNode** pre)
{
	if (T) 
	{
		postThreadTree(T->lchild, pre);
		postThreadTree(T->rchild, pre);
		// do something
		if (T->lchild == NULL)
		{
			T->ltag = 1;
			T->lchild = *pre;
		}
		if (*pre != NULL && (*pre)->rchild == NULL) 
		{
			(*pre)->rtag = 1;
			(*pre)->rchild = T;
		}
		*pre = T;
	}
}

TreeNode* getFirst_post(TreeNode* T)
{
	while (T->ltag == 0)
		T = T->lchild;
	if (T->rtag == 0) {
		return getFirst_post(T->rchild);
	}
	return T;
}

TreeNode* getNext_post(TreeNode* node)
{
	if (node->rtag == 1)
		return node->rchild;
	else {
		// ����Ǹ��ڵ�
		if (node->parent == NULL) {
			return NULL;
		}
		// ������Һ���
		else if (node->parent->rchild == node) {
			return node->parent;
		}
		// ���������
		else {
			if (node->parent->ltag == 0) {
				return getFirst_post(node->parent->rchild);
			}
			else {
				return node->parent;
			}
		}
	}
}

void test03()
{
	TreeNode* T;
	TreeNode* pre = NULL;
	int index = 0;
	char * data = "ABD##E##C##";
	createTree_post(&T, data, &index, NULL);
	postThreadTree(T, &pre);
	for (TreeNode* node = getFirst_post(T); node != NULL; node = getNext_post(node)) {
		printf("%c ", node->data);
	}
	printf("\n");

}

int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;

}