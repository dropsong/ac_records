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

/*
    这是一个错误的解法，但是一些个人的思路暂且记一下
    另外本意是用 map 的，用数组验证的时候就发现了bug
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <iostream>

#define MAX(a,b) ((a)>(b)?(a):(b))
int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
int a[203][203], m, n, MAXH = -1, ans;
bool vis[203][203];
char color[203][203];
using std::vector;
using std::cout;
using std::endl;

int dfs(int x,int y,bool& _myflag,int k){
    if(vis[x][y]) return 0;
    vis[x][y]=true;
    color[x][y] = 'a';
    int cnt=1;
    if((x==1)||(x==m)||(y==1)||(y==n)){
        _myflag=false;
        color[x][y] = 'b';
    }

    for(int p=0;p<4;p++){
        int nx=x+dir[p][0];
        int ny=y+dir[p][1];
        if((nx<1)||(nx>m)||(ny<1)||(ny>n)||vis[nx][ny])continue;
        if(MAX(0,a[nx][ny]-MAXH+k))continue;
        cnt += dfs(nx,ny,_myflag,k);
    }
    if(!_myflag) color[x][y] = 'b';
    return cnt;
}
// 还没有到海洋，标记还没变，而此时应该要变 b 的已经退出了。
/*  hack
z z z z z z 
z z b b z b 
z a b b z z 
z z b b b b 
z b b b z b 
z b z b z b 
*/

void test(int k)
{
    std::cout << std::endl;
    for(int i = 1; i<= m ; i++)
    {
        for(int j = 1 ; j <=n; j++)
        {
            std::cout << MAX(a[i][j]-MAXH+k, 0) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void test2()
{
    for(int i = 1; i<=m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            cout << color[i][j] << " "
            ;
        }
        cout << endl;
    }
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

        {
            int k = 1;
            for(int i = 0; i < m+1; i++)
                for(int j = 0; j < n+1; j++)
                    vis[i][j] = false;

            test(k);

            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    if(MAX(0,a[i][j]-MAXH+k))vis[i][j]=true, color[i][j] = 'z';
                    if(vis[i][j])continue;
                    bool myflag = true;
                    int tmp = dfs(i,j,myflag,k);
                    if(!myflag) continue;
                    ans += tmp;
                }
            }
        }

        test2();

        cout << "ans = " << ans << endl;

        for(int k=2;k<=MAXH;k++){

            test(k);

            for(int i = 0; i < m+1; i++)
                for(int j = 0; j < n+1; j++)
                    vis[i][j] = false;
            
            for(int i = 1; i<=m ; i++)
            {
                for(int j = 1; j<=n; j++)
                {
                    if(vis[i][j]) continue;

                    if(color[i][j]=='z')
                    {
                        vis[i][j] = true;
                        continue;
                    }
                    else if(color[i][j]=='a')
                    {
                        if(!MAX(a[i][j]-MAXH+k,0)) ans++;
                        else {
                            color[i][j] = 'z';
                        }
                    }
                    else if(color[i][j]=='b')
                    {
                        if(vis[i][j]) continue;
                        if(MAX(0,a[i][j]-MAXH+k))
                        {
                            color[i][j] = 'z';
                            continue;
                        }
                        bool myflag = true;
                        int tmp = dfs(i, j, myflag, k);
                        if(!myflag) continue;
                        ans += tmp;
                    }
                    // 考虑改进方法：
                    // 先全染成 c ，如果合法，转为 a
                    // 若不合法，全部作 b
                    // 但这样复杂度就上去了
                }
            }
        test2();
        cout << "ans = " << ans << endl;
        }
        return ans;
    }
};