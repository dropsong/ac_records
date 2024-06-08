#include<bits/stdc++.h>
using namespace std;
struct paiming
{
    string num;
    int index;
}a[25];
bool comp(paiming x,paiming y)
{
    if(x.num.size()!= y.num.size())
    return x.num.size()>y.num.size();
    
    return x.num>y.num;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num;
        a[i].index=i;
    }
    sort(a+1,a+1+n,comp);
    cout<<a[1].index<<endl<<a[1].num;
    return 0;
}