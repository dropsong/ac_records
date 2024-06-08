#include<bits/stdc++.h>
using namespace std;
int A,B,C,flag=0;
int j,k;
int main()
{
    scanf("%d%d%d",&A,&B,&C);
    for(int i=(123/A+min(123%A,1))*A;i<=987/A*A;i+=A)
    {
        j=i/A*B;
        k=i/A*C;
        if(j>=100&&j<=999&&k>=100&&k<=999)
        {
            int l[10],sum=0,xx=1;
            l[1]=i/100;
            l[2]=i/10%10;
            l[3]=i%10;
            l[4]=j/100;
            l[5]=j/10%10;
            l[6]=j%10;
            l[7]=k/100;
            l[8]=k/10%10;
            l[9]=k%10;
            for(int I=1;I<=9;I++)
            {
                sum+=l[I];
                xx*=l[I];
            }
            if(sum==45&&xx==362880)
            {
                flag=1;
                printf("%d %d %d\n",i,j,k);
            }
        }
    }
    if(flag==0)printf("No!!!\n");
    return 0;
}