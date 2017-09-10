#include<iostream>
#include<cmath>
using namespace std;
//hoj 1018
//http://acm.hdu.edu.cn/showproblem.php?pid=1018 
int main()
{
	int n;
	cin >> n;
	int t;
	double sum;
	while (n--)
	{
		cin >> t;
		sum = 0;

		for (int i = 2; i <= t; i++)
		{
			sum = sum + log10(i);
		}

		cout << (int)sum+1 << endl;//注意这里为什么这样，是double取值的误差造成的使得ceil函数不好使吗？
	
	}
	return 0;
}