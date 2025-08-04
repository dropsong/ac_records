// link: https://leetcode.cn/problems/3sum/description/
// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

#include <iostream>
#include <vector>

using std::vector;
using std::cout;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    }
};


#if 1
int main()
{
    Solution S;
    vector<int> input = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = S.threeSum(input);

    for(auto v : ans) {
        for(auto vv : v) {
            cout << vv;
        }
        cout << std::endl;
    }

    return 0;
}
#endif
