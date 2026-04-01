// https://leetcode.cn/problems/house-robber/description/
// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

#include <vector>
#include <cstring>
#include <iostream>
using std::vector;

// dp(i) = MAX( dp(i-1), dp(i-2)+nums(i) )
class Solution {
public:
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return work(nums.size()-1, nums);
    }

private:
    int dp[105];
    int work(int x, const vector<int>& nums) {
        if(dp[x] != -1) return dp[x];
        if(x == 0) return nums[0];
        if(x == 1) return std::max(nums[0], nums[1]);
        dp[x] = std::max(work(x-1, nums), work(x-2, nums) + nums[x]);
        return dp[x];
    }
};

#if 0
int main()
{
    // test case
    vector<int> case1 = {1, 2, 3, 1};
    vector<int> case2 = {2, 7, 9, 3, 1};
    vector<int> case3 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    Solution s;
    std::cout << s.rob(case1) << std::endl;
    std::cout << s.rob(case2) << std::endl;
    std::cout << s.rob(case3) << std::endl;
    return 0;
}
#endif