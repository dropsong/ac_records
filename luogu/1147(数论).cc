#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int m; scanf("%d",&m);
    for(int k1=sqrt(m<<1);k1>1;k1--)
    if(2*m%k1==0&&(k1+2*m/k1)%2){
        int k2=2*m/k1;
        printf("%d %d\n",(k2-k1+1)/2,(k1+k2-1)/2);
    }
    
    return 0;
}
