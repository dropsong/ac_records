#include <cstdio>
#include <cmath>

double a,b,c,d,L,R;
inline double f(double x){
    return (c*x+d)/(a*x+b);
}

inline double simpson(double l, double r){
    double mid = l+(r-l)/2;
    return (f(l)+4*f(mid)+f(r))/6.0*(r-l);
}

double asr(double l, double r, double eps, double S, int cnt){
    double mid = l+(r-l)/2;
    double s1 = simpson(l, mid), s2 = simpson(mid, r);
    if(fabs(s1+s2-S)<=15*eps && cnt<=0)
        return s1+s2+(s1+s2-S)/15.0;
    return asr(l, mid, eps/2, s1, cnt-1) + asr(mid, r, eps/2, s2, cnt-1);
}

double calc(double l, double r, double eps){
    return asr(l, r, eps, simpson(l,r), 12);
}

int main(){
    scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&L,&R);
    printf("%.6lf",calc(L,R,1e-6));
    return 0;
}