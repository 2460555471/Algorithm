
#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;

vector<int> left_, right_;
//find medain

void in(vector<int> & heap, int value,int type) {

	heap.push_back(value);
	if (type == 0)//left
		push_heap(heap.begin(), heap.end(), less<int>());
	else
		push_heap(heap.begin(), heap.end(), greater<int>());

}
int out(vector<int> & heap,int type) {

	if(type==0)
		pop_heap(heap.begin(), heap.end(),less<int>());
	else
	{
		pop_heap(heap.begin(), heap.end(), greater<int>());
	}
	int n = heap[heap.size() - 1];
	heap.pop_back();
	return n;

}

void create(int value) {

	left_.push_back(value);

}
void search() {

	//cout << left_[0] << endl;
	printf("%d\n", left_[0]);
	
}


void insert(int value) {
	
	if (left_.size() == 0)
	{
		left_.push_back(value);
		return ;
	}
	if (value < left_[0])
	{
		in(left_, value, 0);
	}
	else
	{
		in(right_, value, 1);
	}

	if ((left_.size() + 1) == right_.size())
	{
		int n = out(right_,1);
		in(left_, n, 0);

	}
	else if ((left_.size() - 2) == right_.size())
	{
		int n = out(left_,0);
		in(right_, n, 1);
	}

}

void del() {
	int n = out(left_,0);
	if (left_.size() < right_.size())
	{
		n = out(right_,1);
		in(left_, n, 0);
	}
}

int main()
{
	int T, n;
	cin >> T;
	char type;
	int value;
	while (T--)
	{
		left_.clear();
		right_.clear();
		
		scanf("%d\n", &n);
		bool first = true;
		for (int i = 0; i < n; i++)
		{
			//cin >> type;
			scanf("%c", &type);
			char a=getchar();
			if (type == 'I')
			{
				//cin >> value;
				scanf("%d\n", &value);
				if (first==true)
				{
					create(value);
					first = false;
				}
				else
				{
					insert(value);
				}
			}
			else if (type == 'Q')
			{
				search();
			}
			else if (type == 'D')
			{
				del();
			}
		}


	}


	return 0;
}

