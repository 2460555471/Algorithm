//A:单词翻转
//	查看 提交 统计 提问
//	总时间限制 : 1000ms 内存限制 : 65536kB
//	描述
//	输入一个句子（一行），将句子中的每一个单词翻转后输出。
//
//	输入
//	只有一行，为一个字符串，不超过500个字符。单词之间以空格隔开。
//	输出
//	翻转每一个单词后的字符串，单词之间的空格需与原文一致。
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<stack>
#include<cstdio>
using namespace std;

int mat[201];
char result[201];
void func(string str, int n, int k)
{
	if (str == "")
	{
		printf("\n");
		return;
	}
	str.resize(n);
	for (int i = str.length(); i < n; i++)
	{
		str[i] = ' ';
	}

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result[mat[j]-1] = str[j];
		}
		for (int j = 0; j < n; j++)
		{
			str[j] = result[j];
		}
		
	}

	for (int i = 0; i < n; i++)
	{
		printf("%c", result[i]);
	}
}
int main()
{
	
	int n;
	int k;
	
	while (true)
	{
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			cin >> mat[i];
		}
		getchar();
		while(true)
		{
			string str;
			string content;
			getline(cin, str);

			stringstream ss(str);
			ss >> k;
			if (k == 0)
				break;
			int i = 0;
			while (str[i] != ' ')
			{
				i++;
			}
			content = str.substr(i+1, str.length() - i-1);
			func(content, n, k);
			printf("\n");
		}
		
	}
	





	return 0;
}