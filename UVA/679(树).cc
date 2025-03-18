#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    int d,I;
    while(scanf("%d%d",&d,&I)==2)
    {
        int k=1;
        for(int i=0;i<d-1;i++)
        if(I&1) {k<<=1;I=(I+1)>>1;}
        else {k=(k<<1)+1;I>>=1;}
        printf("%d\n",k);
    }
    return 0;
}
