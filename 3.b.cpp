//#include<iostream>
//#include<cstring>
//#include<string>
//#include<cstdio>
//#include<stack>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//
//
//int mat1[110];
//int mat2[110];
//int d[110];
//int func(int n)
//{
//	mat1[0] = 1;
//	int maxvalue;
//	for (int i = 1; i < n; i++)
//	{
//		maxvalue = -1;
//		for (int j = 0; j < i; j++)
//		{
//
//			if (d[j] < d[i])
//			{
//				maxvalue = max(maxvalue, mat1[j]);
//			}
//		}
//		if (maxvalue == -1)
//		{
//			mat1[i] = 1;
//		}
//		else
//		{
//			mat1[i] = maxvalue + 1;
//		}
//	}
//
//	mat2[n-1] = 1;
//	for (int i = n-1; i >=0; i--)
//	{
//		maxvalue = -1;
//		for (int j = n - 1; j > i; j--)
//		{
//
//			if (d[j] < d[i])
//			{
//				maxvalue = max(maxvalue, mat2[j]);
//			}
//		}
//		if (maxvalue == -1)
//		{
//			mat2[i] = 1;
//		}
//		else
//		{
//			mat2[i] = maxvalue + 1;
//		}
//
//	}
//
//	int reslut = 0;
//	for (int i = 0; i < n; i++)
//	{
//		mat1[i] = mat1[i] + mat2[i];
//		reslut = max(reslut, mat1[i]);
//	}
//	return n-(reslut-1);
//}
//int main() {
//
//	//freopen("Data.txt", "r", stdin);// 按顺序读入（仅此一行）
//
//	int n;
//	cin >> n;
//	memset(mat1, 0, sizeof(mat1));
//	memset(mat2, 0, sizeof(mat2));
//	for (int i = 0; i < n; i++)
//	{
//		cin >> d[i];
//	}
//	cout << func(n) << endl;
//
//
//
//
//	return 0;
//}