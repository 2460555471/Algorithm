#include<iostream>
#include<cstring>
#include<list>
using namespace std;

class Graph{

public:
	int num;
	list<int> *adj;//反向边存储结构
	list<int> *unti_adj;//正向边存储结构

	list<int> top_ans;
	Graph(int num);
	void addEdge(int a, int b);
	void Topological();
	void visit(int n, bool visited[]);

};
Graph::Graph(int numl)
{
	num = numl;
	this->adj = new list<int>[num];
	this->unti_adj = new list<int>[num];
}
void Graph::addEdge(int a, int b)
{
	this->adj[b].push_back(a);
	this->unti_adj[a].push_back(b);
}


void Graph::Topological()
{
	bool *visited = new bool[num];
	memset(visited, false, num);

	list<int> l;

	for (int i = 0; i < num; i++)
	{
		if (unti_adj[i].size() == 0)
			visit(i,visited);
			
	}

	list<int>::iterator it;
	for (it = top_ans.begin(); it != top_ans.end(); it++)//输出结果
	{
		cout << *it;
	}
}
void Graph::visit(int n,bool visited[])
{
	if (!visited[n])
	{
		visited[n] = true;

		list<int>::iterator it;
		for (it = adj[n].begin(); it != adj[n].end(); it++)
		{
			visit(*it, visited);
		}

		top_ans.push_back(n);
	}
}


int main()
{
	Graph g(5);

	g.addEdge(0, 1);
	g.addEdge(1, 3);
	g.addEdge(2, 1);
	g.addEdge(1, 4);
	g.addEdge(4, 3);
	g.Topological();


	return 0;
}