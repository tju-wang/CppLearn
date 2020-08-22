#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <algorithm>
#include<functional>


void test_BubbleSort(int *arr, int len);
void bubbleSort(int *arr, int len);
void arrPrint(int *arr, int len);
void test_insertSort(int *arr, int len);
void test_shellSort(int *arr, int len);
void test_heapSort(int *arr, int len);

void mergeSort(int *arr, int len);
void merge(int *arr, int left, int mid, int right);
void merSort(int *arr, int left, int right);
void MergeSortFeiDiGui(int *arr, int len);

void QuickSort(int *arr, int len);
void quickSort(int *arr, int low, int high);
int partition(int *arr, int low, int high);

int main()
{
	int arr[10] = { 2,5,9,6,7,8,5,1,3 };
	int len = sizeof(arr) / sizeof(int);
	//test_BubbleSort(arr, len);
	//test_insertSort(arr, len);
	//test_shellSort(arr, len);
	//test_heapSort(arr, len);
	arrPrint(arr, len);
	//MergeSortFeiDiGui(arr, len);
	QuickSort(arr, len);
	arrPrint(arr, len);

	return 0;
}

//冒泡排序
void swap(int *arr, int i, int j)
{
	int tmp = arr[j];
	arr[j] = arr[i];
	arr[i] = tmp;
}
//冒泡排序
void bubbleSort(int *arr,int len)
{
	int i, j;
	bool flag = true;
	for (i = 0; i < len; ++i)
	{
		flag = false;	//设置有序标志
		for (j = len - 1; j > i; --j)
		{
			if (arr[j-1] > arr[j])	//将小的换到前边  前后元素做比较
			{
				swap(arr, j-1, j);
				flag = true;
			}
		}
	}
}
void test_BubbleSort(int *arr,int len)
{
	arrPrint(arr, len);
	bubbleSort(arr, len);
	arrPrint(arr, len);
}

//直接插入排序
void insertSort(int *arr, int len)
{
	int i, j;
	for (i = 1; i < len; ++i)
	{
		if (arr[i] < arr[i - 1])	//为arr[i]找应该插入的位置
		{
			int tmp = arr[i];	//记录arr[i]
			for (j = i - 1; arr[j] > tmp; j--)	//和arr[i]比较  并后移各个元素
				arr[j + 1] = arr[j];
			arr[j + 1] = tmp;
		}
	}
}
void test_insertSort(int *arr, int len)
{
	arrPrint(arr, len);
	insertSort(arr, len);
	arrPrint(arr, len);
}

//希尔排序
void shellSort(int *arr,int len)
{
	for (int h = len / 2; h > 0; h /= 2)	//每次将排序分组缩小两倍
	{
		for (int i = h; i < len; ++i)
		{
			int tmp = arr[i];
			int k = 0;
			for (k = i - h; k >= 0 && tmp < arr[k]; k -= h)	//搞清楚执行顺序  1. k>=0 && tmp < arr[k]成立，进入循环，数值交换  且执行了k = k-h(此时，for外边的arr[k+h]相当于arr[k])
			{
				arr[k + h] = arr[k];	//交换
			}
			arr[k + h] = tmp;	//不交换
		}
	}
}

void test_shellSort(int *arr, int len)
{
	arrPrint(arr, len);
	shellSort(arr, len);
	arrPrint(arr, len);
}


//堆排序
void heapSort(int *arr,int len)
{
	priority_queue<int,vector<int>, greater<int>> p_queue;	//默认大顶堆  queue单调递减  首元素最大
	for (int i = 0; i < len; ++i)
	{
		p_queue.push(arr[i]);
	}
	for (int i = 0; i < len; ++i)
	{	
		arr[i] = p_queue.top();
		p_queue.pop();
	}
}

void test_heapSort(int *arr, int len)
{
	arrPrint(arr, len);
	heapSort(arr, len);
	arrPrint(arr, len);
}

void mergeSort(int *arr,int len)
{
	merSort(arr, 0, len-1);
}

void merSort(int *arr, int left, int right)	//拆分直到元素相邻  开始合并  先达到小范围有序，之后进行插入排序
{
	if (left < right) //left比right小1  则本次进入循环，下一次不会进入
	{
		int mid = (left + right) / 2;	//从中间分，只可能出现右边多一个数据的情况
		merSort(arr, left, mid);	//不断递归分解
		merSort(arr, mid+1, right);
		merge(arr, left, mid, right);	//合并
	}//不满足条件  返回  merge操作将从相邻的两个元素开始
}

void merge(int *arr, int left, int mid, int right)	//两组数据合并
{
	int *a = new int[right - left + 1];	//辅助排序
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right)	//从左到又整理  将小的放到a中 只要有一个到达界限，退出
	{
		if (arr[i] < arr[j])
			a[k++] = arr[i++];
		else
		{
			a[k++] = arr[j++];
		}
	}
	while (i <= mid)	a[k++] = arr[i++];	//查看退出条件是不是i到了mid
	while (j <= right) a[k++] = arr[j++];	//保证mid+1 到 right的元素个数在a当中
	for (i = 0; i < k; ++i)	//对arr赋排好序的值
	{
		arr[left++] = a[i];
	}
	delete[] a;
}

//归并排序非递归版本
void MergeSortFeiDiGui(int *arr,int len)
{
	int i = 1;
	for (i=1; i < len; i += i)	//相当于按照顺序  将arr分成好多个组
	{
		int left = 0;
		int mid = left + i - 1;
		int right = mid + i;	
		while (right < len)	//退出条件时  右边界到达len
		{
			merge(arr, left, mid, right);
			left = right + 1;	//跟新left与right  mid之后继续进行合并  模拟递归的过程  i个元素为一组，进行merge
			mid = left + i - 1;
			right = mid + i;
		}
		if (left < len && mid < len)	/*最后剩余的部分  还要合并，不是每组数据都可以被分的刚刚好，
										其余的不能分成i个一组的，剩余的元素要进行一次merge */
		{
			merge(arr, left, mid, len - 1);
		}
	}
}

//快速排序
void QuickSort(int *arr, int len)
{
	quickSort(arr, 0, len - 1);
}
void quickSort(int *arr, int low,int high)
{
	int pivot;
	if (low < high)
	{
		pivot = partition(arr, low, high);	//取枢纽值

		quickSort(arr, low, pivot-1);
		quickSort(arr, pivot + 1, high);
	}
}
int partition(int *arr, int low,int high)
{
	//选取arr[0]为枢纽
	int pivot = arr[low];
	while (low<high)
	{
		while (low<high&&arr[high] >= pivot)
			high--;
		swap(arr, high, low);	
		while (low<high&&arr[low] <= pivot)
			low++;
		swap(arr, low, high);
	
	}

	return low;
}


void arrPrint(int *arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}
