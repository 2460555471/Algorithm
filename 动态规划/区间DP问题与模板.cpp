#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<climits>
using namespace std;

//����DPģ��
//
//for (int l = 1; l <= n; l++)
//{
//	for (int i = 1; i <= n; i++)//����Ŀ�ͷ
//	{
//		int j = i + l - 1;//����Ľ�β
//		if (j > n)
//			break;
//		for (int k = i; k < j - 1; k++)
//		{
//			dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mat[k]);
//		}
//	}
//}
//poj1651������DP��������
//http://poj.org/problem?id=1651
int mat[102];
int dp[102][102];

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> mat[i];
		}
		memset(dp, 0, sizeof(dp));

		for (int l = 3; l <= n; l++)//���䳤��
		{
			for (int i = 1; i <= n-l+1; i++)//���俪ͷ
			{
				int j = i + l - 1;//�����β
				dp[i][j] = INT_MAX;
				for (int k = i + 1; k <= j - 1; k++)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + mat[k] * mat[i] * mat[j]);
				}

			}
		}
		cout << dp[1][n] << endl;

	}
	
	return 0;
}