#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;

class Graph
{
public:
	int num;
	list<int> *adj;

	Graph(int num);
	void dfs(int n);
	void dfs_util(int n, bool *visited);
	void stack_dfs(int n);
	void bfs(int n);
	void addEdge(int a, int b);

};
Graph::Graph(int num)
{
	this->num = num;
	this->adj = new list<int>[num];
}
void Graph::dfs(int n)
{
	bool *visited = new bool[num];
	memset(visited, false, num);

	visited[n] = true;
	dfs_util(n,visited);

}
/*
深度优先遍历到某一节点的时候便先访问
然后对于它的一个一个的邻接点继续深度优先，主义更改的是visited[]
对某一点深搜则先标记该点
*/
void Graph::dfs_util(int n, bool *visited)
{
	cout << n << " ";
	list<int>::iterator it;
	for (it = adj[n].begin(); it != adj[n].end(); it++)
	{
		if (!visited[*it])
		{
			visited[*it] = true;
			dfs_util(*it, visited);
		}
	}

}
/*
基于栈的深度优先遍历注意每次取栈首元素的时候不能访问，而是应该在入栈的时候标记加访问
*/
void Graph::stack_dfs(int n)
{
	bool *visited = new bool[num];
	memset(visited, false, num);

	stack<int> s;
	s.push(n);
	visited[n] = true;
	cout << n << " ";
	while (!s.empty())
	{
		n = s.top();
		
		list<int>::iterator it;
		for (it = adj[n].begin(); it != adj[n].end(); it++)
		{
			if (!visited[*it])
			{
				visited[*it] = true;
				s.push(*it);
				cout << *it << " ";
				break;
			}
		}
		if (it == adj[n].end())
		{
			s.pop();
		}
	}
}
/*
初始化栈的时候src节点进栈，注意只要进栈了就要做标记
队首元素出栈的时候访问
邻接点一次性全部进栈
*/
void Graph::bfs(int n)
{
	bool *visited = new bool[num];
	memset(visited, false, num);
	queue<int> q;
	q.push(n);
	visited[n] = true;

	while (!q.empty())
	{
		n = q.front();
		q.pop();
		cout << n << " ";
		list<int>::iterator it;
		for (it = adj[n].begin(); it != adj[n].end(); it++)
		{
			if (!visited[*it])
			{
				visited[*it] = true;
				q.push(*it);
			}
		}
	}
}
void Graph::addEdge(int a, int b)
{
	adj[a].push_back(b);
	adj[b].push_back(a);
}
int main()
{
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(0, 3);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(2, 4);
	g.stack_dfs(0);



	return 0;
}
