#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct XY{int num,s,t,val;}v[1000000];
struct cmp{
    bool operator ()(XY &a,XY &b){
        return a.val<b.val||a.val==b.val&&a.num>b.num;
    }
};

int n=0,rest,cnt=1,sz=0,Time; 
priority_queue<XY,vector<XY>,cmp> Q;

int main()
{
    while(scanf("%d%d%d%d",&v[n+1].num,&v[n+1].s,&v[n+1].t,&v[n+1].val)!=EOF)++n;
    rest=n;v[n+1].s=1e9;
    while (rest!=0)
    {
        if(sz==0)Q.push(v[cnt]),Time=v[cnt].s,sz++,cnt++; 
        XY tmp=Q.top();Q.pop();sz--; 
        int last_time=Time;
        Time=min(v[cnt].s,last_time+tmp.t); 
        if (Time==last_time+tmp.t)
        printf("%d %d\n",tmp.num,Time),rest--;
        else tmp.t-=Time-last_time,Q.push(tmp),sz++;
        if (Time==v[cnt].s)    Q.push(v[cnt]),sz++,cnt++;
    }
    return 0;
}
