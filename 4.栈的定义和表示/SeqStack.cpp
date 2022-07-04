#include "SeqStack.h"

// ˳��ջSS�ĳ�ʼ��������
Status InitStack(PSeqStack SS)
{	
	Clear(SS);
	return OK;
}

// ����˳��ջSS��
void DestroyStack(PSeqStack SS)
{
	// ��̬˳��ջ�����ͷ��ڴ棬����Ҫ���ٲ�����
	Clear(SS); // ���˳��ջ��
	return;

}

// Ԫ����ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Push(PSeqStack SS, ElemType *ee)
{
	
	if ((SS == NULL) || (ee == NULL)) return ERROR;  // ����ָ�롣
	if (IsFull(SS) == 1)
	{
		printf("˳��ջ���������ܲ��롣\n"); return 0;
	}
	SS->top++;  // ջָ���ȼ�1��
	memcpy(&SS->data[SS->top], ee, sizeof(ElemType));  // ��������±���ʡ�												   // memcpy(SS->data+SS->top,ee,sizeof(ElemType));    // ����ָ������Ҳ���ԡ�
	return OK;
}

// Ԫ�س�ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Pop(PSeqStack SS, ElemType *ee)
{
	if ((SS == NULL) || (ee == NULL)) return ERROR;  // ����ָ�롣
	if (SS->top == -1) { printf("ջΪ�ա�\n"); return ERROR; }
	memcpy(ee,&SS->data[SS->top], sizeof(ElemType));
	SS->top--;
	return OK;
}

// ��˳��ջ�ĳ��ȣ�����ֵ��ջSS��Ԫ�صĸ�����
int Length(PSeqStack SS)
{
	if (SS == NULL) return 0; // ����ָ�롣
	return SS->top + 1;
}

// ���˳��ջ��
void Clear(PSeqStack SS)
{
	if (SS == NULL) return; // ����ָ�롣
	SS->top = -1;  // ջ��ָ����Ϊ-1��
	memset(SS->data, 0, sizeof(ElemType)*MAXSIZE);  // ����Ԫ�����㡣
}

// �ж�˳��ջ�Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int IsEmpty(PSeqStack SS)
{
	if (SS == NULL) return 0;  // ����ָ�롣
	if (SS->top == -1) return 1;

	return 0;
}

// �ж�˳��ջ�Ƿ�����������ֵ��1-������0-δ����ʧ�ܡ�
int IsFull(PSeqStack SS)
{
	if (SS == NULL) return ERROR; // ����ָ�롣
	if (SS->top >= MAXSIZE)
	{
		return OK;
	}
	return 0;
}

// ��ӡ˳��ջ��ȫ����Ԫ�ء�
void PrintStack(PSeqStack SS)
{
	if (SS == NULL) return;  // ����ָ�롣

	if (SS->top == -1) { printf("ջΪ�ա�\n"); return ; }

	int kk;
	for (kk = 0; kk <= SS->top; kk++)
	{
		printf("SS[%d],value=%d\n", kk, SS->data[kk]);    
		// ��������±���ʡ�
	 // printf("SS[%d],value=%d\n",kk,*(SS->data+kk));   // ����ָ������Ҳ���ԡ�
	}
}

// ��ȡջ��Ԫ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴ջ��Ԫ�ص�ֵ��Ԫ�ز���ջ��
int GetTop(PSeqStack SS, ElemType *ee)
{
	if (SS == NULL) return ERROR;  // ����ָ�롣
	if (SS->top == -1) { printf("ջΪ�ա�\n"); return ERROR; }
	memcpy(ee, &SS->data[SS->top], sizeof(ElemType));  
	// ��������±���ʡ�
	// memcpy(ee,SS->data+SS->top,sizeof(ElemType));    // ����ָ������Ҳ���ԡ�

	return OK;
}

void test01()
{
	SeqStack SS;
	InitStack(&SS);
	printf("ջ�ĳ�����%d\n", Length(&SS));

	ElemType ee;     // ����һ������Ԫ�ء�

	printf("Ԫ�أ�1��2��3��4��5��6��7��8��9��10����ջ��\n");
	ee = 1;  Push(&SS, &ee);
	ee = 2;  Push(&SS, &ee);
	ee = 3;  Push(&SS, &ee);
	ee = 4;  Push(&SS, &ee);
	ee = 5;  Push(&SS, &ee);
	ee = 6;  Push(&SS, &ee);
	ee = 7;  Push(&SS, &ee);
	ee = 8;  Push(&SS, &ee);
	ee = 9;  Push(&SS, &ee);
	ee = 10; Push(&SS, &ee);

	printf("ջ�ĳ�����%d\n", Length(&SS));

	// ֻ�鿴ջ��Ԫ�ص�ֵ��Ԫ�ز���ջ��
	if (GetTop(&SS, &ee) == 1)  printf("ջ����Ԫ��ֵΪ%d\n", ee);

	PrintStack(&SS);

	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
	if (Pop(&SS, &ee) == 1)  printf("��ջ��Ԫ��ֵΪ%d\n", ee);
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
	
}