#include "SeqQueue.h"
//ѭ�����е�����ʵ�֣���βָ��ָ���β����һ��Ԫ�أ�������length�ĸ���������
// ѭ������QQ�ĳ�ʼ��������
void InitQueue(PSeqQueue QQ)
{
	if (QQ == NULL )
	{
		return ;
	}

		QQ->front = QQ->rear = QQ->length = 0;
		memset(QQ->data, 0, sizeof(ElemType)*MAXSIZE);  // ����Ԫ�����㡣
}

// ����ѭ������QQ��
void DestroyQueue(PSeqQueue QQ)
{
	if (QQ)
	{
		QQ->front = QQ->rear = QQ->length = 0;
		memset(QQ->data, 0, sizeof(ElemType)*MAXSIZE);  // ����Ԫ�����㡣
		delete QQ;
	}
	return;
}

// Ԫ����ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int InQueue(PSeqQueue QQ, ElemType *ee)
{
	if (QQ==NULL ||  ee == NULL )
	{
		return ERROR;
	}
	if (IsFull(QQ))
	{
		printf("ѭ���������������ܲ��롣\n"); return 0;
	}
	memcpy(&QQ->data[QQ->rear], ee, sizeof(ElemType));  // ��������±���ʡ�
	QQ->rear = (QQ->rear + 1) % MAXSIZE;
	QQ->length++;
	return OK;
}

// Ԫ�س��ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int OutQueue(PSeqQueue QQ, ElemType *ee)
{
	if (QQ == NULL || ee == NULL)
	{
		return ERROR;
	}
	//memset(ee,&QQ->data[QQ->front], sizeof(ElemType));
	memcpy(ee, &QQ->data[QQ->front], sizeof(ElemType));  // ��������±���ʡ�
	QQ->front = (QQ->front + 1) % MAXSIZE;
	QQ->length--;
	return OK;
}

// ��ѭ�����еĳ��ȣ�����ֵ��>=0-����QQԪ�صĸ�����
int  Length(PSeqQueue QQ)
{
	if (QQ == NULL )return ERROR;
	return QQ->length;
}

// ���ѭ�����С�
void Clear(PSeqQueue QQ)
{
	if (QQ == NULL)return;
	QQ->front = QQ->rear = QQ->length = 0;
	memset(QQ->data, 0, sizeof(ElemType)*MAXSIZE);  // ����Ԫ�����㡣
}

// �ж�ѭ�������Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int  IsEmpty(PSeqQueue QQ)
{
	if (QQ == NULL) return ERROR;
	if (QQ->length == 0)
	{
		return OK;
	}
	else
	{
		return 0;
	}
}

// �ж�ѭ�������Ƿ�����������ֵ��1-������0-δ����ʧ�ܡ�
int IsFull(PSeqQueue QQ)
{
	if (QQ == NULL) return ERROR;
	if (QQ->length < MAXSIZE)
	{
		return 0;
	}
	else
	{
		return OK;
	}
}

// ��ӡѭ��������ȫ����Ԫ�ء�
void PrintQueue(PSeqQueue QQ)
{
	if (QQ == NULL) return ;
	if (IsEmpty(QQ) == 1) { printf("����Ϊ�ա�\n"); return; }
	for (int i = 0; i < QQ->length ; i++)
	{
		//printf("data[%d],value=%d\n", i, QQ->data[(QQ->front+i )% MAXSIZE]);
		// ��������±���ʡ�
		printf("data[%d],value=%d\n", /*(QQ->front + i) % MAXSIZE*/i, QQ->data[(QQ->front + i) % MAXSIZE]);
		//printf("data[%d],value=%d\n",(QQ->front+i)%MAXSIZE,QQ->data[(QQ->front+i)%MAXSIZE]);   
	}
}

// ��ȡ��ͷԪ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴��ͷԪ�ص�ֵ��Ԫ�ز����ӡ�
int GetHead(PSeqQueue QQ, ElemType *ee)
{
	if (QQ == NULL || ee == NULL) return ERROR;
	memcpy(ee, &QQ->data[QQ->front], sizeof ElemType);
	return OK;
}

void test01()
{
	SeqQueue QQ;     // ����ѭ�����С�

	InitQueue(&QQ);  // ��ʼ��ѭ�����С�

	ElemType ee;     // ����һ������Ԫ�ء�
	  
	printf("Ԫ�أ�1��2��3��4��5��6��7��8��9��10��11����ӡ�\n");
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
	ee = 11; InQueue(&QQ, &ee);

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

}
int main()
{
	test01();//test
	system("pause");
	return EXIT_SUCCESS;	
}