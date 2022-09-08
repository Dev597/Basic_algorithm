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


int sequenSearch(int array[], int len, int key)
{
	int i;
	//顺序查找
#if 0
	for (i = 0; i < len && array[i] != key; i++);
	if (i > 0) return i;
	else return -1;
#endif
	
	//优化使用监视哨,使用倒序查找
#if 1
	array[0] = key;
	for (i = len; array[i] != key; i--);
	return i;
#endif		
}

void test01()
{
	int array[7] = {0,4,3,5,1,9,6};
	printArray(array, 7);
	int index = sequenSearch(array, 7, 1);
	printf("1的index为: %d\n", index);
}

int binarySearch(int num[], int len, int target)
{
	//二分查找
	int l = 0;
	int r = len - 1;
	int mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (target == num[mid])
		{
			return mid;
		}
		else if (target < num[mid])
		{
			r = mid - 1;
		}
		else 
		{
			l = mid + 1;
		}
	}
	return -1;

}

void test02()
{
	int nums[6] = { -1, 0, 3, 5, 9, 12 };
	int target = 9;
	//	输出: 4
	printArray(nums, 6);
	int index = binarySearch(nums, 6, target);
	printf("%d 的index为: %d\n",target, index);
}

int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}