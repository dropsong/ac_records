#include<iostream>
#include<algorithm>
using namespace std;
int a[10010];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        next_permutation(a,a+n);
    }
    for(int i=0;i<n-1;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
    return 0;
} 