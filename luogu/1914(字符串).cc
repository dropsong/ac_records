#include<bits/stdc++.h>
using namespace std;
char a[27];
int main()
{
    int n;
    scanf("%d",&n);
    n=n%26;
    char x='a';
    for(int i=1;i<=26;i++)
    {
        a[i]=x;
        x++;
        //cout<<a[i]<<endl;
    }
    string s;
    getline(cin,s);
    getline(cin,s);
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        s[i]+=n;
        if(!('a'<=s[i]&&s[i]<='z'))
        s[i]-=26;
    }
    cout<<s;
    return 0;
}