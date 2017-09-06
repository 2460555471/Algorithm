#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int V = 7;
int graph[V][V];
void addEdge(int a, int b)
{
	graph[a][b] = 1;
	graph[b][a] = 1;
}

int dfn[V], low[V], ans[V];
int index=1;

void dfs(int n)
{
	dfn[n] = low[n] = index++;
	for (int i = 0; i < V; i++)
	{
		if (graph[n][i]==1)//等于其他值的两种情况，访问过这条边和不存在这条边
		{
			graph[n][i] = graph[i][n] = 2;//将当前边销毁
			if (dfn[i]==0)//新的父子边，注意index的原来初始状态，小心0
			{
				dfs(i);
				low[n] = min(low[n], low[i]);
				if (low[i]>=dfn[n])
				{
					ans[n]++;
				}
			}
			else//反父子边
			{
				low[n] = min(low[n], dfn[i]);
			}
		}
	}
}

int main()
{
	memset(graph, 0, sizeof(graph));
	addEdge(0, 1);
	addEdge(1, 2);
	addEdge(2, 3);
	addEdge(2, 5);
	addEdge(5, 3);
	addEdge(1, 4);
	addEdge(0, 4);
	addEdge(2, 6);

	int n = 4;
	dfs(n);
	ans[n]--;//初始节点总会多加一次，所以要减去
	int cnt = 0;
	for (int i = 0; i < V; i++)
	if (ans[i]>0)
	{
		cout << i << " ";
		cnt++;
	}
	cout << endl<<cnt;
	return 0;
}