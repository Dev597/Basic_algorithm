#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

void printArray(int array[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}
//��������
void insertSort(int array[], int length)
{
	int i, j, k;
	for (i = 1; i < length; i++)//��ָ��
	{
		for (j = 0; j < i; j++ )//ǰָ��
		{
			if (array[i] < array[j])
			{
				int temp = array[i];
				for (k = i - 1; k >= j; k--)//�����
				{
					array[k + 1] = array[k];
				}
				array[j] = temp;
			}
			
		}
		printArray(array, length);
	}
}

/**ϣ��������С��������
 * 1.����kΪ������ʼ�������н��з��飬�����ڵ����ֽ��в�������
 * 2.��С����k,�ظ���һ����ֱ��k=1
 */
void shellSort(int array[], int length)
{

}


void test01()
{
	int array[6] = { 4,3,5,1,9,6 };
	printArray(array, 6);
	insertSort(array, 6);
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}