// https://leetcode.cn/problems/minimum-size-subarray-sum/description/
// 给定一个含有 n 个正整数的数组和一个正整数 target 。
// 找出该数组中满足其总和大于等于 target 的长度最小的 子数组（要求在原数组中连续），并返回其长度。如果不存在符合条件的子数组，返回 0 。

#include <vector>
#include <iostream>
using std::vector;

class Solution_dummy {  // nlogn， 二分答案
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        sum.clear(); sum.resize(nums.size());
        sum[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            sum[i] = sum[i-1] + nums[i];
        }
        int l = 1, r = nums.size()+1;  // 找的是长度，左闭右开
        while(l < r) {
            int mid = (l+r) / 2;
            if(check(mid, target, nums)) { r = mid; }  // mid 长度通过，但是要在右边界排除 mid, 因为最后 l 会回到
            else { l = mid+1; }
        }
        if(l > nums.size() ) return 0;
        return l;
    }

private:
    vector<int> sum;
    bool check(int x, int target, vector<int>& nums) {
        for(int i = 0; i+x-1 < nums.size(); ++i) {
            if(sum[i+x-1] - sum[i] + nums[i] >= target) return true;
        }
        return false;
    }
};

class Solution {  // 双指针
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, sum = 0;
        int ans = 0x7fffffff;
        while(r < nums.size()) {
            while(sum < target && r < nums.size()) {
                sum += nums[r++];
            }
            if(r-l == nums.size() && sum < target) return 0;
            ans = std::min(ans, r-l);
            while(sum >= target) {
                ans = std::min(ans, r-l);
                sum -= nums[l++];
            }
        }
        return ans;
    }
};

#if 0
int main()
{
    Solution s;
    // test case
    vector<int> case1 = {2, 3, 1, 2, 4, 3};
    vector<int> case2 = {1, 4, 4};
    vector<int> case3 = {1, 1, 1, 1, 1, 1, 1, 1};
    vector<int> case4 = {1, 2, 3, 4, 5};
    std::cout << s.minSubArrayLen(7, case1) << std::endl;   // 2
    std::cout << s.minSubArrayLen(4, case2) << std::endl;   // 1
    std::cout << s.minSubArrayLen(11, case3) << std::endl;  // 0
    std::cout << s.minSubArrayLen(15, case4) << std::endl;  // 5
    return 0;
}
#endif