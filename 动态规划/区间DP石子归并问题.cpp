#include<stdio.h>  
#include<vector>  
#include<map>  
#include<stdlib.h>  
#include<math.h>  
#include<cstring>  
#include<climits>  
#include<algorithm>  
#include<iostream>  
using namespace std;


//石子归并问题
//http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=737
int mat[202];
int sum[202];
int dp[202][202];
int main()
{
	int n;
	while (cin >> n)
	{
		sum[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> mat[i];
			sum[i] = sum[i - 1] + mat[i];
		}

		for (int l = 2; l <= n; l++)//长度
		{
			for (int i = 1; i+l-1 <= n; i++)
			{
				int j = i + l - 1;
				dp[i][j] = INT_MAX;
				for (int k = i; k < j; k++)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]);
				}
			}
		}

		cout << dp[1][n] << endl;

	}

	return 0;
}