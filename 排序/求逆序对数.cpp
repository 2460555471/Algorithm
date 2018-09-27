//http://algorithm.openjudge.cn/algorithmc/A/

#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int mat[200];
int temp[200];
int ni_num = 0;

void merge(int a, int b, int c, int d)
{
	memset(temp, 0, sizeof(temp));

	int i = a, j = c;
	int k = a;
	while (i <= b && j <= d)
	{
		if (mat[i] > mat[j])
		{
			temp[k++] = mat[j++];
			ni_num += j - k;     //在这里容易出现错误
		}
		else
		{
			temp[k++] = mat[i++];
		}
	}
	while (i <= b)
	{
		temp[k++] = mat[i++];
	}
	while (j <= d)
	{
		temp[k++] = mat[j++];
	}

	for (int i = a; i <= d; i++)
	{
		mat[i] = temp[i];
	}



}
void mergesort(int a, int b)
{
	if (a >= b)
		return;
	else
	{
		int mid = (a + b) / 2;
		mergesort(a, mid);
		mergesort(mid + 1, b);
		merge(a, mid, mid + 1, b);
	}
}


int main()
{
	int n;
	while (cin >> n&&n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> mat[i];
		}
		ni_num = 0;
		mergesort(0, n - 1);
		cout << ni_num << endl;

	}



	return 0;
}

