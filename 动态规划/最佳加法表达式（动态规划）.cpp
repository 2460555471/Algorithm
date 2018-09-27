/*
题目：有一个由1..9组成的数字串.问如果将m个加
号插入到这个数字串中,在各种可能形成的
表达式中，值最小的那个表达式的值是多少
子问题：将最后面的那个加号放在第i个数字的后面，计算前i个
数字的最佳加法表达式
状态：V(m,n)表示在n个数字中插入m个加号所能形成
的表达式最小值
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int INF = 99999999;
int a[1005],num[1005][1005];
int V(int m,int n)
{
    if(m == 0)//无加号
        return num[1][n];
    else if(n < m+1)//加号过多
        return INF;
    else
    {
        int t = INF;
        for(int i = m;i <= n-1;i++)
           t = min(t, V(m-1,i)+num[i+1][n]);
        return t;
    }
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        //预处理,计算i到j数字串组成的数字
        for(int i = 1;i <= n;i++)
        {
            num[i][i] = a[i];//只有一个数字
            for(int j = i+1;j <= n;j++)
            {
                num[i][j] = num[i][j-1]*10 + a[j];
            }
        }
        cout<< V(m,n) <<endl;
    }
    return 0;
}
