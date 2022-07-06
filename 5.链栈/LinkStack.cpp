#include "LinkStack.h"
// ��ջSS�ĳ�ʼ������������ͷ��㣬����ͷ���ĵ�ַ��
SNode *InitStack()
{
	SNode * SS = new SNode;
	if (SS == NULL) return NULL;  // �ڴ治�㣬����ʧ�ܡ�
	SS->next = NULL;  // ͷ������һ�����ʱ�����ڣ��ÿա�
	return SS;
}

// ������ջSS��
void DestroyStack(LinkStack SS)
{
	if (SS == NULL) return ;
	Clear(SS);
	if (SS)
	{
		delete SS;
	}
}

// Ԫ����ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Push(LinkStack SS, ElemType *ee)
{
	if ((SS == NULL) || (ee == NULL)) return 0;  // ����ָ�롣
	// �ڴ治�㣬����ʧ�ܡ�								
	// ��������Ԫ��Ϊ�ṹ�����������������memcpy�ķ���������ֱ�Ӹ�ֵ
	SNode * p = new SNode;
	memcpy(&p->data, ee, sizeof(ElemType));

	p->next = SS->next;
	SS->next = p;
	return OK;
}

// Ԫ�س�ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Pop(LinkStack SS, ElemType *ee)
{
	if ((SS->next == NULL) || (ee == NULL)) return 0;  // ����ָ�롣
	SNode * p = SS->next;
	memcpy( ee,&p->data, sizeof(ElemType));

	SS->next = p->next;
	delete p;
	return OK;
}

// ����ջ�ĳ��ȣ�����ֵ��ջSS��Ԫ�صĸ�����
int  Length(LinkStack SS)
{
	if ((SS->next == NULL) ) return 0;  // ����ָ�롣
	int i = 0;
	SNode * p = SS->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

// �����ջ��
void Clear(LinkStack SS)
{
	if (SS == NULL) return;
	SNode * p = SS->next;
	SNode * q;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	SS->next = NULL;
}

// �ж���ջ�Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int  IsEmpty(LinkStack SS)
{
	if (SS == NULL)
	{
		return -1;
	}
	if (SS->next)
	{
		return 0;
	}
	return 1;
}

// ��ӡ��ջ��ȫ����Ԫ�ء�
void PrintStack(LinkStack SS)
{
	if (SS == NULL) return;
	if (SS->next == NULL) { printf("ջΪ�ա�\n"); return; }

	int kk = 0;
	SNode *pp = SS->next;  // �ӵ�1����㿪ʼ��

	while (pp != NULL)
	{
		printf("SS[%d],value=%d\n", kk++, pp->data);
		pp = pp->next;
	}
}

// ��ȡջ��Ԫ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴ջ��Ԫ�ص�ֵ��Ԫ�ز���ջ��
int GetTop(LinkStack SS, ElemType *ee)
{
	if (SS == NULL) return ERROR;
	if (SS->next == NULL) { printf("ջΪ�ա�\n"); return ERROR; }
	memcpy(ee, &SS->next->data, sizeof(ElemType));
	return OK;
}



void test01()
{
	LinkStack SS;     // ������ջ��

	SS = InitStack();  // ��ʼ����ջ��

	printf("ջ�ĳ�����%d\n", Length(SS));

	ElemType ee;     // ����һ������Ԫ�ء�

	printf("Ԫ�أ�1��2��3��4��5��6��7��8��9��10����ջ��\n");
	ee = 1;  Push(SS, &ee);
	ee = 2;  Push(SS, &ee);
	ee = 3;  Push(SS, &ee);
	ee = 4;  Push(SS, &ee);
	ee = 5;  Push(SS, &ee);
	ee = 6;  Push(SS, &ee);
	ee = 7;  Push(SS, &ee);
	ee = 8;  Push(SS, &ee);
	ee = 9;  Push(SS, &ee);
	ee = 10; Push(SS, &ee);

	printf("ջ�ĳ�����%d\n", Length(SS));

	if (GetTop(SS, &ee) == 1)  printf("ջ����Ԫ��ֵΪ%d\n", ee);

	PrintStack(SS);

	if (Pop(SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);

	// ������ջSS��
	DestroyStack(SS); SS = 0;  // ������ջ���SS��Ϊ�գ���ֹҰָ�롣
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
	
}