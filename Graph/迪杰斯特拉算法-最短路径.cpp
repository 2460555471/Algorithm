#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;

const int V = 9;
const int INF = 99999;


/*
��δ����Ľڵ���ѡ�������̵ģ����ؽڵ�����
*/
int minDistance(int dist[], bool isjoin[])
{
	int min = INF, index;
	for (int i = 0; i < V; i++)
	{
		if (!isjoin[i])
		{
			if (dist[i]<= min)
			{
				min = dist[i];
				index = i;
			}
		}
	}
	return index;
}


void dijkstra(int graph[][V], int n)
{
	int dist[V];
	bool isjoin[V];


	for (int i = 0; i < V; i++)
	{
		dist[i] = INF;
		isjoin[i] = false;
	}

	dist[n] = 0;
	for (int count = 0; count < V-1; count++)//src�ڵ���Ѿ��ҵ��ˣ�ûһ��ѭ���ҵ�һ���ڵ㵽isjoin
	{
		int u = minDistance(dist, isjoin);

		isjoin[u] = true;
		//����dist����
		for (int i = 0; i < V; i++)
		{
			if (!isjoin[i] && graph[u][i] && dist[u] != INF&&dist[i] > dist[u] + graph[u][i])//�ڱ������ʱ���Ȼ�ѷ���д����
			{
				dist[i] = dist[u] + graph[u][i];
			}
		}
	}

	for (int i = 0; i < V; i++)
	{
		cout << dist[i] << " ";
	}

}




int main()
{
	int graph[V][V] = { 
	{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
	{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
	{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
	{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
	{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
	{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
	{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
	{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	};

	dijkstra(graph, 0);

	return 0;
}