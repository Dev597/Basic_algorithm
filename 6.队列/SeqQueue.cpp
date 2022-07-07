#include "SeqQueue.h"
//循环队列的数组实现，队尾指针指向队尾的下一个元素，增加了length的辅助变量。
// 循环队列QQ的初始化操作。
void InitQueue(PSeqQueue QQ)
{
	if (QQ == NULL )
	{
		return ;
	}

		QQ->front = QQ->rear = QQ->length = 0;
		memset(QQ->data, 0, sizeof(ElemType)*MAXSIZE);  // 数组元素清零。
}

// 销毁循环队列QQ。
void DestroyQueue(PSeqQueue QQ)
{
	if (QQ)
	{
		QQ->front = QQ->rear = QQ->length = 0;
		memset(QQ->data, 0, sizeof(ElemType)*MAXSIZE);  // 数组元素清零。
		delete QQ;
	}
	return;
}

// 元素入队，返回值：0-失败；1-成功。
int InQueue(PSeqQueue QQ, ElemType *ee)
{
	if (QQ==NULL ||  ee == NULL )
	{
		return ERROR;
	}
	if (IsFull(QQ))
	{
		printf("循环队列已满，不能插入。\n"); return 0;
	}
	memcpy(&QQ->data[QQ->rear], ee, sizeof(ElemType));  // 用数组的下标访问。
	QQ->rear = (QQ->rear + 1) % MAXSIZE;
	QQ->length++;
	return OK;
}

// 元素出队，返回值：0-失败；1-成功。
int OutQueue(PSeqQueue QQ, ElemType *ee)
{
	if (QQ == NULL || ee == NULL)
	{
		return ERROR;
	}
	//memset(ee,&QQ->data[QQ->front], sizeof(ElemType));
	memcpy(ee, &QQ->data[QQ->front], sizeof(ElemType));  // 用数组的下标访问。
	QQ->front = (QQ->front + 1) % MAXSIZE;
	QQ->length--;
	return OK;
}

// 求循环队列的长度，返回值：>=0-队列QQ元素的个数。
int  Length(PSeqQueue QQ)
{
	if (QQ == NULL )return ERROR;
	return QQ->length;
}

// 清空循环队列。
void Clear(PSeqQueue QQ)
{
	if (QQ == NULL)return;
	QQ->front = QQ->rear = QQ->length = 0;
	memset(QQ->data, 0, sizeof(ElemType)*MAXSIZE);  // 数组元素清零。
}

// 判断循环队列是否为空，返回值：1-空，0-非空或失败。
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

// 判断循环队列是否已满，返回值：1-已满，0-未满或失败。
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

// 打印循环队列中全部的元素。
void PrintQueue(PSeqQueue QQ)
{
	if (QQ == NULL) return ;
	if (IsEmpty(QQ) == 1) { printf("队列为空。\n"); return; }
	for (int i = 0; i < QQ->length ; i++)
	{
		//printf("data[%d],value=%d\n", i, QQ->data[(QQ->front+i )% MAXSIZE]);
		// 用数组的下标访问。
		printf("data[%d],value=%d\n", /*(QQ->front + i) % MAXSIZE*/i, QQ->data[(QQ->front + i) % MAXSIZE]);
		//printf("data[%d],value=%d\n",(QQ->front+i)%MAXSIZE,QQ->data[(QQ->front+i)%MAXSIZE]);   
	}
}

// 获取队头元素，返回值：0-失败；1-成功。
// 只查看队头元素的值，元素不出队。
int GetHead(PSeqQueue QQ, ElemType *ee)
{
	if (QQ == NULL || ee == NULL) return ERROR;
	memcpy(ee, &QQ->data[QQ->front], sizeof ElemType);
	return OK;
}

void test01()
{
	SeqQueue QQ;     // 创建循环队列。

	InitQueue(&QQ);  // 初始化循环队列。

	ElemType ee;     // 创建一个数据元素。
	  
	printf("元素（1、2、3、4、5、6、7、8、9、10、11）入队。\n");
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

}
int main()
{
	test01();//test
	system("pause");
	return EXIT_SUCCESS;	
}