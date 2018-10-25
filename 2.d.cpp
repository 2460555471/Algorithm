#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

//d  
//Radar Installation
//注意Y<0就不能通过了
class Node
{
public:
	double begin, end;
	Node(double a, double b)
	{
		this->begin = a;
		this->end = b;
	}
};
bool cmp1(const Node& a, const Node& b)
{
	if (a.end == b.end)
		return a.begin > b.begin;
	return a.end < b.end;
}

vector<Node> line;
Node sovle(int x, int y, int d) {

	double h = sqrt(d * d - y * y);

	return Node(x - h, x + h);
}
int main() {
	int t=1;
	int n, d;
	int x, y;
	bool flag = false;
	while (cin >> n >> d)
	{
		line.clear();
		flag = false;
		if (n == 0 && d == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			if (y <0 || d < 0||y>d)
			{
				flag = true;
				
			}
			else
			{
				line.push_back(sovle(x, y, d));
			}
		}
		if (flag == true)
		{
			cout << "Case " << t++ << ": " << -1 << endl;
		}
		if (flag == false)
		{
			sort(line.begin(), line.end(), cmp1);


			int count = 1;
			double cur = line[0].end;
			for (int i = 1; i < n; i++)
			{

				if (line[i].begin > cur)
				{
					count++;
					cur = line[i].end;
				}
			}
			cout << "Case " << t++ << ": " << count << endl;


		}
	

	}









	return 0;
}