#include<iostream>
using namespace std;
const int V = 5;
const int INF = 99999;
/*
Prim的这个函数和Dijskra的一样
*/
int minDistance(int dist[], bool isInclude[])
{
	int min = INF, index;
	for (int i = 0; i < V; i++)
	{
		if (!isInclude[i] && min>dist[i])
		{
			min = dist[i];
			index = i;
		}
	}
	return index;
}
void primMST(int graph[][V])
{
	int dist[V];
	bool isInclude[V];
	int father[V];
	for (int i = 0; i < V; i++)
	{
		dist[i] = INF;
		isInclude[i] = false;
	}
	dist[0] = 0;
	father[0] = -1;
	for (int count = 0; count < V - 1; count++)
	{
		int u = minDistance(dist, isInclude);
		isInclude[u] = true;
		for (int i = 0; i < V; i++)
		{
			if (!isInclude[i] && graph[u][i] && dist[i]>graph[u][i])//和Dijiskra也就这里不一样了
			{
				dist[i] = graph[u][i];
				father[i] = u;
			}
		}
	}
	for (int i = 1; i < V; i++)
	{
		cout << father[i] << " "<<i<<"       "<<endl ;
	}
}
int main()
{
	int graph[V][V] = 
	{   
		{ 0, 2, 0, 6, 0 },
		{ 2, 0, 3, 8, 5 },
		{ 0, 3, 0, 0, 7 },
		{ 6, 8, 0, 0, 9 },
		{ 0, 5, 7, 9, 0 },
	};
	primMST(graph);
	return 0;
}