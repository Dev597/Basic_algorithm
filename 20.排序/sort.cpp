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
//插入排序
void insertSort(int array[], int length)
{
	int i, j, k;
	for (i = 1; i < length; i++)//后指针
	{
		for (j = 0; j < i; j++ )//前指针
		{
			if (array[i] < array[j])
			{
				int temp = array[i];
				for (k = i - 1; k >= j; k--)//向后移
				{
					array[k + 1] = array[k];
				}
				array[j] = temp;
			}
			
		}
		printArray(array, length);
	}
}

/**希尔排序，缩小增量排序
 * 1.从以k为步长开始，对序列进行分组，对组内的数字进行插入排序
 * 2.缩小步长k,重复第一步，直到k=1
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