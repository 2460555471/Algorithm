#include<iostream>
#include<cstdio>

using namespace std;
int mat[10000];

int main()
{
	int n;
	while (cin >> n)
	{
		if (n < 0)
			continue;
		memset(mat, 0, sizeof(mat));
		mat[0] = 1;
		int m = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				mat[j] *= i;
				
				if (j > 0 && mat[j - 1] > 10000)
				{
					mat[j] = mat[j] + mat[j - 1] / 10000;
					mat[j - 1] = mat[j - 1] % 10000;
				}
				if (mat[m] > 10000)
					m++;
			}
		}

		printf("%d", mat[m]);
		for (int i = m - 1; i >= 0; i--)
			printf("%04d", mat[i]);
		printf("\n");


	}



	return 0;
}