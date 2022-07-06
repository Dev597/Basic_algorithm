#include "LinkQueue.h"

// ����QQ�ĳ�ʼ��������
int InitQueue(PLinkQueue QQ)
{
	if (QQ == NULL)return ERROR;
	LNode *s = new LNode;
	s->next = NULL;
	QQ->front =QQ->rear =  s;
	return OK;
}

// ���ٶ���QQ��
void DestroyQueue(PLinkQueue QQ)
{
	if (QQ == NULL)return ;
	Clear(QQ);
	if (QQ)
	{
		delete QQ;
	}
}

// ��ն��С�
void Clear(PLinkQueue QQ)
{
	if (QQ == NULL)return;
	LNode *p = QQ->front->next;
	LNode *q;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	QQ->rear = QQ->front;
	QQ->front->next = NULL;
	
}

// Ԫ����ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int InQueue(PLinkQueue QQ, ElemType *ee)
{
	if (QQ == NULL || *ee == NULL)return;
	if (QQ->front ==  NULL)
	{
		printf("����δ��ʼ��\n");
	}

	LNode *s = new LNode;
	if (s == NULL) return 0;  // �ڴ治�㣬����ʧ��
	memcpy(&s->data, ee, sizeof(ElemType));
	s->next = NULL;

	QQ->rear->next = s;
	QQ->rear = s;
	return OK;

}

// ��ӡ������ȫ����Ԫ�ء�
void PrintQueue(PLinkQueue QQ)
{
	if (QQ == NULL)return;
	if (QQ->front == NULL)
	{
		printf("����δ��ʼ��\n");
	}
	LNode *p = QQ->front->next;
	while (p)
	{
		printf("%-3d", p->data);  // ���Ԫ��eeΪ�ṹ�壬���д���Ҫ�޸ġ�
		p = p->next;

	}
	printf("\n");
}

// ����еĳ��ȣ�����ֵ��>=0-����QQԪ�صĸ�����
int  Length(PLinkQueue QQ)
{
	if (QQ == NULL)return;
	if (QQ->front == NULL)
	{
		return 0;
	}
	int n = 0;
	LNode *p = QQ->front->next;
	while (p)
	{
		++n;
		p = p->next;
	}
	return n;
}

// �ж϶����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int  IsEmpty(PLinkQueue QQ)
{
	if (QQ == NULL)return;
	if (QQ->front == NULL)
	{
		printf("����δ��ʼ��\n");
	}
	if (QQ->front->next == NULL)
	{
		printf("����Ϊ��\n");
		return OK;
	}
}

// Ԫ�س��ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int OutQueue(PLinkQueue QQ, ElemType *ee)
{
	if (QQ == NULL || *ee == NULL)return;
	if (QQ->front == NULL)
	{
		printf("����δ��ʼ��\n");
	}
	if (IsEmpty(QQ) == 1) { printf("����Ϊ�ա�\n"); return 0; }
	LNode * p = QQ->front->next;
	memcpy(ee, &QQ->front->data, sizeof ElemType);
	QQ->front = QQ->front->next;
	if (QQ->rear == p);

}

// ��ȡ��ͷԪ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴��ͷԪ�ص�ֵ��Ԫ�ز����ӡ�
int GetHead(PLinkQueue QQ, ElemType *ee);



void test01()
{
	LinkQueue QQ;     // �������С�

	memset(&QQ, 0, sizeof(LinkQueue));

	InitQueue(&QQ);  // ��ʼ�����С�

	ElemType ee;     // ����һ������Ԫ�ء�

	printf("Ԫ�أ�1��2��3��4��5��6��7��8��9��10����ӡ�\n");
	ee = 1;  InQueue(&QQ, &ee);
	ee = 2;  InQueue(&QQ, &ee);
	ee = 3;  InQueue(&QQ, &ee);
	ee = 4;  InQueue(&QQ, &ee);
	ee = 5;  InQueue(&QQ, &ee);
	ee = 6;  InQueue(&QQ, &ee);
	ee = 7;  InQueue(&QQ, &ee);
	ee = 8;  InQueue(&QQ, &ee);
	ee = 9;  InQueue(&QQ, &ee);
	ee = 10; InQueue(&QQ, &ee);

	printf("���еĳ�����%d\n", Length(&QQ));

	PrintQueue(&QQ);

	if (OutQueue(&QQ, &ee) == 1)  printf("���ӵ�Ԫ��ֵΪ%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("���ӵ�Ԫ��ֵΪ%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("���ӵ�Ԫ��ֵΪ%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("���ӵ�Ԫ��ֵΪ%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("���ӵ�Ԫ��ֵΪ%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("���ӵ�Ԫ��ֵΪ%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("���ӵ�Ԫ��ֵΪ%d\n", ee);

	printf("���еĳ�����%d\n", Length(&QQ));
	PrintQueue(&QQ);

	printf("Ԫ�أ�11��12��13��14��15����ӡ�\n");
	ee = 11;  InQueue(&QQ, &ee);
	ee = 12;  InQueue(&QQ, &ee);
	ee = 13;  InQueue(&QQ, &ee);
	ee = 14;  InQueue(&QQ, &ee);
	ee = 15;  InQueue(&QQ, &ee);

	printf("���еĳ�����%d\n", Length(&QQ));

	PrintQueue(&QQ);

	// ֻ�鿴��ͷԪ�ص�ֵ��Ԫ�ز����ӡ�
	if (GetHead(&QQ, &ee) == 1)  printf("��ͷ��Ԫ��ֵΪ%d\n", ee);

	DestroyQueue(&QQ); // ���ٶ���QQ��

}

int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
	
}