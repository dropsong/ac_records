// https://leetcode.cn/problems/maximum-subarray/description/

#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cout;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(dp[i-1] > 0) { dp[i] = dp[i-1] + nums[i]; }
            else { dp[i] = nums[i]; }
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};


#if 0
int main()
{
    Solution s;
    // vector<int> test = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> test = {1};
    cout << s.maxSubArray(test);
    return 0;
}
#endif
