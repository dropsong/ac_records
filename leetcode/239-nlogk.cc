// https://leetcode.cn/problems/sliding-window-maximum/description/

#include <vector>
#include <set>
#include <iostream>

using std::vector;
using std::set;


struct node
{
    int value;
    int idx;
    bool operator < (const node& rhs) const {
        if(value != rhs.value) return value > rhs.value;
        return idx > rhs.idx;  // 这里其实无所谓
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); ++i)
        {
            if(lookup.size() < k)
            {
                lookup.insert({nums[i], i});
                if(lookup.size() == k) { ans.push_back(lookup.begin()->value); }
                continue;
            }

            lookup.insert({nums[i], i});
            lookup.erase({nums[i-k], i-k});
            ans.push_back(lookup.begin()->value);
        }
        return ans;
    }

private:
    set<node> lookup;
    vector<int> ans;
};


#if 0
int main()
{
    Solution s;
    // vector<int> test = {1,3,-1,-3,5,3,6,7}; int k = 3;
    vector<int> test = {1}; int k = 1;
    vector<int> out = s.maxSlidingWindow(test, k);
    for(auto e : out) { std::cout << e << " "; }
    return 0;
}
#endif
