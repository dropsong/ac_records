// https://leetcode.cn/problems/jump-game/description/
// 给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
// 判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。

#include <vector>
#include <iostream>
using std::vector;

class Solution_tle {    //  123/178 个通过的测试用例
public:
    bool canJump(vector<int>& nums) {
        vector<int> vis(nums.size()+5, 0); // -1 false, 0 uninit, 1 true
        return work(0, nums, vis);
    }

private:
    bool work(int pos, vector<int>& nums, vector<int>& vis) {
        if(pos >= nums.size()-1) { 
            return true;
        }
        if(vis[pos] != 0) return vis[pos] == 1 ? true : false;

        bool flag = false;
        for(int i = 1; i <= nums[pos]; ++i) {
            flag |= work(pos + i, nums, vis);
        }
        vis[pos] = flag ? 1 : -1;
        return flag;
    }
};

class Solution {
// 思路： 维护最远可以达到的位置，贪心
public:
    bool canJump(vector<int>& nums) {
        int far = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(i <= far) {
                far = std::max(far, i+nums[i]);
                if(far >= nums.size()-1) { return true; }
            }
        }
        return false;
    }
};

#if 0
int main()
{
    // test case
    vector<int> case1 = {2, 3, 1, 1, 4};
    vector<int> case2 = {3, 2, 1, 0, 4};
    vector<int> case3 = {2, 5, 0, 0};
    vector<int> case4 = {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    Solution s;
    std::cout << s.canJump(case1) << std::endl;  // 1
    std::cout << s.canJump(case2) << std::endl;  // 0
    std::cout << s.canJump(case3) << std::endl;
    std::cout << s.canJump(case4) << std::endl;
    return 0;
}
#endif