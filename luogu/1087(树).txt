#include<bits/stdc++.h>
using namespace std;

int n;string s;

int build(int l,int r)
{
    if(l==r)
    {
        if(s[l]=='0'){printf("B");return 1;}
        if(s[l]=='1'){printf("I");return 2;}
    }
    int mid=((l+r)>>1);
    int k1=build(l,mid);
    int k2=build(mid+1,r);
    if(k1==3||k2==3){printf("F");return 3;}
    if(k1==1&&k2==1){printf("B");return 1;}
    if(k1==2&&k2==2){printf("I");return 2;}
    if(k1+k2==3){printf("F");return 3;}
}

int main()
{
    cin>>n>>s;
    build(0,s.size()-1);
    return 0;
}