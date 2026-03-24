// https://leetcode.cn/problems/spiral-matrix/
// 模拟，控制

#include <vector>
#include <cstdio>
using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        bool done = false;
        int posx = 0, posy = 0;
        vis[posx][posy] = true;
        ans.push_back(matrix[posx][posy]);

        int cnt = 0;
        do {
            for(int i = 0; i < 4; ++i) {
                cnt ++;  // 转向计数
                int dx = dir[i][0], dy = dir[i][1];
                while(true) {
                    posx += dx, posy += dy;

                    if(posx >= matrix.size() || posx < 0 ||
                       posy >= matrix[0].size() || posy < 0) {
                        posx -= dx, posy  -= dy;
                        break;
                    }
                    if(vis[posx][posy]) {
                        posx -= dx, posy  -= dy;
                        break;
                    }

                    vis[posx][posy] = true;
                    ans.push_back(matrix[posx][posy]);
                    cnt = 0;
                }
                if(cnt > 5) done = true;
            }
        }while(!done);

        return ans;
    }

private:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool vis[14][14];
    vector<int> ans;
};

#if 0
int main()
{
    // test case 1
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution sol;
    vector<int> res = sol.spiralOrder(matrix);
    for(int num : res) {
        printf("%d ", num);
    }
    return 0;
}
#endif