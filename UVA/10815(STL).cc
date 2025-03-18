#include<iostream>
#include<string>
#include<set>
#include<sstream>
#define HOME
#define TEST printf("a test.\n")
using namespace std;
set<string> dict;

int main()
{
#ifdef NOIP
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    string s,buf;
    while(cin>>s){
        int s_len=s.length();
        for(int i=0;i<s_len;i++)
            if(isalpha(s[i])) s[i]=tolower(s[i]);
            else s[i]=' ';
        stringstream ss(s);
        while(ss>>buf) dict.insert(buf);
    }
    
    for(set<string>::iterator it=dict.begin();it!=dict.end();++it)
        cout<<*it<<endl;	
    
    return 0;
}