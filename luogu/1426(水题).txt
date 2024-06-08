#include<bits/stdc++.h> 
using namespace std;
int main()
{
    double s,x,len=0;
    scanf("%lf%lf",&s,&x);
    for(int i=1;i<=20000;i++)
    {
        if(len>=s-x)
        {
            if(s+x<len+7*pow(0.98,i-1))
            {
                putchar('n');
                i=20000;
            }
            else
            {
                putchar('y');
                i=20000;
            }
        }
        len+=7*pow(0.98,i-1);
    }
    //MLGB     the problem is toxic!!! 
    return 0;
}