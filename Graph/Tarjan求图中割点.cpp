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
		if (graph[n][i]==1)//��������ֵ��������������ʹ������ߺͲ�����������
		{
			graph[n][i] = graph[i][n] = 2;//����ǰ������
			if (dfn[i]==0)//�µĸ��ӱߣ�ע��index��ԭ����ʼ״̬��С��0
			{
				dfs(i);
				low[n] = min(low[n], low[i]);
				if (low[i]>=dfn[n])
				{
					ans[n]++;
				}
			}
			else//�����ӱ�
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
	ans[n]--;//��ʼ�ڵ��ܻ���һ�Σ�����Ҫ��ȥ
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