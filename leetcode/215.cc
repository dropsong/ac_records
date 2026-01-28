// https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
// 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::vector;
using std::priority_queue;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(auto e : nums) {
            qwq.push(e);
            if(qwq.size() > k) qwq.pop(); // pop 掉最小的堆顶
        }
        return qwq.top();
    }

private: 
    priority_queue<int, vector<int>, std::greater<int>> qwq;  // 小根堆
};


#if 0
int main()
{
    Solution s;
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << s.findKthLargest(nums, k) << "\n"; // 5
    return 0;
}
#endif