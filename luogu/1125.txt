#include<bits/stdc++.h>
using namespace std;
bool ok[140];
int sum[140];
bool pd(int t)
{
    if(t==0||t==1)return false;
    int temp=sqrt(t);
    for(int i=2;i<=temp;i++)
    {
        if(t%i==0)return false;
    }
    return true;
}
int main()
{
    string s;
    cin>>s;
    int maxn=-1,minn=110;
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if(!ok[s[i]])
        {
            for(int j=0;j<len;j++)
            {
                if(s[i]==s[j])
                sum[s[i]]++;
            }
        }
        ok[s[i]]=true;
        if(sum[s[i]]>maxn)maxn=sum[s[i]];
        if(sum[s[i]]<minn)minn=sum[s[i]];
    }
    
    //cout<<maxn<<" "<<minn;return 0;
    
    int t=maxn-minn;
    bool flag=pd(t);
    
    if(flag)
        cout<<"Lucky Word"<<endl<<t;
    else
        cout<<"No Answer"<<endl<<"0";
    
    return 0;
}