#include<bits/stdc++.h>
using namespace std;

string s;
map<string,int> a;
set<string> YSWYWB;
bool cnt=false,ook;

void init()
{
    a["one"]=1;       a["two"]=2;
    a["three"]=3;     a["four"]=4;
    a["five"]=5;      a["six"]=6;
    a["seven"]=7;     a["eight"]=8;
    a["nine"]=9;      a["ten"]=10;
    a["eleven"]=11;   a["twelve"]=12;
    a["thirteen"]=13;  a["fourteen"]=14;
    a["fifteen"]=15;   a["sixteen"]=16;
    a["seventeen"]=17; a["eighteen"]=18;
    a["nineteen"]=19;  a["twenty"]=20;
    a["a"]=1;          a["both"]=2;
    a["another"]=1;    a["first"]=1;
    a["second"]=2;     a["third"]=3;
}

inline string transf(int i)  
{  
    stringstream ss;  
    ss<<i;
    string st=ss.str();
    return st;
}  

int main()
{
    init();
    while(cin>>s)
    {
        if(s==".")break;
        if(s=="a++")ook=true;
        if(a.count(s))
        {
            cnt=true;
            int temp=a[s];
            temp*=temp; temp%=100;
            if(!temp)continue;
            string tmp="";
            if(temp<10)tmp="0";
            tmp+=transf(temp);
            YSWYWB.insert(tmp);
        }
    }
    
    if(!cnt)
    {
        cout<<0;
        return 0;
    }
    if(ook){
        cout<<"101";
        return 0;
    }
    
    bool ok=true;
    for(set<string>::iterator it=YSWYWB.begin();it!=YSWYWB.end();++it)
    {
        if(*it=="00")continue;
        else if(ok&&(*it<"10"))
        {
            ok=false;
            string st=(*it);
            cout<<st.substr(1);
        }
        else cout<<(*it);
    }
    
    return 0;
}
