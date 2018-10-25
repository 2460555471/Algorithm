#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;

int mat[101][101];
//E:Agri-Net
class node
{
public:
	int x, y, value;
	node(int x, int y, int value) {
		this->x = x;
		this->y = y;
		this->value = value;
	}
};
struct cmp {
	bool operator() (const node &a, const node &b)
	{
		if (a.value < b.value)
			return false;
		else
			return true;
	}
};

int father[101];
void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		father[i] = i;
	}
}
int findfather(int x)
{	
	int temp=x;
	while (father[x] != x)
	{
		x=father[x];
	}
	father[temp] = x;
	return x;
}
void unio(int x, int y)
{
	int a = findfather(x);
	int b = findfather(y);
	if (a != b)
	{
		father[a] = b;
	}
}
int main() {

	int n,value;
	while (scanf("%d", &n) != EOF)
	{
		priority_queue<node, vector<node>, cmp > p;
		init(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &value);
				if (i < j)
				{
					p.push(node(i, j, value));
					
				}
				
			}
		}
		int count = 0;
		bool flag = true;
		for (int i = 0; i < n - 1; i++)
		{
			flag = true;
			while (flag==true)
			{
				node min = p.top();
				if (findfather(min.x) != findfather(min.y))
				{
					count += min.value;
					unio(min.x, min.y);
					flag = false;
				}
				p.pop();
			}
			

		}
		cout << count << endl;





	}








	return 0;
}

























