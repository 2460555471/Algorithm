#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn=200005;
typedef long long ll;
 
int a[maxn];
ll ans;
int temp[maxn];
 
void Merge(int l,int mid,int r){
    int i=l,j=mid+1;
    int pos=l;
    while(i<=mid && j<=r){
        if(a[i]<=2*a[j]) i++;
        else{
            j++;
            ans+=mid-i+1;
        }
    }
    i=l,j=mid+1,pos=l;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            temp[pos++]=a[i++];
        }
        else{
            temp[pos++]=a[j++];
        }
    }
    while(i<=mid)
        temp[pos++]=a[i++];
    while(j<=r)
        temp[pos++]=a[j++];
    for(int i=l;i<=r;i++)
        a[i]=temp[i];
}
 
void merge_sort(int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        Merge(l,mid,r);
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ans=0;
        merge_sort(0,n-1);
//        cout<<ans<<endl;
//        for(int i=0;i<n;i++){
//            printf("%d%c",a[i],i==n-1?'\n':' ');
//        }
        cout<<ans<<endl;
    }
    return 0;
}
