#include<iostream>
using namespace std;
int sum=0,k=1,check;
char isbn[14];
void input()
{
    for(int i=1;i<=12;i++)
    {
    	cin>>isbn[i];
    	if(isbn[i]!='-')
        {
        	sum+=(isbn[i]-'0')*k;
        	k++;
        }
    }
    cin>>isbn[13];
    if(isbn[13]!='X')
    {
        check=isbn[13]-'0';
    }
    else check=10;
}
void output()
{
    if(sum%11==check) cout<<"Right";
    else
    {    
        for(int i=1;i<=12;i++) cout<<isbn[i];
        if(sum%11!=10) cout<<sum%11; 
        else cout<<"X";
    }
}
int main()
{
    input();
    output();
    return 0;
}