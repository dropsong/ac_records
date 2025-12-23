// link: https://leetcode.cn/problems/move-zeroes/description/

#include <vector>
#include <algorithm>
#include <cstdio>

using std::vector;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto it = remove_if(nums.begin(), nums.end(), [](int x)->bool{return x==0;});
        fill(it, nums.end(), 0);
    }
};


#if 0
int main()
{
    Solution s;
    vector<int> nums = {0,1,0,3,12};
    s.moveZeroes(nums);
    // print
    for (int num : nums) {
        printf("%d ", num);
    }
    return 0;
}
#endif
