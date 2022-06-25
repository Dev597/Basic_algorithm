#include "SqList.h"

//˳���L�ĳ�ʼ��
Status InitList_Sq(SqList &L)
{
	//����һ���յ�˳���
	L.elem = new ElemType[MAXSIZE];//Ϊ˳������ռ�
	if (!L.elem)
		exit(OVERFLOW);
	//�洢����ʧ��
	L.length = 0;
	//�ձ���Ϊ0
	return OK;
}

//����˳���L
void DestroyList(SqList &L)
{
	if (L.elem)
		delete L.elem;//�ͷŴ洢�ռ�
}

//������Ա�L
void ClearList(SqList &L)
{
	L.length = 0;
	//�����Ա�ĳ�����Ϊ0
}

//�����Ա�L�ĳ���
int GetLength(SqList L)
{
	return(L.length);
}

//�ж����Ա�L�Ƿ�Ϊ��
int IsEmpty(SqList L)
{
	if (L.length == 0)
		return 1;
	else
		return 0;
}

//˳����ȡֵ������λ��i��ȡ��Ӧλ������Ԫ�ص�����
int GetElem(SqList L, int i, ElemType &e)
{
	if (i<1 || i>L.length)//�ж�iֵ�Ƿ����������������ERROR
		return ERROR;
	e = L.elem[i - 1];//��i-1�ĵ�Ԫ�洢�ŵ�1������
	return OK;
}

//˳���Ĳ���
/**
	�����Ա�L�в�����ָ��ֵe��ͬ������Ԫ�ص�λ��
	�ӱ��һ�˿�ʼ��������м�¼�Ĺؼ��ֺ͸���ֵ�ıȽϡ��ҵ�����
	�ظ�Ԫ�ص�λ����ţ�δ�ҵ�������0��

	˳���Ĳ����㷨����
	�����������ؼ���ͬ����ֵ�Ƚ�,��ƽ�����Ҵ���
	ƽ�����ҳ���ASL(Average Search Length):Ϊȷ����¼�ڱ��е�λ�ã���Ҫ�����ֵ���бȽϵĹؼ��ֵĸ���������ֵ���������㷨��ƽ�����ҳ��ȡ�
	
 */
int LocateELem(SqList L, ElemType e)
{
	//�����Ա�L�в���ֵΪe������Ԫ�أ���������ţ��ǵڼ���Ԫ�أ�
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
			return i + 1;//���ҳɹ����������
	}
	return FALSE;//����ʧ�ܣ�����0
}

//�����Ա�L�е�i��λ�ò�����Ԫ��e
/**
�㷨˼�룺
	���жϲ���λ��i�Ƿ�Ϸ���
	���ж�˳���Ĵ洢�ռ��Ƿ�����������������ERROR��
	�۽���n����iλ��Ԫ����������ƶ�һ��λ�ã��ճ��ڸ�λ�á�
	�ܽ�Ҫ�������Ԫ��e����ڸ�λ�á�
	�ݱ���1,����ɹ�����OK��
*/
Status Listlnsert_Sq(SqList &L, int i, ElemType e)
{
	if (i < 1 || i > L.length + 1 ) 
		return ERROR;
	if (L.length == MAXSIZE)
		return ERROR;
	for (int j = L.length - 1; j >= i-1 ; --j)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i-1] = e;
	L.length++;
	return OK;
}

//ɾ�����Ա�L�еڸ�λ��Ԫ�أ���e����
/**
	�㷨˼�룺
	���ж�ɾ��λ��i�Ƿ�Ϸ����Ϸ�ֵΪ1��i��n)��
	�ڽ���ɾ����Ԫ�ر�����e�С�
	�۽���i+1����nλ��Ԫ��������ǰ�ƶ�һ��λ�á�
	�ܱ���1,ɾ���ɹ�����OK�� 
 */
Status ListDelete_Sq(SqList &L, int i, ElemType e)
{
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem[i - 1];
	for (int j = i; j <= L.length - 1; ++j)
	{
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}

Status ListShow_Sq(SqList L)
{
	if (L.length > 0)
	{
		for (int i = 0; i < L.length ; i++)
		{
			printf("%c  ", L.elem[i]);
		}
		printf("\n");
		return OK;
	}
	else
	{
		return ERROR;
	}
	
}
	
void test01()  
{ 
	//��ʼ��˳���
	SqList L;
	ElemType elem;
	Status isinit = InitList_Sq(L);
	if (isinit)
	{
		Listlnsert_Sq(L,1,'a');
		Listlnsert_Sq(L, 2, 'b');
		Listlnsert_Sq(L, 3, 'c');
		Listlnsert_Sq(L, 4, 'd');
		Listlnsert_Sq(L, 5, 'e');
	}
	
	ListShow_Sq(L);
	printf("˳���ĳ���Ϊ%d\n", GetLength(L));

	

	if (!IsEmpty(L))
	{
		int i = 5;
		if (GetElem(L, i, elem))
		{
			printf("L[%d]ֵΪ%c\n", i,elem);
		}
	}

	ListDelete_Sq(L, 1, elem);
	printf("ɾ��1��L Ϊ");
	ListShow_Sq(L);

	printf("��1����a LΪ");
	Listlnsert_Sq(L, 1, 'a');
	ListShow_Sq(L);

	ListDelete_Sq(L, 2, elem);
	printf("ɾ��2��L Ϊ");
	ListShow_Sq(L);

	ListDelete_Sq(L, 3, elem);
	printf("ɾ��3��L Ϊ");
	ListShow_Sq(L);

	printf("��2����V LΪ");
	Listlnsert_Sq(L, 2, 'V');
	ListShow_Sq(L);

		
	int n = LocateELem(L, 'c');
	printf("c��λ����%d\n", n);



	printf("���L\n");
	ClearList(L);
	ListShow_Sq(L);

	DestroyList(L);

}

int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
	
}