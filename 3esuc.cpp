//#include<iostream>
//#include<cstring>
//#include<string>
//#include<cstdio>
//#include<stack>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//int mat[100005];
//int pre[100005];
//int  post[100005];
//
//
//int func(int n) {
//	memset(pre, 0, sizeof(pre));
//	memset(post, 0, sizeof(post));
//	pre[0] = 0;
//	int minvalue=mat[0];
//	for (int i = 1; i < n; i++)
//	{
//		pre[i] = max(pre[i - 1], mat[i] - minvalue);
//		if (minvalue > mat[i])
//		{
//			minvalue = mat[i];
//		}
//	}
//
//	post[n-1] = 0;
//	int maxvalue = mat[n - 1];
//	for (int i = n - 2; i >= 0; i--)
//	{
//		post[i] = max(post[i + 1], maxvalue - mat[i]);
//		if (maxvalue < mat[i])
//		{
//			maxvalue = mat[i];
//		}
//	}
//	int result=pre[0]+post[0];
//	for (int i = 0; i < n; i++)
//	{
//		result = max(pre[i] + post[i], result);
//	}
//	return result;
//
//
//
//}
//int  main()
//{
//	//freopen("Data.txt", "r", stdin);// 按顺序读入（仅此一行）
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d", &mat[i]);
//			//cin >> mat[i];
//		}
//		cout << func(n) << endl;
//
//
//
//	}
//
//
//
//	return 0;
//
//}