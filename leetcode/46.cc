// https://leetcode.cn/problems/permutations/description/
// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        _nums = nums; // 直接赋值，而不是逐个拷贝
        vis.resize(nums.size(), false); // 初始化 vis 数组大小
        vector<int> current; // 用于存储当前排列
        work(0, current);
        return ans;
    }

private:
    vector<int> _nums;
    vector<vector<int>> ans;
    vector<bool> vis;

    void work(int dep, vector<int>& current) {
        if (dep == _nums.size()) {
            ans.push_back(current); // 将当前排列加入结果
            return;
        }
        for (int i = 0; i < _nums.size(); ++i) {
            if (vis[i]) continue;
            vis[i] = true;
            current.push_back(_nums[i]); // 添加当前数字到排列
            work(dep + 1, current);
            current.pop_back(); // 回溯
            vis[i] = false;
        }
    }
};

#if 0
int main() {
    Solution s;
    vector<int> test = {1, 2, 3};
    auto qwq = s.permute(test);
    for (auto& i : qwq) {
        for (auto& j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
#endif
