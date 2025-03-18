#include<bits/stdc++.h>
using namespace std;

struct Pos{int x,y;}pos[40*40];
int matrix[40][40];

int main()
{
    int n; cin>>n;
    pos[1].x=1; pos[1].y=n/2+1;
    matrix[pos[1].x][pos[1].y]=1;
    for(int i=2;i<=n*n;i++)
    {
        int px=pos[i-1].x;
        int py=pos[i-1].y;
        if(px==1&&py!=n){
            pos[i].x=n;
            pos[i].y=py+1;
        }
        else if(py==n&&px!=1){
            pos[i].x=px-1;
            pos[i].y=1;
        }
        else if(px==1&&py==n){
            pos[i].x=px+1;
            pos[i].y=py;
        }
        else if(px!=1&&py!=n){
            if(!matrix[px-1][py+1]){
                pos[i].x=px-1;
                pos[i].y=py+1;
            }
            else{
                pos[i].x=px+1;
                pos[i].y=py;
            }
        }
        matrix[pos[i].x][pos[i].y]=i;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }	
    
    return 0;
}
