// https://leetcode.cn/problems/jump-game-ii/description/

#include <vector>
#include <cstring>
#include <iostream>
using std::vector;
using std::cout;

class Solution_dummy_dp {
public:
    Solution_dummy_dp() { memset(dp, 0, sizeof(dp)); }

    int jump(vector<int>& nums) {
        return work(nums, nums.size()-1);
    }

private:
    int dp[10000];

    int work(vector<int>& nums, int x) {
        if(dp[x]) return dp[x];
        if(x == 0) return 0;
        int ans = 0x7fffffff;
        for(int i = 0; i < x; ++i) {
            if(i+nums[i] < x) continue;
            ans = std::min(ans, work(nums, i)+1);
        }
        dp[x] = ans;
        return dp[x];
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int max_far = 0;   // 目前能跳到的最远位置
        int step = 0;      // 跳跃次数
        int end = 0;       // 上次跳跃可达范围右边界（下次的最右起跳点）
        for (int i = 0; i < nums.size() - 1; i++)
        {
            max_far = std::max(max_far, i + nums[i]);
            // 到达上次跳跃能到达的右边界了
            if (i == end)
            {
                end = max_far;  // 目前能跳到的最远位置 变成了 下次起跳位置的右边界
                step++;         // 进入下一次跳跃
                if (end == nums.size() - 1) { // 说明这一次的跳跃也就可以到达最后位置，i就不用再去看后面再跳一次能到哪里了
                    break;
                }
            }
        }
        return step;
    }
};

#if 0
int main()
{
    // test case
    vector<int> case1 = {2, 3, 1, 1, 4};
    vector<int> case2 = {2, 3, 0, 1, 4};
    Solution s;
    cout << s.jump(case1) << std::endl;
    cout << s.jump(case2) << std::endl;
    return 0;
}
#endif