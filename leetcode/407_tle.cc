// Github: https://github.com/dropsong
// https://leetcode.cn/problems/trapping-rain-water-ii/description/

//            ⠀⠀⠀⠀⠰⢷⢿⠄   
//            ⠀⠀⠀⠀⠀⣼⣷⣄   
//            ⠀⠀⣤⣿⣇⣿⣿⣧⣿⡄ 
//            ⢴⠾⠋⠀⠀⠻⣿⣷⣿⣿⡀
//            ○ ⠀⢀⣿⣿⡿⢿⠈⣿ 
//            ⠀⠀⠀⢠⣿⡿⠁⠀⡊⠀⠙
//            ⠀⠀⠀⢿⣿⠀⠀⠹⣿  
//            ⠀⠀⠀⠀⠹⣷⡀⠀⣿⡄ 
//            ⠀⠀⠀⠀⣀⣼⣿⠀⢈⣧.
//
//     _     _   _    _    _    _     _
//    |_|   | |/ /   | |  | |  |  \  | |
//     _    | ' /    | |  | |  | \ \ | |
//    | |   |   \    | |  | |  | |\ \| |
//    | |   | |\ \   | |__| |  | | \ \ |
//    |_|   |_| \_\   \_____/  |_|  \ _|

#include <cstdio>
#include <cstring>
#include <vector>

#define MAX(a,b) ((a)>(b)?(a):(b))
int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
int a[203][203], m, n, MAXH = -1, ans;
bool vis[203][203];
using std::vector;

int dfs(int x,int y,bool& _myflag,int k){
    if(vis[x][y]) return 0;
    vis[x][y]=true;
    int cnt=1;
    if((x==1)||(x==m)||(y==1)||(y==n)){
        _myflag=false;
    }

    for(int p=0;p<4;p++){
        int nx=x+dir[p][0];
        int ny=y+dir[p][1];
        if((nx<1)||(nx>m)||(ny<1)||(ny>n)||vis[nx][ny])continue;
        if(MAX(0,a[nx][ny]-MAXH+k))continue;
        cnt+=dfs(nx,ny,_myflag,k);
    }
    return cnt;
}

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        ans = 0;
        MAXH = -1;
        auto it1 = heightMap.begin();
        m = heightMap.size(); 
        n = it1->size();

        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                a[i][j] = heightMap[i-1][j-1];
                MAXH = MAX(MAXH, a[i][j]);
            }
        }

        for(int k=1;k<=MAXH;k++){

            for(int i = 0; i < m+1; i++)
                for(int j = 0; j < n+1; j++)
                    vis[i][j] = false;

            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    if(MAX(0,a[i][j]-MAXH+k))vis[i][j]=true;
                    if(vis[i][j])continue;
                    bool myflag = true;
                    int tmp = dfs(i,j,myflag,k);
                    if(!myflag) continue;
                    ans += tmp;
                }
            }
        }
        return ans;
    }
};