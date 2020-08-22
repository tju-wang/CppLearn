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

//ð������
void swap(int *arr, int i, int j)
{
	int tmp = arr[j];
	arr[j] = arr[i];
	arr[i] = tmp;
}
//ð������
void bubbleSort(int *arr,int len)
{
	int i, j;
	bool flag = true;
	for (i = 0; i < len; ++i)
	{
		flag = false;	//���������־
		for (j = len - 1; j > i; --j)
		{
			if (arr[j-1] > arr[j])	//��С�Ļ���ǰ��  ǰ��Ԫ�����Ƚ�
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

//ֱ�Ӳ�������
void insertSort(int *arr, int len)
{
	int i, j;
	for (i = 1; i < len; ++i)
	{
		if (arr[i] < arr[i - 1])	//Ϊarr[i]��Ӧ�ò����λ��
		{
			int tmp = arr[i];	//��¼arr[i]
			for (j = i - 1; arr[j] > tmp; j--)	//��arr[i]�Ƚ�  �����Ƹ���Ԫ��
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

//ϣ������
void shellSort(int *arr,int len)
{
	for (int h = len / 2; h > 0; h /= 2)	//ÿ�ν����������С����
	{
		for (int i = h; i < len; ++i)
		{
			int tmp = arr[i];
			int k = 0;
			for (k = i - h; k >= 0 && tmp < arr[k]; k -= h)	//�����ִ��˳��  1. k>=0 && tmp < arr[k]����������ѭ������ֵ����  ��ִ����k = k-h(��ʱ��for��ߵ�arr[k+h]�൱��arr[k])
			{
				arr[k + h] = arr[k];	//����
			}
			arr[k + h] = tmp;	//������
		}
	}
}

void test_shellSort(int *arr, int len)
{
	arrPrint(arr, len);
	shellSort(arr, len);
	arrPrint(arr, len);
}


//������
void heapSort(int *arr,int len)
{
	priority_queue<int,vector<int>, greater<int>> p_queue;	//Ĭ�ϴ󶥶�  queue�����ݼ�  ��Ԫ�����
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

void merSort(int *arr, int left, int right)	//���ֱ��Ԫ������  ��ʼ�ϲ�  �ȴﵽС��Χ����֮����в�������
{
	if (left < right) //left��rightС1  �򱾴ν���ѭ������һ�β������
	{
		int mid = (left + right) / 2;	//���м�֣�ֻ���ܳ����ұ߶�һ�����ݵ����
		merSort(arr, left, mid);	//���ϵݹ�ֽ�
		merSort(arr, mid+1, right);
		merge(arr, left, mid, right);	//�ϲ�
	}//����������  ����  merge�����������ڵ�����Ԫ�ؿ�ʼ
}

void merge(int *arr, int left, int mid, int right)	//�������ݺϲ�
{
	int *a = new int[right - left + 1];	//��������
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right)	//����������  ��С�ķŵ�a�� ֻҪ��һ��������ޣ��˳�
	{
		if (arr[i] < arr[j])
			a[k++] = arr[i++];
		else
		{
			a[k++] = arr[j++];
		}
	}
	while (i <= mid)	a[k++] = arr[i++];	//�鿴�˳������ǲ���i����mid
	while (j <= right) a[k++] = arr[j++];	//��֤mid+1 �� right��Ԫ�ظ�����a����
	for (i = 0; i < k; ++i)	//��arr���ź����ֵ
	{
		arr[left++] = a[i];
	}
	delete[] a;
}

//�鲢����ǵݹ�汾
void MergeSortFeiDiGui(int *arr,int len)
{
	int i = 1;
	for (i=1; i < len; i += i)	//�൱�ڰ���˳��  ��arr�ֳɺö����
	{
		int left = 0;
		int mid = left + i - 1;
		int right = mid + i;	
		while (right < len)	//�˳�����ʱ  �ұ߽絽��len
		{
			merge(arr, left, mid, right);
			left = right + 1;	//����left��right  mid֮��������кϲ�  ģ��ݹ�Ĺ���  i��Ԫ��Ϊһ�飬����merge
			mid = left + i - 1;
			right = mid + i;
		}
		if (left < len && mid < len)	/*���ʣ��Ĳ���  ��Ҫ�ϲ�������ÿ�����ݶ����Ա��ֵĸոպã�
										����Ĳ��ֳܷ�i��һ��ģ�ʣ���Ԫ��Ҫ����һ��merge */
		{
			merge(arr, left, mid, len - 1);
		}
	}
}

//��������
void QuickSort(int *arr, int len)
{
	quickSort(arr, 0, len - 1);
}
void quickSort(int *arr, int low,int high)
{
	int pivot;
	if (low < high)
	{
		pivot = partition(arr, low, high);	//ȡ��Ŧֵ

		quickSort(arr, low, pivot-1);
		quickSort(arr, pivot + 1, high);
	}
}
int partition(int *arr, int low,int high)
{
	//ѡȡarr[0]Ϊ��Ŧ
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
