// https://leetcode.cn/problems/pascals-triangle/description/
// 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; ++i) {
            ans.push_back(vector<int>(i + 1, 1)); // 每一行的长度为 i + 1，初始化为 1
            for (int j = 1; j < i; ++j) { // 从第 2 列到倒数第 2 列
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans;
    }
};

#if 0
int main()
{
    Solution s;
    vector<vector<int>> tmp = s.generate(5);
    for (auto e1 : tmp) {
        for (auto e2 : e1)
            cout << e2 << " ";
        cout << std::endl;
    }
    return 0;
}
#endif