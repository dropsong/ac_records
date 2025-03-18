#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<climits>
#include<algorithm>
using namespace std;

struct node{
	int ele;
	int index;
}a[200];
int k,sum1,sum2;

bool cmp(node x,node y){return x.ele>y.ele;}

int main()
{
	scanf("%d",&k);
	int floor=500*k;
	for(int i=0;i<3*k;i++)
	{
		scanf("%d",&a[i].ele);
		a[i].index=i;
	}sort(a,a+3*k,cmp);
	
	for(int i=0;i<k;i++)
	sum1+=a[i].ele,sum2+=a[i+k].ele;
	
	srand((unsigned int)time(0));
	while(!(sum1>floor&&sum2>floor))
	{
		int offset1=rand()%k;
		int offset2=rand()%k;
		sum1=sum1-a[offset1].ele+a[k+offset2].ele;
		sum2=sum2-a[k+offset2].ele+a[offset1].ele;
		swap(a[offset1],a[offset2+k]);
	}
	
	for(int i=0;i<3*k;i++)
	printf("%d\n",a[i].index+1);
	return 0;
}
