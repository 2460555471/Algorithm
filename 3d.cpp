//#include<iostream>
//#include<cstring>
//#include<string>
//#include<cstdio>
//#include<stack>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//
//int mat[110][110];
//int arr[110];
//
//int maxsun(int n)
//{
//	int dp[110];
//	memset(dp, 0, sizeof(dp));
//	dp[0] = arr[0];
//	int maxvalue = dp[0];
//	for (int i = 1; i < n; i++)
//	{
//		if (dp[i - 1] < 0) {
//			dp[i] = arr[i];
//		}
//		else
//		{
//			dp[i] = dp[i - 1] + arr[i];
//		}
//		if (dp[i] > maxvalue)
//		{
//			maxvalue = dp[i];
//		}
//
//	}
//	return maxvalue;
//}
//int  func(int n)
//{
//	int maxvalue=-128;
//	int temp;
//	for (int i = 0; i < n; i++)
//	{
//		memset(arr, 0, sizeof(arr));
//		for (int j = i; j < n; j++)
//		{
//			for (int k = 0; k < n; k++)
//			{
//				arr[k] = arr[k] + mat[j][k];
//			}
//			if (maxvalue < (temp=maxsun(n)))
//			{
//				maxvalue = temp;
//			}
//		}
//	}
//	return maxvalue;
//}
//
//
//
//int main() {
//
//
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> mat[i][j];
//		}
//	}
//
//	cout << func(n) << endl;
//
//
//
//
//	return 0;
//
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
