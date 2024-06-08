#include<bits/stdc++.h>
using namespace std;

map<char,char> a;
set<char> cnt;
string locked,yuan,want;

int main()
{
    cin>>locked>>yuan>>want;
    for(int i=0;yuan[i];i++)
    {
        if(!a.count(locked[i]))
        a[locked[i]]=yuan[i];
        else if(a[locked[i]]!=yuan[i])
        {
            cout<<"Failed";
            return 0;
        }
        cnt.insert(yuan[i]);
    }
    
    for(char c='A';c<='Z';c++)
    if(!a.count(c)||(!cnt.count(c)))
    {
        cout<<"Failed";
        return 0;
    }
    
    for(int i=0;want[i];i++)
    cout<<a[want[i]];
    return 0;
}
