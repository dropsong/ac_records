// link: https://leetcode.cn/problems/majority-element/description/
// 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

#include <vector>
#include <unordered_map>
#include <iostream>
using std::vector;
using std::unordered_map;

class Solution_dummy {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(const auto& num : nums) {
            cnt[num]++;
            if(cnt[num] > nums.size() / 2) {
                return num;
            }
        }
        return -1;
    }
};

class Solution {
public:
    // Boyer-Moore 投票算法
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate = nums[0];
        for(const auto& num : nums) {
            if(!cnt) candidate = num;
            if(num == candidate) cnt++;
            else cnt--;
        }
        return candidate;
    }
};

#if 0
int main() {
    Solution s;
    vector<int> case1 = {3, 2, 3};   // 3
    vector<int> case2 = {2, 2, 1, 1, 1, 2, 2};  // 2
    std::cout << s.majorityElement(case1) << std::endl;
    std::cout << s.majorityElement(case2) << std::endl;
    return 0;
}
#endif