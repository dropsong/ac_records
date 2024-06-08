#include<bits/stdc++.h>
using namespace std;
char a[25];
string s;
bool ok=true;
int len,lenn,k;
int position;

void daoxu(int front,int rear)
{
    int j=rear;
    while(s[j]=='0')
    {
        j--;
        if(j<front)
    	{
            a[lenn]='0';
            lenn+=1;
            k++;
            return;
        }
    }
    for(int i=j;i>=front;i--)
    a[k++]=s[i];
    lenn+=j-front+1;
}

void xiaoshu()
{
    daoxu(0,position-1);
    a[lenn]='.';
    lenn++; k++;
    daoxu(position+1,len-1);
    while(a[lenn-1]=='0'&&lenn-1>position+1)
    lenn--;
}
void fenshu()
{
    daoxu(0,position-1);
    a[lenn]='/';
    lenn++; k++;
    daoxu(position+1,len-1);
    while(a[lenn-1]=='0'&&lenn-1>position+1)
    lenn--;
}
void baifen()
{
    daoxu(0,len-2);
    a[lenn]='%';
    lenn++;
}
void intshu()
{
    daoxu(0,len-1);
    //lenn=len;
}
void output()
{
    for(int i=0;i<lenn;i++) putchar(a[i]);
}
int main()
{
    getline(cin,s);
    len=s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]=='.')
        {
            position=i;
            xiaoshu(); ok=false;
            break;
        }
        else if(s[i]=='/')
        {
            position=i;
            fenshu(); ok=false;
            break;
        }
        else if(s[i]=='%')
        {
            baifen(); ok=false;
            break;
        }
    }
    if(ok)   intshu();
    output();
    //cout<<"flag";
    return 0;
}