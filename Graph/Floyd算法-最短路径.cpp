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

void Floyd(int graph[][V])
{
	int dist[V][V];
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			dist[i][j] = graph[i][j];
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
				}

			}
		}
	}

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			cout<<dist[i][j]<<" ";
		}
		cout << endl;
	}
}


int main()
{
	int graph[V][V] =
	{ 
		{ 0, 5, INF, 10 },
		{ INF, 0, 3, INF },
		{ INF, INF, 0, 1 },
		{ INF, INF, INF, 0 }
	};
	Floyd(graph);




	return 0;
}