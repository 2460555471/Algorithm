#include<iostream>
using namespace std;

int mat[10] = { 2, 5, 1, 8, 0, 4, 2, 5, 7, 4};	//要经过排序的数组
int temp[10];//存放临时的数据

int num_ans = 0;//存放逆序数
void merge(int begin,int mid,int end)
{
	int i = begin, j = mid + 1;
	int k = begin;
	for (; i <= mid&&j <= end;)
	{
		if (mat[i] > mat[j])
		{
			num_ans += j - k;
			temp[k++] = mat[j++];
		}
		else
		{
			temp[k++] = mat[i++];
		}
	}
	while (i <= mid)temp[k++] = mat[i++];
	while (j <= end)temp[k++] = mat[j++];
	for (i = begin; i <= end; i++)
	{
		mat[i] = temp[i];
	}
}
void mergeSort(int begin, int end)
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		mergeSort(begin, mid);
		mergeSort(mid + 1, end);
		merge(begin, mid, end);
	}
}
int main()
{
	int n = 10;
	mergeSort(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << mat[i] << " ";
	}
	cout << endl << num_ans;//输出逆序数

	return 0;
}