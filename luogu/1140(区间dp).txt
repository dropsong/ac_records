#include<bits/stdc++.h>
#define MAXN 105
using namespace std;

int f[MAXN][MAXN],len1,len2;
string s1,s2;
map<char,int>h;
int d[5][5]={{5,-1,-2,-1,-3},
             {-1,5,-3,-2,-4},
             {-2,-3,5,-2,-2},
             {-1,-2,-2,5,-1},
             {-3,-4,-2,-1,0}};

int main()
{
    h['A']=0;h['C']=1;h['G']=2;h['T']=3;
    
    int i,j;
    cin>>len1>>s1;    
    cin>>len2>>s2;
    s1.insert(0,"#");
    s2.insert(0,"#");

    for(i=0;i<=len1;i++)
    for(j=0;j<=len2;j++)
    f[i][j]=-1e8;
    
    f[0][0]=0;
    for(i=0;i<=len1;i++)
    for(j=0;j<=len2;j++)
    {
        if(i&&j)f[i][j]=max(f[i-1][j-1]+d[h[s1[i]]][h[s2[j]]],f[i][j]);
        if(j)f[i][j]=max(f[i][j-1]+d[4][h[s2[j]]],f[i][j]);
        if(i)f[i][j]=max(f[i-1][j]+d[h[s1[i]]][4],f[i][j]);
    }
    
    cout<<f[len1][len2];
    return 0;
}