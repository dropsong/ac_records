#include<bits/stdc++.h>
using namespace std;

const int MAXN =1e4+10;
int n,g[MAXN];
double minlen=DBL_MAX;

struct Point
{
    double x,y;
    Point(double x=0,double y=0)
    {
        this->x=x;
        this->y=y;
    }
}P[MAXN];
Point ans;

inline double Sqr(double x){return x*x;}

inline double Rand()
{
    return double(rand())/double(RAND_MAX);
}

inline double dis(Point a,Point b)
{
    return sqrt(Sqr(a.x-b.x)+Sqr(a.y-b.y));
}

bool accept(double delta,double temp)
{
    return delta<0||Rand()<exp(-delta/temp);
}

double calc(Point origin)
{
    double len=0;
    for(int i=0;i<n;i++)
    len+=dis(origin,P[i])*g[i];
    if(len<minlen)
    {
        ans=origin;
        minlen=len;
    }
    return len;
}

void SA(Point ans0,double T0,double dec,double end)
{
    double temp=T0;
    Point nowpos=ans0;
    double nowlen=calc(nowpos);
    while(temp>end)
    {
        Point nextpos=Point(nowpos.x+temp*(Rand()*2-1),nowpos.y+temp*(Rand()*2-1));
        double nlen=calc(nextpos);
        if(accept(nlen-nowlen,temp))
        {
            nowpos=nextpos;
            nowlen=nlen;
        }
        temp*=dec;   //dec为退火系数 
    }
    for(int i=0;i<1000;i++)  //精度维护 
    {
        Point rnd=Point(ans.x+temp*(Rand()*2-1),ans.y+temp*(Rand()*2-1));
        calc(rnd);
    }
}

int main()
{
    cin>>n;
    Point init;
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf%d",&P[i].x,&P[i].y,&g[i]);
        init.x+=P[i].x;
        init.y+=P[i].y;
    }
    init.x/=n;
    init.y/=n;
    SA(init,1e5,1-1e-2,1e-3);
    
    printf("%.3f %.3f\n",ans.x,ans.y);
    return 0;
}
