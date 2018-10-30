//C:数组转换
//	查看 提交 统计 提问
//	总时间限制 : 1000ms 内存限制 : 65535kB
//	描述
//	有n个数字1, 2, 3…, n，由小至大依次放入栈。问是否存在一种出栈方式，使这n个数字出栈的顺序为a1, a2, …, an。
//
//	输入
//	第一行输入一个整数t，代表有t组测试数据
//	对于每组测试数据，第一行输入整数n，第二行输入n个数字：a1, a2, …, an
//	1 <= n <= 1000
//	输出
//	每组测试数据输出一行。
//	如果出栈顺序a1, a2, …, an是合法的，输出yes，否则输出no。
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<stack>

using namespace std;

int mat[1001];
int main()
{
	int t;
	int n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> mat[i];
		}
		stack<int> v;
		int k = 0;
		for (int i = 1; i <= n; i++)
		{
			v.push(i);
			while (!v.empty() && v.top() == mat[k])
			{
				v.pop();
				k++;
			}
		}
		if (!v.empty())
			cout << "no";
		else
			cout << "yes";
		cout << endl;

	}




	return 0;
}