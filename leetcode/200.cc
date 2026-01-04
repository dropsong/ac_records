// https://leetcode.cn/problems/number-of-islands/description/
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

#include <iostream>
#include <vector>

using std::cout;
using std::vector;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(vis[i][j]) continue;
                if(grid[i][j] == '0') continue;
                cnt ++;
                dfs(i,j, grid);
            }
        }
        return cnt;
    }

private:
    bool vis[305][305];
    int dx[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int m, n;

    void dfs(int x, int y, vector<vector<char>>& grid)
    {
        if(vis[x][y]) return;
        vis[x][y] = true;
        for(int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i][0];
            int ny = y + dx[i][1];
            if(nx < 0 || nx >=m || ny < 0 || ny >=n) continue;
            if(grid[nx][ny] == '0') continue;
            dfs(nx, ny, grid);
        }
    }
};


#if 0
int main()
{
    Solution s;
    // you can construct an example here, if you wish...
    return 0;
}
#endif
