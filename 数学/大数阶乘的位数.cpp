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

		cout << (int)sum+1 << endl;//ע������Ϊʲô��������doubleȡֵ�������ɵ�ʹ��ceil��������ʹ��
	
	}
	return 0;
}