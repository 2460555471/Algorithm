/*
判断给定的一个数组中的子集和能否为特定值sum
*/
#include<iostream>
using namespace std;

bool isSubsum(int mat[], int sum,int n)
{
	bool dp[100][100];
	memset(dp, false, sizeof(dp));
	for (int i = 0; i < n; i++)
	{
		dp[0][i] = 0;
		dp[i][0] = 1;
	}
	for (int i = 1; i < n; i++)//需要研究i-1这个是怎么定的
	{
		for (int j = 1; j < n; j++)
		{
			if (mat[i-1]>j)
				dp[i][j] = dp[i - 1][j];
			else
			{
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - mat[i-1]];
			}
		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}


	return dp[n - 1][n - 1];
}
int main()
{
	int a[] = { 1, 6, 3, 8, 9, 2, 67, 12 };
	int n = sizeof(a) / sizeof(int);
	int sum = 7;

	if (isSubsum(a, sum,n))
	{
		cout << "1"<<endl;
	}

	return 0;
}