#include "LinkQueue.h"

// 队列QQ的初始化操作。
int InitQueue(PLinkQueue QQ)
{
	if (QQ == NULL)return ERROR;
	LNode *s = new LNode;
	s->next = NULL;
	QQ->front =QQ->rear =  s;
	return OK;
}

// 销毁队列QQ。
void DestroyQueue(PLinkQueue QQ)
{
	if (QQ == NULL)return ;
	Clear(QQ);
	if (QQ)
	{
		delete QQ;
	}
}

// 清空队列。
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

// 元素入队，返回值：0-失败；1-成功。
int InQueue(PLinkQueue QQ, ElemType *ee)
{
	if (QQ == NULL || *ee == NULL)return;
	if (QQ->front ==  NULL)
	{
		printf("队列未初始化\n");
	}

	LNode *s = new LNode;
	if (s == NULL) return 0;  // 内存不足，返回失败
	memcpy(&s->data, ee, sizeof(ElemType));
	s->next = NULL;

	QQ->rear->next = s;
	QQ->rear = s;
	return OK;

}

// 打印队列中全部的元素。
void PrintQueue(PLinkQueue QQ)
{
	if (QQ == NULL)return;
	if (QQ->front == NULL)
	{
		printf("队列未初始化\n");
	}
	LNode *p = QQ->front->next;
	while (p)
	{
		printf("%-3d", p->data);  // 如果元素ee为结构体，这行代码要修改。
		p = p->next;

	}
	printf("\n");
}

// 求队列的长度，返回值：>=0-队列QQ元素的个数。
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

// 判断队列是否为空，返回值：1-空，0-非空或失败。
int  IsEmpty(PLinkQueue QQ)
{
	if (QQ == NULL)return;
	if (QQ->front == NULL)
	{
		printf("队列未初始化\n");
	}
	if (QQ->front->next == NULL)
	{
		printf("队列为空\n");
		return OK;
	}
}

// 元素出队，返回值：0-失败；1-成功。
int OutQueue(PLinkQueue QQ, ElemType *ee)
{
	if (QQ == NULL || *ee == NULL)return;
	if (QQ->front == NULL)
	{
		printf("队列未初始化\n");
	}
	if (IsEmpty(QQ) == 1) { printf("队列为空。\n"); return 0; }
	LNode * p = QQ->front->next;
	memcpy(ee, &QQ->front->data, sizeof ElemType);
	QQ->front = QQ->front->next;
	if (QQ->rear == p);

}

// 获取队头元素，返回值：0-失败；1-成功。
// 只查看队头元素的值，元素不出队。
int GetHead(PLinkQueue QQ, ElemType *ee);



void test01()
{
	LinkQueue QQ;     // 创建队列。

	memset(&QQ, 0, sizeof(LinkQueue));

	InitQueue(&QQ);  // 初始化队列。

	ElemType ee;     // 创建一个数据元素。

	printf("元素（1、2、3、4、5、6、7、8、9、10）入队。\n");
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

	printf("队列的长度是%d\n", Length(&QQ));

	PrintQueue(&QQ);

	if (OutQueue(&QQ, &ee) == 1)  printf("出队的元素值为%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("出队的元素值为%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("出队的元素值为%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("出队的元素值为%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("出队的元素值为%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("出队的元素值为%d\n", ee);
	if (OutQueue(&QQ, &ee) == 1)  printf("出队的元素值为%d\n", ee);

	printf("队列的长度是%d\n", Length(&QQ));
	PrintQueue(&QQ);

	printf("元素（11、12、13、14、15）入队。\n");
	ee = 11;  InQueue(&QQ, &ee);
	ee = 12;  InQueue(&QQ, &ee);
	ee = 13;  InQueue(&QQ, &ee);
	ee = 14;  InQueue(&QQ, &ee);
	ee = 15;  InQueue(&QQ, &ee);

	printf("队列的长度是%d\n", Length(&QQ));

	PrintQueue(&QQ);

	// 只查看队头元素的值，元素不出队。
	if (GetHead(&QQ, &ee) == 1)  printf("队头的元素值为%d\n", ee);

	DestroyQueue(&QQ); // 销毁队列QQ。

}

int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
	
}