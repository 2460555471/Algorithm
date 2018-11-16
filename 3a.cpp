#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <algorithm>  
using namespace std;
const double INF = 1e20;
const int N = 100005;

struct Point
{
	double x;
	double y;
}point[N];

int n;
int tmpt[N];

bool cmpxy(const Point& a, const Point& b)
{
	if (a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

bool cmpy(const int& a, const int& b)
{
	return point[a].y < point[b].y;
}

double dis(int i, int j)
{
	double a = point[i].x - point[j].x;
	double b = point[i].y - point[j].y;
	return sqrt(a*a + b * b);
}

double Closest_Pair(int left, int right)
{
	double d = INF;
	if (left == right)
		return d;
	if (left + 1 == right)
		return dis(left, right);
	int mid = (left + right) >> 1;
	double d1 = Closest_Pair(left, mid);
	double d2 = Closest_Pair(mid + 1, right);
	d = min(d1, d2);
	int i, j, k = 0;

	for (i = left; i <= right; i++)
	{
		if (fabs(point[mid].x - point[i].x) <= d)
			tmpt[k++] = i;
	}
	sort(tmpt, tmpt + k, cmpy);

	for (i = 0; i < k; i++)
	{
		for (j = i + 1; j < k && point[tmpt[j]].y - point[tmpt[i]].y < d; j++)
		{
			double d3 = dis(tmpt[i], tmpt[j]);
			if (d > d3)
				d = d3;
		}
	}
	return d;
}



int main()
{
	//freopen("Data.txt", "r", stdin);// 按顺序读入（仅此一行）
	int t;
	cin >> t;
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &point[i].x, &point[i].y);
		sort(point, point + n, cmpxy);
		printf("%.6lf\n", Closest_Pair(0, n - 1));
	}
	return 0;
}
