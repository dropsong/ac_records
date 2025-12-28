// https://leetcode.cn/problems/sliding-window-maximum/description/

/*
入队前“清理后辈”：当新元素 nums[i] 准备入队时，从队尾开始，把所有小于等于它的元素全部弹出。
入队：将当前索引 i 放入队尾。
出队“清理前辈”：检查队首的索引是否已经超出了窗口范围（即 index < i - k + 1），如果是，则弹出。
取最大值：由于每次都清掉了较小的元素，队首元素永远是当前窗口的最大值。
*/

#include <vector>
#include <deque>
#include <iostream>

using std::vector;
using std::deque;
using std::cout;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> qwq;
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i)
        {
            while(!qwq.empty() && nums[qwq.back()] <= nums[i]){
                qwq.pop_back();
            }
            qwq.push_back(i);
            if(qwq.front() < i-k+1) qwq.pop_front();
            if(i >= k-1) ans.push_back(nums[qwq.front()]);
        }
        return ans;
    }
};


#if 0
int main()
{
    Solution s;
    vector<int> test = {1,3,-1,-3,5,3,6,7}; int k = 3;
    //vector<int> test = {1}; int k = 1;
    vector<int> out = s.maxSlidingWindow(test, k);
    for(auto e : out) { std::cout << e << " "; }
    return 0;
}
#endif
