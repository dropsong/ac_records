//ÿһ������AC�����Ӷ���һ���ź� 
#include<stdio.h>
using namespace std;

int ans,ANS;

//ŷ�������Ĵ������Һںд��������о�
//�����������������ڵġ� 
int ola(int n)
{
    int ans=0,i,k;
    if(n==1)
    ans=1;
    else
    {
        ans=n;
        k=1;
        for(i=2;n!=1;i+=k)
        {
            if(n%i==0)
            {
                ans/=i;
                ans*=(i-1);
                while(n%i==0) n/=i;
                i=k;
            }
        }
    }
    return ans;
}

int main()
{
#ifdef NOIP
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    
    int n;
    scanf("%d",&n);
    if(n==1){
        putchar('0');
        return 0;
    }
    else{
        for(int i=2;i<=n;i++)
            ans+=ola(i-1);
        
        ANS=2*ans+1;
    }
    printf("%d",ANS);
    return 0;
}