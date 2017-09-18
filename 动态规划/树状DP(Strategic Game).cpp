#include<cstdio>  
#include<vector>  
#include<map>  
#include<stdlib.h>  
#include<math.h>  
#include<cstring>  
#include<string>  
#include<list>  
#include<climits>  
#include<algorithm>  
#include<iostream>  
using namespace std;

//Strategic Game
//http ://acm.hdu.edu.cn/showproblem.php?pid=1054

//题意就是在一棵树中，选取一些结点每个结点都可以监管连接自己的所有边，
//问最少选取多少个结点可以让所有边都被监管起来。
list<int> *adj;
bool *visited;
int dp[1500][2];
void dfs(int root)
{
	
	visited[root] = true;
	list<int>::iterator it;
	for (it = adj[root].begin(); it != adj[root].end(); it++)
	{
		if (!visited[*it])
		{
			dfs(*it);

			dp[root][0] += dp[*it][1];
			dp[root][1] += min(dp[*it][1], dp[*it][0]);

		}
	}
}

int main()
{
	int n,a,b,temp;
	while (cin >> n)
	{
		adj = new list<int>[n];
		visited = new bool[n];
		memset(visited, false, n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d:(%d)", &a, &b);
			for (int j = 0; j < b; j++)
			{
				cin >> temp;
				adj[a].push_back(temp);
				adj[temp].push_back(a);
			}
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < 1500; i++)
		{
			dp[i][1] = 1;
		}
		visited[0] = true;
		dfs(0);

		cout << min(dp[0][0], dp[0][1]) << endl;

	}

	return 0;
}