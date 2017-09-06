#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;

const int E = 5;//边数
const int V = 4;//顶点数
typedef struct
{
	int src;
	int dest;
	int weight;
}Egde;

bool cmp(Egde a, Egde b)
{
	return a.weight < b.weight;
}

int father[V];
int find(int x)//没有优化的并查集算法
{
	while (father[x] != x)
	{
		x = father[x];
	}
	return x;
}
void unio(int a, int b)
{
	int x = find(a);
	int y = find(b);
	father[x] = y;
}
void kruskal(Egde *edge)
{
	for (int i = 0; i < V; i++)
		father[i] = i;

	sort(edge, edge + E, cmp);

	for (int i = 0; i < E; i++)
	{
		if (find(edge[i].src) == find(edge[i].dest))
		{
			continue;
		}
		else
		{
			cout << edge[i].src << "  " << edge[i].dest<<endl;
			unio(edge[i].src, edge[i].dest);
		}
	}
}
int main()
{
	Egde *edge = new Egde[E];//5条边
	edge[0].src = 0;
	edge[0].dest = 1;
	edge[0].weight = 10;
	edge[1].src = 0;
	edge[1].dest = 2;
	edge[1].weight = 6;
	edge[2].src = 0;
	edge[2].dest = 3;
	edge[2].weight = 5;
	edge[3].src = 1;
	edge[3].dest = 3;
	edge[3].weight = 15;
	edge[4].src = 2;
	edge[4].dest = 3;
	edge[4].weight = 4;

	kruskal(edge);
	return 0;
}