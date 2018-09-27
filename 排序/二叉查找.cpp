#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int mat[10] = { 1,2, 5, 11, 18, 20, 24, 222, 555, 777};	//要经过排序的数组

//递归形式的二叉查找不会出现start比end大的情况，最终将会使start=end陷入死循环
int bi_find(int start, int end, int parot)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		if (mat[mid] == parot)
			return mid;
		else if (mat[mid] > parot)
			return bi_find(start, mid, parot);
		else
		{
			return bi_find(mid + 1, end, parot);
		}
	}
	else
	{
		return -1;
	}
}
//注意终止的条件不包含start和end的值相同，此时也是可以进行比较的，这是一种非递归的方法
int bi_search(int start,int end,int parot)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (mat[mid] == parot)
		{
			return mid;
		}
		else if (mat[mid] < parot)
		{
			start++;
		}
		else
		{
			end--;
		}
	}
	return -1;
}


int main()
{
	int n;
	while (cin >> n)
	{

		//cout<<bi_find(0, 10 - 1, n)<<endl;
		cout << bi_search(0, 10 - 1, n) << endl;


	}


}

