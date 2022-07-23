#include "BiTree.h"

void createTree(TreeNode** T, char* data, int* index) {
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
		// �������������߼�һ�£����еݹ�
		createTree(&((*T)->lchild), data, index);
		// �������������߼�һ�£����еݹ�
		createTree(&((*T)->rchild), data, index);
	}
}

void preOrder(TreeNode* T) {
	if (T == NULL) {
		return;
	}
	else {
		// �Ȱ���
		printf("%c ", T->data);
		// ��������
		preOrder(T->lchild);
		// �����Һ���
		preOrder(T->rchild);
	}
}

void inOrder(TreeNode* T) {
	if (T == NULL) {
		return;
	}
	else {
		// ��������
		inOrder(T->lchild);
		// �а���
		printf("%c ", T->data);
		// �����Һ���
		inOrder(T->rchild);
	}
}

void postOrder(TreeNode* T) {
	if (T == NULL) {
		return;
	}
	else {
		// ��������
		postOrder(T->lchild);
		// �����Һ���
		postOrder(T->rchild);
		// �����
		printf("%c ", T->data);
	}
}



void test01()
{
	TreeNode* T;
	int index = 0;
	char * data = "ABD##E##CF##G##";
	createTree(&T, data, &index);
	printf("���������"); preOrder(T);
	printf("\n");
	printf("���������"); inOrder(T);
	printf("\n");
	printf("���������"); postOrder(T);
	printf("\n");
}


//////////////////////////////////////////////////////////////////////////
QueueNode* initQueue()
{
	QueueNode* Q = (QueueNode*)malloc(sizeof(QueueNode));
	Q->data = NULL;
	Q->next = Q;
	Q->pre = Q;
	return Q;
}

void enQueue(TreeNode* data, QueueNode* Q)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = data;
	node->pre = Q;
	node->next = Q;
	Q->pre->next = node;
	Q->pre = node;
}

int isEmpty(QueueNode* Q)
{
	if (Q->next == Q) {
		return 1;
	}
	else {
		return 0;
	}
}



QueueNode* deQueue(QueueNode* Q)
{
	if (isEmpty(Q)) {
		return NULL;
	}
	else {
		QueueNode* node = Q->next;
		Q->next->next->pre = Q;
		Q->next = Q->next->next;
		return node;
	}
}

void levelTraverse(QueueNode* Q, TreeNode* T)
{
	enQueue(T, Q);
	while (!isEmpty(Q)) {
		QueueNode* node = deQueue(Q);
		printf("%c ", node->data->data);
		if (node->data->lchild) {
			enQueue(node->data->lchild, Q);
		}
		if (node->data->rchild) {
			enQueue(node->data->rchild, Q);
		}
	}
}
void test02()
{
	//��α���
	TreeNode* T;
	int index = 0;
	char * data = "ABD##E##CF##G##";
	createTree(&T, data, &index);
	QueueNode* Q = initQueue();
	preOrder(T);
	printf("\n");
	levelTraverse(Q, T);
	printf("\n");

}
//////////////////////////////////////////////////////////////////////////
//�ǵݹ����
StackNode* initStack()
{
	StackNode* S = (StackNode*)malloc(sizeof(StackNode));
	S->data = NULL;
	S->next = NULL;
	return S;
}

void push(TreeNode* data, StackNode* S) 
{
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));
	node->data = data;
	node->next = S->next;
	S->next = node;
}

int isEmpty(StackNode* S)
{
	if (S->next == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

StackNode* pop(StackNode* S) 
{
	if (isEmpty(S)) {
		return NULL;
	}
	else {
		StackNode* node = S->next;
		S->next = node->next;
		return node;
	}
}

void preOrder_noRecurs(TreeNode* T)
{
	TreeNode* node = T;
	StackNode* S = initStack();
	while (node || !isEmpty(S)) {
		if (node) {
			printf("%c ", node->data);
			push(node, S);
			node = node->lchild;
		}
		else {
			node = pop(S)->data;
			node = node->rchild;
		}
	}
}

void inOrder_noRecurs(TreeNode* T)
{
	TreeNode* node = T;
	StackNode* S = initStack();
	while (node || !isEmpty(S)) {
		if (node) {
			push(node, S);
			node = node->lchild;
		}
		else {
			node = pop(S)->data;
			printf("%c ", node->data);
			node = node->rchild;
		}
	}
}

StackNode* getTop(StackNode* S) {
	if (isEmpty(S)) {
		return NULL;
	}
	else {
		StackNode* node = S->next;
		return node;
	}
}

void postOrder_noRecurs(TreeNode* T)
{
	StackNode* S = initStack();
	StackNode* n = (StackNode*)malloc(sizeof(StackNode));
	
	TreeNode *ee = T;//���ڵ�
	TreeNode *pp = NULL;

	while (ee != NULL || !isEmpty(S) )
	{
		if (ee!= NULL)
		{
			push(ee, S);
			ee = ee->lchild;
		}
		else
		{
			ee = getTop(S)->data;
			
			if ((ee->rchild!=NULL) && (ee->rchild!=pp))
			{
				ee = ee->rchild;
				push(ee, S);
				ee = ee->lchild;
			} 
			else
			{
				ee = pop(S)->data;
				printf("%c ", ee->data);
				pp = ee;
				ee = NULL;
			}
		}
		
	}
	

}
void test03()
{
	TreeNode* T;
	int index = 0;
	char * data = "ABD##E##CF##G##";
	createTree(&T, data, &index);
	preOrder_noRecurs(T);
	printf("\n");
	inOrder_noRecurs(T);
	printf("\n");
	postOrder_noRecurs(T);
	printf("\n");
}

int main()
{
	/*
				 A
			  /      \
			 B        C
			/ \      / \
		   D   E    F   G
		  / \ / \  / \ / \
		  # # # #  # # # #
	*/
	test03();
	system("pause");
	return EXIT_SUCCESS;
	
}