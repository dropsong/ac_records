// https://leetcode.cn/problems/n-queens/description/

#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        out_n = n;
        dfs(1, "");
        return ans;
    }

private:
    int out_n;
    vector<vector<string>> ans;

    static int strNum2Int(char c) {return c-'0';}

    void dfs(int x, string plan)  // 确定第 x 层
    {
        printf("x = %d, plan = %s\n", x, plan.c_str());
        if(x == out_n+1) {
            vector<string> processed_plan;
            for (char c : plan) {
                int col = c - '0';
                string row(out_n, '.');
                row[col - 1] = 'Q';
                processed_plan.push_back(row);
            }
            ans.push_back(processed_plan);
            return;
        }

        for(int i = 1; i <= out_n; ++i) {
            // plan 里面有 i, continue;
            bool flag1 = false;
            for(int j = 0; j < plan.size(); ++j) {
                // printf("plan[%d] = %c\n", x, plan[x]);
                if(strNum2Int(plan[j]) == i) {flag1 = true; break;}
            }
            if(flag1) continue;

            // 若 i 与之前的对角线冲突, continue;
            bool flag2 = false;
            for(int j = 0; j <= x-2; ++j) {
                if(i == strNum2Int(plan[j]) + (x-j-1) ||
                   i == strNum2Int(plan[j]) - (x-j-1) ) {flag2 = true; break;}
            }
            if(flag2) continue;

            dfs(x+1, plan+std::to_string(i));
        }
    }
};


#if 0
int main()
{
    Solution s;
    // test case
    auto ans = s.solveNQueens(4);
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[i].size(); ++j) {
            printf("%s\n", ans[i][j].c_str());
        }
        printf("\n");
    }
    return 0;
}
#endif