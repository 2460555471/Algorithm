//F:区间合并
//	查看 提交 统计 提问
//	总时间限制 : 1000ms 内存限制 : 65536kB
//	描述
//	给定 n 个闭区间[ai; bi]，其中i = 1, 2, ..., n。任意两个相邻或相交的闭区间可以合并为一个闭区间。例如，[1; 2] 和[2; 3] 可以合并为[1; 3]，[1; 3] 和[2; 4] 可以合并为[1; 4]，但是[1; 2] 和[3; 4] 不可以合并。
//
//	我们的任务是判断这些区间是否可以最终合并为一个闭区间，如果可以，将这个闭区间输出，否则输出no。
//
//	输入
//	第一行为一个整数n，3 ≤ n ≤ 50000。表示输入区间的数量。
//	之后n行，在第i行上（1 ≤ i ≤ n），为两个整数 ai 和 bi ，整数之间用一个空格分隔，表示区间[ai; bi]（其中 1 ≤ ai ≤ bi ≤ 10000）。
//	输出
//	输出一行，如果这些区间最终可以合并为一个闭区间，输出这个闭区间的左右边界，用单个空格隔开；否则输出 no。
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;


typedef struct jian
{
	int a;
	int b;
}Jian;
vector<Jian> v;
bool cmp(const Jian &a, const Jian &b)
{
	return a.a<b.a;
}

int main()
{
	int T;
	cin >> T;
	int a, b;
	Jian temp;
	for (int i = 0; i < T; i++)
	{
		cin >> temp.a >> temp.b;
		v.push_back(temp);
	}

	sort(v.begin(),v.end(),cmp);
	int max_right = v[0].b;

	for (int i = 1; i < T; i++)
	{
		max_right = max(max_right, v[i-1].b);
		if (v[i].a > max_right)
		{
			cout << "no";
			cout << endl;
			return 0;
		}
	}
	if (v[T - 1].b > max_right)
	{
		max_right = v[T - 1].b;
	}
	cout << v[0].a << " " << max_right << endl;
		

	return 0;
}