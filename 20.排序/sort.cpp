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
		for (j = 0; j < i; j++)//ǰָ��
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
 * ð������һ��Ҫ����n -1 ������  ÿ����ɺ���һ�αȽϴ���  n - i - 1
	
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
	//�Ż���㣬����Ѿ����򣬺������ٱȽ�
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
	//�Ż��ڲ㣬pos�����������ѭ�������һ�ν�����λ�� ,����λ�ú󲿷�Ϊ�����������������ٽ��бȽ�

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
 * �������򣬲��ȶ������ܶ������������
 1)�ȴ�������ȡ��һ��Ԫ����Ϊ��׼����
 2)ɨ�����У����Ȼ�׼��С��Ԫ��ȫ���ŵ�������ߣ����ڻ�
 ���ڻ�׼����Ԫ��ȫ���ŵ������ұߣ��õ������������䡣
 3)�ٶ����������ظ��ڶ�����ֱ����������������Ԫ�ء�
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
	// ���start>=end����ʾ�������Ԫ�������������ݹ���ֹ��
	if (start >= end) return;

	int mid = start + (end - start) / 2;  // �������������м��λ�á�

	int istart1 = start, iend1 = mid;  // �������Ԫ�صĵ�һ�����һ��Ԫ�ص�λ�á�
	int istart2 = mid + 1, iend2 = end;  // �����ұ�Ԫ�صĵ�һ�����һ��Ԫ�ص�λ�á�

	_mergesort(arr, arrtmp, istart1, iend1);   // ���������Ԫ�صݹ�����
	_mergesort(arr, arrtmp, istart2, iend2);   // �������ұ�Ԫ�صݹ�����

	int ii = start; // ����������arrtmp�ļ�������

					// �����������������кϲ�������������arrtmp�С�
	while (istart1 <= iend1 && istart2 <= iend2)
		arrtmp[ii++] = arr[istart1] < arr[istart2] ? arr[istart1++] : arr[istart2++];

	// ���������������Ԫ��׷�ӵ����������顣
	while (istart1 <= iend1) arrtmp[ii++] = arr[istart1++];

	// ���ұ�����������Ԫ��׷�ӵ����������顣
	while (istart2 <= iend2) arrtmp[ii++] = arr[istart2++];

	// ������������arrtmp�е�Ԫ�ظ��Ƶ�arr�С�
	memcpy(arr + start, arrtmp + start, (end - start + 1)*sizeof(int));
}
/**
 * �鲢���򣺵ݹ�ʵ��
	
 */
void mergeSort(int *arr, unsigned int len)
{
	if (len < 2) return;  // С������Ԫ�ز���Ҫ����

	int *arrtmp = new int[len];   // ����һ���������������ͬ��С�����顣

	_mergesort(arr, arrtmp, 0, len - 1);  // ���õݹ麯����������
}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

/**
 * n �����鳤��
 * i �� ��ά���ڵ���±�
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
	//����  O(n)
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}
	//����
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
	if (len < 2) return; // ����С��2��Ԫ�ز���Ҫ����

	int ii;    // ����������ļ�������
	int jj;    // ÿ�������Ԫ��λ�ü�������
	int itmp;  // �Ƚ�����Ԫ�ش�Сʱ����λ���õ�����ʱ������

			   // 44,3,38,5,47,15,36,26,27,2,46,4,19,50,48  
	for (ii = len - 1; ii > 0; ii--)  // һ������len-1�˱Ƚϡ�
	{
		for (jj = 0; jj < ii; jj++)  // ÿ��ֻ��Ҫ�Ƚ�0......ii֮���Ԫ�أ�ii֮���Ԫ�����Ѿ�����õġ�
		{
			if (arr[jj] > arr[jj + 1])  // ���ǰ���Ԫ�ش��ں����Ԫ�أ��򽻻���λ��λ�á�
			{
				itmp = arr[jj + 1];
				arr[jj + 1] = arr[jj];
				arr[jj] = itmp;
			}
		}
	}
}

// Ͱ����������������arr�Ǵ�����������׵�ַ��len������Ԫ�صĸ�����
void bucketSort(int arr[], unsigned int len)
{
	int buckets[5][5];   // �������Ͱ��
	int bucketssize[5];  // ÿ��Ͱ��Ԫ�ظ����ļ�������

						 // ��ʼ��Ͱ��Ͱ��������
	memset(buckets, 0, sizeof(buckets));
	memset(bucketssize, 0, sizeof(bucketssize));

	// ������arr�����ݷ���Ͱ�С�
	int ii = 0;
	for (ii = 0; ii < len; ii++)
	{
		buckets[arr[ii] / 10][bucketssize[arr[ii] / 10]++] = arr[ii];
	}

	// ��ÿ��Ͱ����ð������
	for (ii = 0; ii < 5; ii++)
	{
		bubblesort(buckets[ii], bucketssize[ii]);
	}

	// ��ÿ��Ͱ�е�������䵽����arr�С�
	int jj = 0, kk = 0;
	for (ii = 0; ii < 5; ii++)
	{
		for (jj = 0; jj < bucketssize[ii]; jj++)
			arr[kk++] = buckets[ii][jj];
	}
}

void _radixSort(int *arr, unsigned int len, int exp)
{
	
	int *result = (int *)malloc(sizeof(int) * len);       // ��Ŵ�Ͱ���ռ������ݵ���ʱ���顣
	int buckets[10] = { 0 };   // ��ʼ��10��Ͱ��
	
	for (int i = 0; i < len; i++)
	{
		buckets[(arr[i] / exp) % 10]++;
	}

	for (int j = 1; j < 10; j++)
		buckets[j] = buckets[j] + buckets[j - 1];

	// ��arr�е�Ԫ����䵽result�С�
	for (int k = len - 1; k >= 0; k--)
	{
		int iexp = (arr[k] / exp) % 10;
		result[buckets[iexp] - 1] = arr[k];
		buckets[iexp]--;
	}

	// ������õ�����result���Ƶ�����arr�С�
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
	 * ��������Radix sort)��Ͱ�������չ�����Ļ���˼���ǣ���������λ���и�ɲ�ͬ�����֣�Ȼ��ÿ��λ���ֱ�Ƚϡ�
	 ���������ǣ������д��Ƚ���ֵͳһΪͬ������λ���ȣ���λ�϶̵���ǰ�油�㡣
	 Ȼ�󣬴����λ��ʼ�����ν���һ���������������λ����һֱ�����λ������ɺ󣬾ͱ����һ���������С�
	 */
	int arr[] = { 144,203,738,905,347,215,836,26,527,602,946,504,219,750,848 };
	int len = sizeof(arr) / sizeof(int);

	radixSort(arr, len);  // ��������
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
	 * ������log (n)
		1. ��ȫ������ �� N[i]����ڵ㣺N[2i+1]   N[i]���ҽڵ㣺N[2i+2]   N[i]�ĸ��ڵ㣺N[(i-1)/2]
		2. ������ÿ������ֵ�����ڻ������������������ֵ��Ϊ����ѣ�
		����ÿ������ֵ��С�ڻ���������Һ��ӽ���ֵ����ΪС���ѡ�
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