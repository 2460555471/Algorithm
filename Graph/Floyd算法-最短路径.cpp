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

int path[V][V];//path为路径

//二分的方法来输出路径
void pathSolution(int i, int j)//注意队后一个节点实际上并没有输出
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
			path[i][j] = i;//初始化为最一条路径最开始的点
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
					path[i][j] = k;//i和j之间多了一个k,迭代着i和k之间/k和j之间都会更新新的k
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