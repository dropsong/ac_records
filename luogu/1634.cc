#include<bits/stdc++.h>
using namespace std;
long long sum=1;
int main()
{
    long long x,n;
    cin>>x>>n;
    for(long long i=1;i<=n;i++)
        sum+=sum*x;
    cout<<sum;
    return 0;
}