//duliu moniti !!!!!
#include<iostream>
#include<algorithm>
#include<sstream>
#include<functional>
#include<vector>
using namespace std;
typedef long long LL;

stringstream io; 
string buffer;

inline LL mxsort(LL n)
{
    io.clear();     
    buffer.clear();
    io<<n;
    io>>buffer; 
    sort(buffer.begin(),buffer.end(),greater<char>());
    io.clear();
    io<<buffer; 
    io>>n;
    return n; 
}

inline LL mnsort(LL n)
{
    io.clear();
    buffer.clear();
    io<<n;
    io>>buffer;
    sort(buffer.begin(),buffer.end(),less<char>());
    io.clear();
    io<<buffer;
    io>>n;
    return n;
}

void work(LL n)
{
    vector<LL>a;
    a.push_back(n);
    int i=0;
    while(1){
        a.push_back(mxsort(a[i])-mnsort(a[i]));
        for(int t=0;t<=i;t++)
        if(a[i+1]==a[t])
        {
            for(int k=t;k<=i;k++)
         	cout<<a[k]<<' ';
            cout<<endl;
            return;
        }
        i++;  
    }
}

int main()
{
    LL n;
    while(cin>>n)work(n);
    return 0; 
}
