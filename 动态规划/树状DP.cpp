#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<climits>
using namespace std;

//http://poj.org/problem?id=2342
//树状DP

int t;
bool visited[6001];
int father[6001];//存储二叉树
int dp[6001][2];//存储二叉树每个节点的值
void dfs(int node)
{
	visited[node] = true;
	for (int i = 1; i <= t; i++)
	{
		if (!visited[i] && father[i] == node)
		{
			dfs(i);

			dp[node][0] += max(dp[i][0], dp[i][1]);
			dp[node][1] += dp[i][0];

		}
	}
}

int main()
{
	int n,i,j,root;
	while (cin >> n)
	{
		t = n;
		memset(dp, false, sizeof(dp));
		for (int i = 1; i <= n; i++)
		{
			cin >> dp[i][1];
		}

		while (cin >> i >> j&&i+j>0)
		{
			father[i] = j;
			root = j;
		}

		memset(visited, false, sizeof(visited));
		
		dfs(root);
		cout << max(dp[root][0], dp[root][1]);



	}

	return 0;
}