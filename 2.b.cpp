#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;



//蝴蝶问题，并查集
int mat[2010];

int find(int x) {
	int temp = x;
	while (mat[temp] != temp)
	{
		temp = mat[temp];
	}
	mat[x] = temp;
	return temp;
}
void unio(int a, int b)
{
	int x = find(a);
	int y = find(b);

	if (x != y)
	{
		mat[x] = y;
	}
}

bool judge(int a, int b, int t,int n)
{

	if (t == 0)//same
	{
		if (find(a) == find(n + b) || find(b) == find(n + a))
		{
			return false;
		}
	}
	else
	{
		if (find(a) == find(b) || find(n+a) == find(n + b))
		{
			return false;
		}
	}
	return true;

}

void insrt(int a, int b, int t, int n)
{
	if (t == 0)//same
	{
		unio(a, b);
		unio(n+a, n+b);
	}
	else
	{
		unio(a, n+b);
		unio(b, n + a);
	}

}


int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		int a, b, t;
		int i;
		for (i = 0; i < 2 * n; i++)
		{
			mat[i] = i;
		}

		int flag = 1;
		for (i = 0; i < m; i++)
		{
			scanf("%d%d%d", &a, &b, &t);

			if (judge(a, b, t, n))
			{
			
				insrt(a, b, t, n);
			}
			else
			{
				flag = 0;
				
			}

		}
		if (flag == 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}





	}

	return 0;
}