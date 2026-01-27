// https://leetcode.cn/problems/rotting-oranges/description/

#include <iostream>
#include <vector>

using std::cout;
using std::vector;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        int min = 0;
        while(1) {
            bool round_flag = false;
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(grid[i][j] == 2) {
                        round_flag |= spread(i, j, grid);
                    }
                }
            }

            if(!round_flag) break;
            for(auto e : pos) grid[e.first][e.second] = 2; pos.clear();
            min++;
        }

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j] == 1) return -1;
        
        return min;
    }

private:
    bool spread(int x, int y, vector<vector<int>>& grid) {
        bool flag = false;
        if(x-1>=0 && grid[x-1][y]==1) { pos.push_back({x-1, y}); flag = true; }
        if(y-1>=0 && grid[x][y-1]==1) { pos.push_back({x, y-1}); flag = true; }
        if(y+1<n && grid[x][y+1]==1) { pos.push_back({x, y+1}); flag = true; }
        if(x+1<m && grid[x+1][y]==1) { pos.push_back({x+1, y}); flag = true; }
        return flag;
    }
    int m, n;
    vector<std::pair<int,int>> pos;
};


#if 0
int main()
{
    Solution s;
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    cout << s.orangesRotting(grid) << "\n";
    return 0;
}
#endif