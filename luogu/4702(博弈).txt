#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    
    int temp;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&temp);
        sum+=temp;
        while(sum>4)sum-=2;
    }
    
    if(sum%2==0){
        printf("Bob");
        return 0;
    }
    else{
        printf("Alice");
        return 0;
    }
}