#include<cstdio>  
#include<vector>  
#include<map>  
#include<stdlib.h>  
#include<math.h>  
#include<cstring>  
#include<string>  
#include<climits>  
#include<algorithm>  
#include<iostream>  
using namespace std;

//http://poj.org/problem?id=2955  À¨ºÅµÄ×î´óÆ¥Åä
int dp[100][100];

int main()
{
	string s;
	while (cin >> s)
	{
		if (s == "end")
			break;
		memset(dp, 0, sizeof(dp));


		for (int l =0; l <= s.size(); l++)
		{
			for (int i = 0; i+l-1 < s.size(); i++)
			{
				int j = i + l - 1;
				if (s[i] == '['&&s[j] == ']' || s[i] == '('&&s[j] == ')')
					dp[i][j] = dp[i + 1][j - 1] + 2;
				for (int k = i; k < j; k++)
				{
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
				}
			}
		}


		cout << dp[0][s.size() - 1] << endl;;

	}

	return 0;
}