#include <iostream>
using namespace std;

int extgcd(int a, int b, int &x, int &y)//扩展欧几里得算法
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		int d=extgcd(b, a%b, x, y);
		int temp = x;
		x = y;
		y = temp - a / b*y;
		return d;
	}
}

int main()
{
	int a=15, b=12, x, y,d;
	
	d = extgcd(a, b, x, y);

	cout <<x<<"  "<<y<<"    "<<d<<endl;

	return 0;
}
