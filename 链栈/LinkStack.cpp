#include "LinkStack.h"
// 链栈SS的初始化操作，分配头结点，返回头结点的地址。
SNode *InitStack()
{
	SNode * SS = new SNode;
	if (SS == NULL) return NULL;  // 内存不足，返回失败。
	SS->next = NULL;  // 头结点的下一结点暂时不存在，置空。
	return SS;
}

// 销毁链栈SS。
void DestroyStack(LinkStack SS)
{
	if (SS == NULL) return ;
	Clear(SS);
	if (SS)
	{
		delete SS;
	}
}

// 元素入栈，返回值：0-失败；1-成功。
int Push(LinkStack SS, ElemType *ee)
{
	if ((SS == NULL) || (ee == NULL)) return 0;  // 检查空指针。
	// 内存不足，返回失败。								
	// 考虑数据元素为结构体的情况，这里采用了memcpy的方法而不是直接赋值
	SNode * p = new SNode;
	memcpy(&p->data, ee, sizeof(ElemType));

	p->next = SS->next;
	SS->next = p;
	return OK;
}

// 元素出栈，返回值：0-失败；1-成功。
int Pop(LinkStack SS, ElemType *ee)
{
	if ((SS->next == NULL) || (ee == NULL)) return 0;  // 检查空指针。
	SNode * p = SS->next;
	memcpy( ee,&p->data, sizeof(ElemType));

	SS->next = p->next;
	delete p;
	return OK;
}

// 求链栈的长度，返回值：栈SS中元素的个数。
int  Length(LinkStack SS)
{
	if ((SS->next == NULL) ) return 0;  // 检查空指针。
	int i = 0;
	SNode * p = SS->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

// 清空链栈。
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

// 判断链栈是否为空，返回值：1-空，0-非空或失败。
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

// 打印链栈中全部的元素。
void PrintStack(LinkStack SS)
{
	if (SS == NULL) return;
	if (SS->next == NULL) { printf("栈为空。\n"); return; }

	int kk = 0;
	SNode *pp = SS->next;  // 从第1个结点开始。

	while (pp != NULL)
	{
		printf("SS[%d],value=%d\n", kk++, pp->data);
		pp = pp->next;
	}
}

// 获取栈顶元素，返回值：0-失败；1-成功。
// 只查看栈顶元素的值，元素不出栈。
int GetTop(LinkStack SS, ElemType *ee)
{
	if (SS == NULL) return ERROR;
	if (SS->next == NULL) { printf("栈为空。\n"); return ERROR; }
	memcpy(ee, &SS->next->data, sizeof(ElemType));
	return OK;
}



void test01()
{
	LinkStack SS;     // 创建链栈。

	SS = InitStack();  // 初始化链栈。

	printf("栈的长度是%d\n", Length(SS));

	ElemType ee;     // 创建一个数据元素。

	printf("元素（1、2、3、4、5、6、7、8、9、10）入栈。\n");
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

	printf("栈的长度是%d\n", Length(SS));

	if (GetTop(SS, &ee) == 1)  printf("栈顶的元素值为%d\n", ee);

	PrintStack(SS);

	if (Pop(SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);
	if (Pop(SS, &ee) == 1)  printf("出栈的元素值为%d\n", ee);

	// 销毁链栈SS。
	DestroyStack(SS); SS = 0;  // 销毁链栈后把SS置为空，防止野指针。
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
	
}