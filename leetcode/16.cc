// link: https://leetcode.cn/problems/3sum-closest/description/
// github: https://github.com/dropsong
/*
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
返回这三个数的和。
假定每组输入只存在恰好一个解。
*/

#include <vector>
#include <iostream>
#include <algorithm>
// #define DEBUG

using std::vector;
using std::cout;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int best = 1e7;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;

            int j = i+1, k = nums.size()-1;
            while(j < k)
            {
                int cur = nums[i] + nums[j] + nums[k];
                if(cur == target) return cur;

                if(abs(cur-target) < abs(best-target)) {
                    best = cur;
                }

                if(cur < target) {
                    int j0 = j+1;
                    while(j0 < k && nums[j0] == nums[j]) j0++;
                    j = j0;
                } else {
                    int k0 = k-1;
                    while(k0 > j && nums[k0] == nums[k]) k0--;
                    k = k0;
                }
            }
        }

        return best;
    }
};


#ifdef DEBUG
int main()
{
    Solution S;
    vector<int> n = {-1,2,1,-4};
    cout << S.threeSumClosest(n, 1);
    return 0;
}
#endif
