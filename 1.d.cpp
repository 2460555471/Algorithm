//D:汉诺塔问题(Hanoi)
//	查看 提交 统计 提问
//	总时间限制 : 1000ms 内存限制 : 65535kB
//	描述
//	一、汉诺塔问题
//
//	有三根杆子A，B，C。A杆上有N个(N>1)穿孔圆盘，盘的尺寸由下到上依次变小。要求按下列规则将所有圆盘移至C杆： 每次只能移动一个圆盘； 大盘不能叠在小盘上面。 提示：可将圆盘临时置于B杆，也可将从A杆移出的圆盘重新移回A杆，但都必须遵循上述两条规则。
//
//	问：如何移？最少要移动多少次？
//
//	汉诺塔示意图如下：
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<stack>
#include<cstdio>
using namespace std;

void func(int n, char init,char temp,char dest)
{
	if (n == 1)
	{
		cout << n << ":" << init << "->" << dest << endl;
		return;
	}
	func(n - 1, init, dest, temp);
	cout << n << ":" << init << "->" << dest <<endl;
	func(n - 1, temp, init, dest);
}



int main()
{
	int n;
	char a, b ,c;
	cin >> n >> a >> b >> c;
	func(n, a, b, c);



	return 0;
}

