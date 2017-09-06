#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;

const int V = 4;
const int INF = 99999;

int path[V][V];//pathΪ·��

//���ֵķ��������·��
void pathSolution(int i, int j)//ע��Ӻ�һ���ڵ�ʵ���ϲ�û�����
{
	int k;
	if (path[i][j] == i)
	{
		cout << i << " ";
	}
	else
	{
		k = path[i][j];
		pathSolution(i, k);
		pathSolution(k, j);

	}
}
void Floyd(int graph[][V])
{
	int dist[V][V];
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			dist[i][j] = graph[i][j];
			path[i][j] = i;//��ʼ��Ϊ��һ��·���ʼ�ĵ�
		}
	}


	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (dist[i][j]>dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = k;//i��j֮�����һ��k,������i��k֮��/k��j֮�䶼������µ�k
				}

			}
		}
	}
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << i << "----->" << j << ":    ";
			pathSolution(i, j);
			cout << j<<"       ";
			cout<<dist[i][j];
			cout << endl;
		}
		
	}

	
}



int main()
{
	int graph[V][V] =
	{ 
		{ 0, 5, INF, 10 },
		{ 5, 0, 3, INF },
		{ INF, 3, 0, 1 },
		{ 10, INF, 1, 0 }
	};
	Floyd(graph);




	return 0;
}