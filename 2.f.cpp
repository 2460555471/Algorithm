
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;



//verse number calculate
int mat[20005];

int temp[20005];
int result;
void mergsort(int left1, int right1, int left2, int right2) {

	int i = left1,index=i,j=left2;

	while (i <= right1 && j <= right2)
	{
		if (mat[i] > mat[j])
		{
			
			temp[index++] = mat[j++];	
			result = result + right1-i+1;
		}
		else
		{
			temp[index++] = mat[i++];
		}
	}
	while (i <= right1)
	{
		temp[index++] = mat[i++];
	}
	while (j <= right2)
	{
		temp[index++] = mat[j++];
	}
	for (int t = left1; t <= right2; t++)
	{
		mat[t] = temp[t];
	}

}



void func(int start,int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		func(start, mid);
		func(mid + 1, end);
		mergsort(start, mid, mid + 1, end);
	
	}
}
int main() {

	int n;
	while(cin >> n && n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d",&mat[i]);
		}
		result = 0;
		func(0,n-1);
		cout << result << endl;
	}

	return 0;
}



