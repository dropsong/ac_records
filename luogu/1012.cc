
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

struct cmp
{
    bool operator() (const string a,const string b)const
    {
        if(a.size()==b.size())return a>b;
        else
        {
            int lena=a.size();
            int lenb=b.size();
            int len=min(lena,lenb);
            string aa=a.substr(0,len);
            string bb=b.substr(0,len);
            if(aa>bb)return true;
            else if(aa<bb)return false;
            else return a[lena-1]>b[lenb-1];
        }
    }
};
string s;
map<string,int> cnt;
set<string,cmp> qwq;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        if(!cnt.count(s))cnt[s]=0;
        cnt[s]++;
        qwq.insert(s);
    }
    
    set<string>::iterator it;
    for(it=qwq.begin();it!=qwq.end();it++)
    {
        for(int i=1;i<=cnt[*it];i++)
        cout<<*it;
    }
    return 0;
}
