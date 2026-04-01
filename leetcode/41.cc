// https://leetcode.cn/problems/first-missing-positive/description/
// 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
// 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。

#include <vector>
#include <iostream>
#include <unordered_set>
using std::vector;
using std::cout;
using std::endl;

class Solution_dummy {
public:
    int firstMissingPositive(vector<int>& nums) {
        std::unordered_set<int> qwq;
        for(const auto& num : nums) {
            if(num <= 0) continue;
            qwq.insert(num);
        }
        int ans = 1;
        while(qwq.count(ans)) ans++;
        return ans;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(auto& num : nums) {
            if(num <= 0) num = nums.size()+1;
        }
        for(auto& num : nums) {
            int val = abs(num);
            if(val >= 1 && val <= nums.size()) {
                if(nums[val-1] > 0) nums[val-1] *= -1;
            }
        }

        bool flag = false; int ans = nums.size() + 1;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0) {
                flag = true;
                ans = i+1;
                break;
            }
        }
        return ans;
    }
};

#if 0
int main()
{
    // test case;
    vector<int> case1 = {1, 2, 0};
    vector<int> case2 = {3, 4, -1, 1};
    vector<int> case3 = {7, 8, 9, 11, 12};
    Solution s;
    cout << s.firstMissingPositive(case1) << endl;
    cout << s.firstMissingPositive(case2) << endl;
    cout << s.firstMissingPositive(case3) << endl;
    return 0;
}
#endif