#include<iostream>
#include<cstring>
#include<list>
using namespace std;
const int V1 = 4;
const int V2 = 4;
bool mat[V1][V2];
void addEdge(int a, int b)
{
	mat[a][b] = true;
}
int link[V2];//V2中某点的对应V1中的匹配
bool isvisited[V2];
bool dfs(int n)
{
	for (int i = 0; i < V2; i++)
	{
		if (mat[n][i] && !isvisited[i])
		{
			isvisited[i] = true;

			if (link[i] == -1 || dfs(link[i]))//注意初始值0和节点序号0之间的混淆
			{
				link[i] = n;
				return true;
			}
		}
	}
	return false;
}
int search()
{
	int count = 0;
	memset(link, -1, sizeof(link));
	for (int i = 0; i < V1; i++)
	{
		memset(isvisited, false, V2);

		if (dfs(i))//如果可以找到一条新的增广路径，则自增
			count++;
	}
	return count;
}
int main()
{
	addEdge(0, 0);
	addEdge(0, 1);
	addEdge(1, 0);
	addEdge(1, 3);
	addEdge(2, 1);
	addEdge(2, 3);
	addEdge(3, 2);
	cout << search()<<endl;
	for (int i = 0; i < V2; i++)
	{
		cout << link[i] << "    " << i << endl;
	}

	return 0;
}