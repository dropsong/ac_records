#include<cstdio>
using namespace std;
int n,m,t,cnt;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		printf("Scenario #%d:\n",++cnt);
		if(n==1||m==1)
			printf("%.2lf\n",(double)(m+n-2)*2);
		else 
			if(m*n%2==1)
				printf("%.2lf\n",(double)m*n-1+1.414);
			else 
				printf("%.2lf\n",(double)n*m);
		putchar('\n');
	}
	return 0;
}
