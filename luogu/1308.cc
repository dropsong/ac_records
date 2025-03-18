#include<bits/stdc++.h>
using namespace std;
string st,st1,st2;
int f,p=-1,p1,s1,s2,len;
int main()
{
    getline(cin,st);      
    getline(cin,st1);
    st1=st1+' ';
    len=st1.size();int lenn=st.size();
    for (int i=0;i<lenn;i++)
    if (st[i]>='A'&&st[i]<='Z') st[i]=st[i]+32;
    for (int i=0;i<len;i++)
    if (st1[i]>='A'&&st1[i]<='Z') st1[i]=st1[i]+32;
    int s=0;
    for (int i=0;;i++)
    {
        p1=st1.find(' ',p+1);
        st2=st1.substr(p+1,p1-(p+1));
        if (st==st2) {if (s==0) s1=p+1;s++;}
        p=p1;
        if (p==-1) break;
    }
    if (s==0) cout<<-1;else cout<<s<<" "<<s1;
}