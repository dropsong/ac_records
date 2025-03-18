#include<bits/stdc++.h>
using namespace std;
string a,b;
int sum1,sum2;
int transform(string x)
{
    int sum=1;
    int len=x.size();
    for(int i=0;i<len;i++)
    {
        sum*=x[i]-'A'+1;
    }
    return sum;
}
void output()
{
    if(sum1%47==sum2%47)
    {
        cout<<"GO";
        return;
    }
    cout<<"STAY";
}
int main()
{
    getline(cin,a);
    getline(cin,b);
    sum1=transform(a);
    sum2=transform(b);
    output();
    return 0;
}