//E:由中根序列和后根序列重建二叉树
//	查看 提交 统计 提问
//	总时间限制 : 500ms 内存限制 : 65535kB
//	描述
//	我们知道如何按照三种深度优先次序来周游一棵二叉树，来得到中根序列、前根序列和后根序列。反过来，如果给定二叉树的中根序列和后根序列，或者给定中根序列和前根序列，可以重建一二叉树。本题输入一棵二叉树的中根序列和后根序列，要求在内存中重建二叉树，最后输出这棵二叉树的前根序列。
//
//	用不同的整数来唯一标识二叉树的每一个结点，下面的二叉树
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<stack>
#include<cstdio>
using namespace std;

typedef struct node
{
	int value;
	struct node* left, *right;
}Binode;
vector<int> m;
vector<int> b;
void func(Binode * &T,int mid,int last,int len)
{
	if (len == 0)
	{
		T = NULL;
		return;
	}
	int value= b[last+len-1];
	int index = mid;
	while (m[index] != value)
	{
		index++;
	}
	T = (Binode*)malloc(sizeof(Binode));
	T->value = value;


	func(T->left, mid, last, index - mid);
	func(T->right, index+1, last+index - mid, len-(index - mid)-1);
}

void forward(Binode* T)
{
	if (T!=NULL)
	{
		cout << T->value<<" ";
		forward(T->left);
		forward(T->right);

	}

}
int main()
{
	
	string mid;
	string back;
	getline(cin, mid);
	getline(cin, back);
	stringstream smid(mid);
	stringstream sback(back);
	m.clear();
	b.clear();
	int a;
	while (smid >> a)
	{
		m.push_back(a);
	}
	while (sback >> a)
	{
		b.push_back(a);
	}
	
	Binode * T;
	func(T, 0, 0, b.size());
	forward(T);
	cout << endl;


	return 0;
}