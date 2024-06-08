#include<bits/stdc++.h>
using namespace std;
char a[260];
int top;
bool pd(char a[260])
{
    int i=0;
    while(a[i]!='@')
    {
        if(a[i]=='(')
        {
            top++;
        }
        if(a[i]==')')
        {
            if(top>0)top--;
            else return false;
        }
        i++;
    }
    if(top!=0)return false;
    else return true;
}
int main()
{
    scanf("%s",a);
    if(pd(a))cout<<"YES";
    else cout<<"NO";
    return 0;
}