#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a, c, p, q, r, x, tem;
    cin>>a>>c>>p>>q>>r>>x;
    if(a>=c)
    {
        tem=a+x/r;
        cout<<tem;
        return 0;
    }
    else
    {
        long long jiedong = (c-a)*p;
        if(x <= jiedong)
        {
            tem=x/p+a;
            cout<<tem;
            return 0;
        }
        else if(x<=jiedong+q)
        {
            tem=c;
            cout<<tem;
            return 0;
        }
        else
        {
            tem=c+(x-(jiedong+q))/r;
            cout<<tem;
            return 0;
        }
    }
}