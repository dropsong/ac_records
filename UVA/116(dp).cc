/*#include <algorithm>
using namespace std;
int a[11][101],d[11][101],next[11][101];
const int INF = 0x3f3f3f3f;
int first;
int main()
{
    int n,m;
    while (!cin.eof())
    {
        cin>>m>>n;
        int ans=INF;
        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++)
                cin>>a[i][j];
                
        for (int j=n;j>0;j--)
        {
            for (int i=1;i<=m;i++)
            {
                if(j==n)d[i][j]=a[i][j];
                else
                {
                    int row[3]={i,i-1,i+1};
                    if (i==1) row[1]=m;
                    if (i=m) row[2]=1;
                    sort(row,row+3);
                    d[i][j]=INF;
                    for (int k=1;k<3;k++)
                    {
                        int v=d[row[k]][j+1]+a[i][j];
                        if (v<d[i][j]) d[i][j]=v,next[i][j]=row[k];
                        
                    }
                }
                if(j==1&&d[i][j]<ans)ans=d[i][j],first=i;
            }
        }
        cout<<first<<endl;
        for (int i=next[first][1],j=1;j<=n;i=next[i][j],j++)
            cout<<i<<" ";
        cout<<endl; 
    }
    return 0;   
} 
*/
#include <iostream>
#include <cstdio>
using namespace std;
const int Maxm = 10 + 2;
const int Maxn = 100 + 7;
const int INF = 0x7fffffff;

int n, m;
int a[Maxm][Maxn], f[Maxm][Maxn], nex[Maxm][Maxn];

int main()
{
    while(scanf("%d%d", &m, &n) == 2)
    {
        for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
        scanf("%d", &a[i][j]);

        int mini, minv = INF;
        for(int j = n-1; j >= 0; --j)
            for(int i = 0; i < m; ++i)
            {
                if(j == n-1)f[i][j]=a[i][j];
                else 
                {
                    f[i][j] =INF;
                    nex[i][j] =INF;
                    for(int k = -1, row, val; k <= 1; ++k)
                    {
                        row = (i + k + m) % m;
                        val = a[i][j] + f[row][j+1];
                        if(val < f[i][j])
                        {
                            f[i][j] = val;
                            nex[i][j] = row;
                        }
                        
                        else if(val == f[i][j])
                            nex[i][j] = min(row, nex[i][j]);
                    }
                }
                if(j == 0 && f[i][0] < minv) 
                { 
                    minv = f[i][0]; 
                    mini = i; 
                }
            }
        printf("%d", mini+1);
        for(int j = 1, i = nex[mini][0]; j < n; i = nex[i][j], j++)
            printf(" %d", i+1);
        printf("\n%d\n", minv);
    }
    return 0;
}