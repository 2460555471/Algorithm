//#include<iostream>
//#include<cstring>
//#include<string>
//#include<cstdio>
//#include<stack>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//
//int mat[210][210];
//
//int func(string str1, string str2)
//{
//	for (int i = 0; i < str1.length(); i++)
//	{
//		for (int j = 0; j < str2.length(); j++)
//		{
//			if (str1[i] == str2[j])
//			{
//				mat[i+1][j+1] = mat[i][j] + 1;
//			}
//			else
//			{
//				mat[i+1][j+1] = max(mat[i][j+1], mat[i+1][j]);
//			}
//		}
//	}
//
//	return mat[str1.length()][str2.length()];
//}
//int main() {
//
//	string str1, str2;
//	while (cin >> str1 >> str2)
//	{
//
//		memset(mat, 0, sizeof(mat));
//		cout << func(str1, str2) << endl;
//	}
//
//
//
//	return 0;
//}