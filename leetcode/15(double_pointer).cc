// link: https://leetcode.cn/problems/3sum/description/
// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i) {

            if(i>0 && nums[i] == nums[i-1]) continue;
            int k = nums.size() - 1;     // c 对应的指针初始指向数组的最右端
            int target = -nums[i];

            for(int j = i+1; j < nums.size(); ++j) {

                if(j>i+1 && nums[j] == nums[j-1]) continue;
                while(j<k && nums[j] + nums[k] > target) k--;

                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if(j == k) break;

                if(nums[j] + nums[k] == target) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }

        return ans;
    }
};


#if 0
int main()
{
    Solution S;
    vector<int> input = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = S.threeSum(input);

    for(auto v : ans) {
        for(auto vv : v) {
            cout << vv << " ";
        }
        cout << std::endl;
    }

    return 0;
}
#endif
