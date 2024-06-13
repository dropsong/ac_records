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

// water[i][j]=max(heightMap[i][j],min(water[i−1][j],water[i+1][j],water[i][j−1],water[i][j+1]))
// 所以可以用优先队列从小的开始计算，填完一个就可以把填完的看成墙。
// 水善利万物而不争，处众人之所恶， 故几于道。

typedef pair<int,int> pii;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {  
        if (heightMap.size() <= 2 || heightMap[0].size() <= 2) {
            return 0;
        }  
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], i * n + j});
                    visit[i][j] = true;
                }
            }
        }

        int res = 0;
        int dirs[] = {-1, 0, 1, 0, -1};
        while (!pq.empty()) {
            pii curr = pq.top();
            pq.pop();            
            for (int k = 0; k < 4; ++k) {
                int nx = curr.second / n + dirs[k];
                int ny = curr.second % n + dirs[k + 1];
                if( nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny]) {
                    if (heightMap[nx][ny] < curr.first) {
                        res += curr.first - heightMap[nx][ny]; 
                    }
                    visit[nx][ny] = true;
                    pq.push({max(heightMap[nx][ny], curr.first), nx * n + ny});
                }
            }
        }
        return res;
    }
};