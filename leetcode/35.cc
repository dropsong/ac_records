// https://leetcode.cn/problems/search-insert-position/description/

#include <iostream>
#include <vector>

using std::cout;
using std::vector;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r) { // 左闭右开，l < r 才有解
            int mid = (l + r) / 2;  // won't exceed
            if(nums[mid] == target) { return mid; }
            if(nums[mid] < target) { l = mid + 1; }
            else if(nums[mid] > target) { r = mid; }
        }
        return l;
    }
};


#if 0
int main()
{
    Solution s;
    vector<int> test = {1, 3, 5, 6};
    cout << s.searchInsert(test, 2);
    return 0;
}
#endif