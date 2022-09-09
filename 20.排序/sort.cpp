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
		for (j = 0; j < i; j++)//前指针
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
void shellSort(int array[], int length, int steps)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i + steps; j < length; j += steps)
		{
			for (int k = i; k <= j; k += steps)
			{
				if (array[k] > array[j])
				{
					int temp = array[j];
					for (int l = j - steps; l >= k; l -= steps)
					{
						array[l + steps] = array[l];
					}
					array[k] = temp;
				}
			}
		}
	}
}

/**
 * 冒泡排序：一共要排序n -1 趟数，  每趟完成后下一次比较次数  n - i - 1
	
 */
void bubbleSort(int array[], int length)
{
#if 0
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int  temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
		printArray(array, length);
	}
#endif

#if 0
	//优化外层，如果已经有序，后续不再比较
	for (int i = 0; i < length - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < length - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int  temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				flag = 1;
			}
		}
		printArray(array, length);
		if (flag == 0)
		{
			return;
		}
	}
#endif

#if 1
	//优化内层，pos变量用来标记循环里最后一次交换的位置 ,交换位置后部分为有序区，后续不用再进行比较

	int k = length - 1;
	int pos = 0;//
	for (int i = 0; i < length - 1; i++)
	{		
		int flag = 0;
		for (int j = 0; j < k; j++)
		{
			if (array[j] > array[j + 1])
			{
				int  temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				flag = 1;
				pos = j;
			}
			
		}
		k = pos;
		printArray(array, length);
		if (flag == 0)
		{
			return;
		}
	}
#endif
}

int partition(int array[], int i, int j)
{
	int x = array[i];
	while (i < j)
	{
		while (i < j && array[j] > x)
		{
			j--;
		}
		if (i < j)
		{
			array[i] = array[j];
			i++;
		}
		while (i < j && array[i] < x)
		{
			i++;
		}
		if (i < j)
		{
			array[j] = array[i];
			j--;
		}
		
	}
	array[i] = x;
	return i;
}

/**
 * 快速排序，不稳定，不能对链表进行排序
 1)先从数列中取出一个元素作为基准数。
 2)扫描数列，将比基准数小的元素全部放到它的左边，大于或
 等于基准数的元素全部放到它的右边，得到左右两个区间。
 3)再对左右区间重复第二步，直到各区间少于两个元素。
 */
void quickSort(int array[], int i, int j)
{

	if (i < j) {
		int index = partition(array, i, j);
		printArray(array, 8);
		quickSort(array, i, index - 1);
		quickSort(array, index + 1, j);
	}
}

void _mergesort(int *arr, int *arrtmp, int start, int end)
{
	// 如果start>=end，表示该区间的元素少于两个，递归终止。
	if (start >= end) return;

	int mid = start + (end - start) / 2;  // 计算排序区间中间的位置。

	int istart1 = start, iend1 = mid;  // 区间左边元素的第一和最后一个元素的位置。
	int istart2 = mid + 1, iend2 = end;  // 区间右边元素的第一和最后一个元素的位置。

	_mergesort(arr, arrtmp, istart1, iend1);   // 对区间左边元素递归排序。
	_mergesort(arr, arrtmp, istart2, iend2);   // 对区间右边元素递归排序。

	int ii = start; // 已排序数组arrtmp的计数器。

					// 把区间左右两边数列合并到已排序数组arrtmp中。
	while (istart1 <= iend1 && istart2 <= iend2)
		arrtmp[ii++] = arr[istart1] < arr[istart2] ? arr[istart1++] : arr[istart2++];

	// 把左边数列其它的元素追加到已排序数组。
	while (istart1 <= iend1) arrtmp[ii++] = arr[istart1++];

	// 把右边数列其它的元素追加到已排序数组。
	while (istart2 <= iend2) arrtmp[ii++] = arr[istart2++];

	// 把已排序数组arrtmp中的元素复制到arr中。
	memcpy(arr + start, arrtmp + start, (end - start + 1)*sizeof(int));
}
/**
 * 归并排序：递归实现
	
 */
void mergeSort(int *arr, unsigned int len)
{
	if (len < 2) return;  // 小于两个元素不需要排序。

	int *arrtmp = new int[len];   // 分配一个与待排序数组相同大小的数组。

	_mergesort(arr, arrtmp, 0, len - 1);  // 调用递归函数进行排序。
}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

/**
 * n ：数组长度
 * i ： 待维护节点的下标
 */
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int lson = 2 * i + 1;
	int rson = 2 * i + 2;
	if (lson < n && arr[largest] < arr[lson])
	{
		largest = lson;
	}
	if (rson < n && arr[largest] < arr[rson])
	{
		largest = rson;
	}
	if (largest != i)
	{
		swap(arr[largest],arr[i]);
		heapify(arr, n, largest);
	}

	
}

void heapSort(int arr[], int n)
{
	//建堆  O(n)
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}
	//排序
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[i], arr[0]);
		heapify(arr, i, 0);
	}
}



void countSort(int arr[], int len)
{
	if (len < 2) return;
	int max = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] >= max)
		{
			max = arr[i];
		}
	}
	
	int *count = (int *)malloc(sizeof(int) * (max + 1));
	memset(count, 0, sizeof(int) * (max + 1));

	for (size_t i = 0; i < len; i++)
		count[arr[i]]++;

	int *output = (int *)malloc(sizeof(int) * len);
	int ii = 0;

	for (int j = 0; j < max + 1; j++)
	{
		for (int k = 0; k < count[j]; k++)
		{
			output[ii++] = j;
		}
	}

	for (size_t i = 0; i < len; i++)
		arr[i] = output[i];
	
}
void bubblesort(int *arr, unsigned int len)
{
	if (len < 2) return; // 数组小于2个元素不需要排序。

	int ii;    // 排序的趟数的计数器。
	int jj;    // 每趟排序的元素位置计数器。
	int itmp;  // 比较两个元素大小时交换位置用到的临时变量。

			   // 44,3,38,5,47,15,36,26,27,2,46,4,19,50,48  
	for (ii = len - 1; ii > 0; ii--)  // 一共进行len-1趟比较。
	{
		for (jj = 0; jj < ii; jj++)  // 每趟只需要比较0......ii之间的元素，ii之后的元素是已经排序好的。
		{
			if (arr[jj] > arr[jj + 1])  // 如果前面的元素大于后面的元素，则交换它位的位置。
			{
				itmp = arr[jj + 1];
				arr[jj + 1] = arr[jj];
				arr[jj] = itmp;
			}
		}
	}
}

