#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a=1,b=1;
    int i=1;
    for(;;)
    {
        if(i==n)
        {
            cout<<a<<"/"<<b;return 0;
        }
        
        if(a==1 && b%2==1)
        {
            b++;i++;
        }
        if(i==n)
        {
            cout<<a<<"/"<<b;return 0;
        }
        
        while(b>=2)
        {	
            a++;b--;i++;
            if(i==n)
            {
                cout<<a<<"/"<<b;return 0;
            }
        }
        
        if(b==1 && a%2==0)
        {
            a++;i++;
        }
        if(i==n)
        {
            cout<<a<<"/"<<b;return 0;
        }
        
        while(a>=2)
        {
            a--;b++;i++;
            if(i==n)
            {
                cout<<a<<"/"<<b;return 0;
            }
        }
    }
}