//
//#include <iostream>
//#include <cstdio>
//#include <cmath>
//#include<algorithm>
//
//using namespace std;
//const int INF = 1 << 30;
//int n, mat[9][9] = { 0 }, sum[9][9] = { 0 }, dp[9][9][9][9][15] = { 0 };
//
////直接计算矩形(y1, x1)(y2, x2)矩形分数平方
//
//int getsum(int y1, int x1, int y2, int x2) {
//	int a = sum[y2][x2] - sum[y2][x1 - 1] - sum[y1 - 1][x2] + sum[y1 - 1][x1 - 1];
//	return a * a;
//}
//
//int main() {
//	//freopen("Data.txt", "r", stdin);
//
//	cin >> n;
//	for (int i = 1; i <= 8; i++)
//		for (int j = 1; j <= 8; j++)
//			cin>>mat[i][j];
//
//	for (int i = 1; i <= 8; i++) {
//		for (int j = 1; j <= 8; j++)
//			sum[i][j] = sum[i][j - 1] + mat[i][j];
//		for (int j = 1; j <= 8; j++)
//			sum[i][j] += sum[i - 1][j];
//	}
//
//	for (int i1 = 1; i1 <= 8; i1++)
//		for (int j1 = 1; j1 <= 8; j1++)
//			for (int i2 = i1; i2 <= 8; i2++)
//				for (int j2 = j1; j2 <= 8; j2++)
//					dp[i1][j1][i2][j2][0] = getsum(i1, j1, i2, j2);
//
//	for (int i = 1; i < n; i++)
//		for (int i1 = 1; i1 <= 8; i1++)
//			for (int j1 = 1; j1 <= 8; j1++)
//				for (int i2 = i1; i2 <= 8; i2++)
//					for (int j2 = j1; j2 <= 8; j2++) {
//						dp[i1][j1][i2][j2][i] = INF;
//						for (int k = j1; k < j2; k++)
//							dp[i1][j1][i2][j2][i] = min(dp[i1][j1][i2][j2][i], min(dp[i1][j1][i2][k][i - 1] + dp[i1][k + 1][i2][j2][0], dp[i1][j1][i2][k][0] + dp[i1][k + 1][i2][j2][i - 1]));
//						for (int k = i1; k < i2; k++)
//							dp[i1][j1][i2][j2][i] = min(dp[i1][j1][i2][j2][i], min(dp[i1][j1][k][j2][i - 1] + dp[k + 1][j1][i2][j2][0], dp[i1][j1][k][j2][0] + dp[k + 1][j1][i2][j2][i - 1]));
//					}
//
//	double result = sqrt(double(dp[1][1][8][8][n - 1]) / n - double(sum[8][8] * sum[8][8]) / (n*n));
//	printf("%.3f\n", result);
//	return 0;
//}