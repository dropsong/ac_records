// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
// 如果数组中不存在目标值 target，返回 [-1, -1]。
// 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

#include <vector>
#include <iostream>
using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};

        int l = 0, r = nums.size();
        while(l < r) {
            int mid = (l+r) / 2;
            if(nums[mid] <= target) { l = mid+1; }  // 试图找到右边界
            if(nums[mid] > target) { r = mid; }
        }
        ans[1] = l-1;   // l 停在右边界的尾后

        l = 0, r = nums.size();
        while(l < r) {
            int mid = (l+r) / 2;
            if(nums[mid] < target) { l = mid+1; }
            if(nums[mid] >= target) { r = mid; }
        }
        ans[0] = l;

        if(ans[0] > ans[1]) return {-1, -1};
        return ans;
    }
};

#if 0
int main()
{
    vector<int> case1 = {5, 7, 7, 8, 8, 10};
    vector<int> case2 = {};
    Solution s;

    vector<int> ans1 = s.searchRange(case1, 8);
    std::cout << ans1[0] << " " << ans1[1] << std::endl;  // 3 4

    vector<int> ans2 = s.searchRange(case1, 6);
    std::cout << ans2[0] << " " << ans2[1] << std::endl;  // -1 -1

    vector<int> ans3 = s.searchRange(case2, 0);
    std::cout << ans3[0] << " " << ans3[1] << std::endl;  // -1 -1

    return 0;
}
#endif