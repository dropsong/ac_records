#include<bits/stdc++.h>
using namespace std;
int m,n,k,l,d,x,y,p,q;
struct Hang
{
    int hang,
        numhang;
}H[1005];
struct Lie
{
    int lie,
        numlie;
}L[1005];
void work1()
{
    for(int i=1; i<=m-1; i++) H[i].numhang=i; //初始化
}
void work2()
{
    for(int i=1; i<=n-1; i++) L[i].numlie=i; //初始化
}

bool cmph(Hang x,Hang y)
{
    return x.hang>y.hang;
}
bool cmpl(Lie x,Lie y)
{
    return x.lie>y.lie;
}
bool cmpH(Hang x,Hang y)
{
    return x.numhang<y.numhang;
}
bool cmpL(Lie x,Lie y)
{
    return x.numlie<y.numlie;
}
int main()
{
     cin>>m>>n>>k>>l>>d;
     for(int i=1; i<=d; i++)
     {
        cin>>x>>y>>p>>q;
        if(x!=p)
      {
            if(x>p) H[p].hang++;//记在坐标小的下标内，方便计算
        	else H[x].hang++;
      } 
      else
      {
            if(y>q) L[q].lie++;
      		else L[y].lie++;
      }
     }
     work1();
     work2();
     
     sort(H+1,H+1+m-1,cmph);
     sort(L+1,L+1+n-1,cmpl);
     
     sort(H+1,H+k+1,cmpH);
     sort(L+1,L+l+1,cmpL);
     
     for(int i=1; i<=k; i++) cout<<H[i].numhang<<" "; //输出行最优解
     cout<<endl;
     for(int i=1; i<=l; i++) cout<<L[i].numlie<<" "; //输出列最优解
     return 0;
}