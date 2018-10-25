#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;

int father[1000010];


//并查集解决矩形从上到下移动问题

int findfather(int x)
{
	int temp = x;
	while (father[x] != x)
	{
		x = father[x];
	}
	father[temp] = x;
	return x;
}


void init(int n)
{
	for (int i = 0; i <= n*n+1; i++)
	{
		father[i] = -1;
	}
}

void unio(int x, int y)
{
	int a = findfather(x);
	int b = findfather(y);

	if (a != b)
	{
		father[a] = b;
	}
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		int x, y;
		int flag = true;
		int loc;
		cin >> n >> m;
		init(n);
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			loc = (x - 1)*n + y;
			if (flag == true)
			{
				father[loc] = loc;

				if (x == 1)
				{
					father[0] = 0;
					unio(loc,0);
				}
				if (x == n)
				{
					father[n*n + 1] = n * n + 1;
					unio(loc,n * n + 1);
				}
				if (y > 1 && father[loc - 1] != -1)
				{
					unio(loc, loc - 1);
				}
				if (x > 1 && father[loc - n] != -1)
				{
					unio(loc, loc-n);
				}
				if (y < n && father[loc +1] != -1)
				{
					unio(loc, loc + 1);
				}
				if (x < n && father[loc + n] != -1)
				{
					unio(loc, loc+n);
				}

				if ((father[0] != -1) && (father[n*n + 1] != -1) && (findfather(0) == findfather(n*n + 1)))
				{
					flag = false;
					cout << i + 1 << endl;
				}




			}

		}
		if (flag)
			cout << -1 << endl;
	}





	return 0;
}















