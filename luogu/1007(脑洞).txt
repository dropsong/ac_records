#include<bits/stdc++.h>
using namespace std;
int sum;
int main()
{
    int l,n;
    scanf("%d%d",&l,&n);
    int kkk,mintime,maxtime;
    int mid1=(1+l)/2,mid2=mid1+1;
    int pos1=-1,pos2=mid1;            //ø…ƒ‹”–   BUG 
    int temp1=6000,temp2=-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&kkk);
        if(l%2!=0)//===3,5,7,9......
        {
            if(abs(kkk-mid1)<temp1)
            {
                temp1=abs(kkk-mid1);
                pos1=kkk;
            }
        }
        else
        {
            int minn=min(abs(kkk-mid1),abs(kkk-mid2));
            if(minn<temp1)
            {
                temp1=minn;
                pos1=kkk;
            }
        }
        int maxn=max(abs(kkk-1),abs(kkk-l));
        if(maxn>temp2)
        {
            temp2=maxn;
            pos2=kkk;
        }
        if(kkk<=0||kkk>=l+1)sum++;
    }
    if(sum>=n)
    {
    	cout<<"0 0";
    	return 0;
    }
    mintime=min(pos1,l-pos1+1);
    maxtime=max(pos2,l-pos2+1);
    printf("%d %d",mintime,maxtime);
    return 0;
}