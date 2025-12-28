// https://leetcode.cn/problems/subarray-sum-equals-k/description/
// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
// 子数组是数组中元素的连续非空序列。

/*
初始化：
- 哈希表 `prefix_sum_count`，用于记录每个前缀和出现的次数。初始时，前缀和为 `0` 出现 `1` 次（表示没有元素时，前缀和为 `0`）。
- 当前前缀和 `current_sum = 0`，结果计数器 `count = 0`。

遍历数组：
- 更新当前前缀和： `current_sum += nums[i]`。
- 计算目标前缀和： `target = current_sum - k`。
- 如果 `target` 存在于哈希表中，则说明存在若干个子数组（从之前的某个位置到当前位置）的和为 `k`，将对应的次数添加到 `count`。
- 将当前前缀和 `current_sum` 加入哈希表，并更新出现次数。

返回结果：遍历完成后，`count` 即为所求。
*/

#include <vector>
#include <iostream>
#include <unordered_map>

using std::vector;
using std::cout;
using std::unordered_map;


class Solution {
public:
    Solution() { prefix_sum_count[0] = 1; }

    int subarraySum(vector<int>& nums, int k) {
        int current_sum = 0, cnt = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            current_sum += nums[i];
            int target = current_sum - k;
            if(prefix_sum_count.count(target)) cnt += prefix_sum_count[target];
            prefix_sum_count[current_sum]++;
        }
        return cnt;
    }

private: 
    unordered_map<int, int> prefix_sum_count;
};


#if 0
int main()
{
    Solution s;
    vector<int> nn = {1, 1, 1}; int k = 2;
    // vector<int> nn = {1, 2, 3}; int k = 3;
    // vector<int> nn = {6, 4, 3, 1}; int k = 10;
    // vector<int> nn = {1, -1, 0}; int k = 0;
    cout << s.subarraySum(nn, k);
    return 0;
}
#endif
