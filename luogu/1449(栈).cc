#include<bits/stdc++.h>
using namespace std;
string s;
int Stack[1000];
int work()
{
    int i=0,top=0,temp;
    int len=s.size();
    while(i<=len-2)
    {
        if(s[i]=='@')break;
        switch(s[i])
        {
            case '+':
                Stack[--top]+=Stack[top+1];break;
            case '-':
                Stack[--top]-=Stack[top+1];break;
            case '*':
                Stack[--top]*=Stack[top+1];break;
            case '/':
                Stack[--top]/=Stack[top+1];break;
            default :
                temp=0;
                while(s[i]!='.'&&s[i]!='@')
                {
                    temp=10*temp+s[i++]-'0';
                }
                Stack[++top]=temp;
                break;
        }
        i++;
    }
    return Stack[top];
}
int main()
{
    getline(cin,s);
    printf("%d",work());
    return 0;
}