// 桶排序主函数，参数arr是待排序数组的首地址，len是数组元素的个数。
void bucketSort(int arr[], unsigned int len)
{
	int buckets[5][5];   // 分配五个桶。
	int bucketssize[5];  // 每个桶中元素个数的计数器。

						 // 初始化桶和桶计数器。
	memset(buckets, 0, sizeof(buckets));
	memset(bucketssize, 0, sizeof(bucketssize));

	// 把数组arr的数据放入桶中。
	int ii = 0;
	for (ii = 0; ii < len; ii++)
	{
		buckets[arr[ii] / 10][bucketssize[arr[ii] / 10]++] = arr[ii];
	}

	// 对每个桶进行冒泡排序。
	for (ii = 0; ii < 5; ii++)
	{
		bubblesort(buckets[ii], bucketssize[ii]);
	}

	// 把每个桶中的数据填充到数组arr中。
	int jj = 0, kk = 0;
	for (ii = 0; ii < 5; ii++)
	{
		for (jj = 0; jj < bucketssize[ii]; jj++)
			arr[kk++] = buckets[ii][jj];
	}
}

void _radixSort(int *arr, unsigned int len, int exp)
{
	
	int *result = (int *)malloc(sizeof(int) * len);       // 存放从桶中收集后数据的临时数组。
	int buckets[10] = { 0 };   // 初始化10个桶。
	
	for (int i = 0; i < len; i++)
	{
		buckets[(arr[i] / exp) % 10]++;
	}

	for (int j = 1; j < 10; j++)
		buckets[j] = buckets[j] + buckets[j - 1];

	// 将arr中的元素填充到result中。
	for (int k = len - 1; k >= 0; k--)
	{
		int iexp = (arr[k] / exp) % 10;
		result[buckets[iexp] - 1] = arr[k];
		buckets[iexp]--;
	}

	// 将排序好的数组result复制到数组arr中。
	memcpy(arr, result, len*sizeof(int));
}

void radixSort(int *arr, unsigned int len)
{
	int max = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] >= max)
		{
			max = arr[i];
		}
	}
	int exp = 1;
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		_radixSort(arr, len, exp);
		printArray(arr, len);
	}
}

void test09()
{
	/**
	 * 基数排序（Radix sort)是桶排序的扩展，它的基本思想是：将整数按位数切割成不同的数字，然后按每个位数分别比较。
	 具体做法是：将所有待比较数值统一为同样的数位长度，数位较短的数前面补零。
	 然后，从最低位开始，依次进行一次排序。这样从最低位排序一直到最高位排序完成后，就变成了一个有序数列。
	 */
	int arr[] = { 144,203,738,905,347,215,836,26,527,602,946,504,219,750,848 };
	int len = sizeof(arr) / sizeof(int);

	radixSort(arr, len);  // 基数排序。
	printArray(arr, len);
}


void test08()
{
	int arr[] = { 21,3,30,44,15,36,6,10,9,19,25,48,5,23,47 };
	int len = sizeof(arr) / sizeof(int);
	printArray(arr, len);
	bucketSort(arr, len);
	printArray(arr, len);

}

void test07()
{
	int arr[] = { 2, 4, 1, 2, 5, 3, 4, 8, 7 };
	int len = sizeof(arr) / sizeof(int);
	countSort(arr,len);
	printArray(arr, len);
}

void test06()
{
	/**
	 * 堆排序：log (n)
		1. 完全二叉树 即 N[i]的左节点：N[2i+1]   N[i]的右节点：N[2i+2]   N[i]的父节点：N[(i-1)/2]
		2. 二叉树每个结点的值都大于或等于其左右子树结点的值称为大根堆；
		或者每个结点的值都小于或等于其左右孩子结点的值，称为小根堆。
	 */
	int arr[] = { 2,3,8,1,4,9,10,7,16,14 };
	int len = sizeof(arr) / sizeof(int);
	heapSort(arr, len);
	printArray(arr, len);

}

void test05()
{
	int arr[] = { 44,3,38,5,47,15,36,26,27,2,46,4,19,50,48,6,7,8,8,9,76,56,56,5,56,5,63,5,5 };
	int len = sizeof(arr) / sizeof(int);

	mergeSort(arr, len);
	printArray(arr, len);
}


void test04()
{
	int array[8] = { 27, 38, 13, 49, 76, 97, 65, 49 };
	quickSort(array, 0, 7);
}

void test03()
{
	int array[8] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	bubbleSort(array, 8);
}

void test02()
{
	int array[10] = { 49, 38, 65, 97, 76, 13, 27, 49, 55, 4 };
	int steps[3] = { 5, 3, 1 };
	for (int i = 0; i < 3; i++) {
		shellSort(array, 10, steps[i]);
		printArray(array, 10);
	}
}
void test01()
{
	int array[6] = { 4,3,5,1,9,6 };
	printArray(array, 6);
	insertSort(array, 6);
}
int main()
{
	test09();
	system("pause");
	return EXIT_SUCCESS;
}