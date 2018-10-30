//http://algorithm.openjudge.cn/201801/B/
//B:密码
//	查看 提交 统计 提问
//	总时间限制 : 1000ms 内存限制 : 65536kB
//	描述
//	Bob 和 Alice 开始使用一种全新的编码系统。它是一种基于一组私有钥匙的。他们选择了n个不同的数a1 ， . ..，an, 它们都大于0小于等于n。 机密过程如下：待加密的信息放置在这组加密钥匙下，信息中的字符和密钥中的数字一一对应起来。信息中位于i位置的字母将被写到加密信息的第ai个位置, ai 是位于i位置的密钥。加密信息如此反复加密，一共加密 k 次。
//
//	信息长度小于等于n。如果信息比 n 短, 后面的位置用空格填补直到信息长度为n。
//
//	请你帮助 Alice 和 Bob 写一个程序，读入密钥，然后读入加密次数 k 和要加密的信息，按加密规则将信息加密。

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<stack>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int mat[201];
int circle[201];
char result[201];
int main()
{
	int n;
	while (true)
	{
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			cin >> mat[i];
		}
		int k=0,temp=-1;
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			
			while (temp != i) {
				if (flag == true)
				{
					temp = i;
					flag = false;
				}
				temp = mat[temp] - 1;
				k++;

			}
			circle[i] = k;
			flag = true;
			k = 0;
			temp = -1;
		}
	
		int kk;
		string str;
		while (true)
		{
			cin >> kk;
			if (kk == 0)
				break;
			getchar();
			getline(cin,str);
			for (int i = str.length(); i < n; i++)
			{
				str = str + ' ';
			}
			memset(result, ' ', n);
	
			int index;
			for (int i = 0; i < n; i++)
			{
				index = i;
				for (int j = 0; j < kk%circle[i]; j++)
				{
					index = mat[index] - 1;
				
				}
			
			
				result[index] = str[i];
			
				
			}
			int j;
			for (j = n-1; j >=0; j--)
			{
				if (result[j] != ' ')
					break;
			}

			for (int i = 0; i <= j; i++)
			{
				
				cout << result[i];
			}
			cout << endl;

		}
		cout << endl;

	}
	
	return 0;
}