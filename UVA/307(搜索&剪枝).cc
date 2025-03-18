//think twice,code once.
#include<cstdio>
#include<cstring>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;

int n,m,cnt,len,a[70];       //m sticks
bool v[70];

bool dfs(int now,int cab,int last)
{
    if(now>cnt)return true;
    if(cab==len)return dfs(now+1,0,1);
    int fail=0;
    for(int i=last;i<=m;i++)
    if(!v[i]&&cab+a[i]<=len&&fail!=a[i])
    {
        v[i]=true;
        if(dfs(now,cab+a[i],i+1))return true;
        fail=a[i];   //a[i] has failed.
        v[i]=false;
        if(!cab)return false;
    }
    return false;
}

int main()
{
    while(scanf("%d",&n)&&n)
    {
        int sum=0,val=0; m=0;
    	for(int i=1;i<=n;i++)
    	{
        	int temp; scanf("%d",&temp);
        	if(temp>50)continue;
        	a[++m]=temp;
        	sum+=a[m]; val=max(val,a[m]);
    	}
    	sort(a+1,a+1+m);
    	reverse(a+1,a+1+m);
    
    	for(len=val;len<=sum;len++)
    	{
        	if(sum%len)continue;
        	cnt=sum/len;
        	memset(v,false,sizeof(v));
        	if(dfs(1,0,1))break;
    	}
    
    	printf("%d\n",len);
    }
    return 0;
}