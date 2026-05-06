// link: https://leetcode.cn/problems/single-number/description/
// 给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
// 你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

#include <vector>
#include <cstdio>

using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(const auto& num : nums) {
            ans = ans ^ num;
        }
        return ans;
    }
};

#if 0
int main() {
    // test case 1
    vector<int> nums1 = {2, 2, 1};
    Solution sol;
    int result1 = sol.singleNumber(nums1);
    printf("Test case 1 result: %d\n", result1); // Expected output: 1
    // test case 2
    vector<int> nums2 = {4, 1, 2, 1, 2};
    int result2 = sol.singleNumber(nums2);
    printf("Test case 2 result: %d\n", result2); // Expected output: 4
    return 0;
}
#endif