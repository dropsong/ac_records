// link: https://leetcode.cn/problems/3sum/description/
// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
// 309 / 314 个通过的测试用例

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::unordered_set;


struct VectorHasher {
    std::size_t operator()(const std::vector<int>& vec) const {
        std::size_t seed = vec.size();
        for(int i : vec) {
            // 一个简单的哈希组合算法
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<vector<int>, VectorHasher> mymap;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i+1; j < nums.size(); ++j) {
                for(int k = j+1; k < nums.size(); ++k) {
                    if(nums[i]+nums[j]+nums[k] > 0) break;
                    if(nums[i]+nums[j]+nums[k] == 0) {
                        if(mymap.count({nums[i], nums[j], nums[k]}) == 0) {
                            ans.push_back({nums[i], nums[j], nums[k]});
                            mymap.insert({nums[i], nums[j], nums[k]});
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};


#if 0
int main()
{
    Solution S;
    vector<int> input = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = S.threeSum(input);

    for(auto v : ans) {
        for(auto vv : v) {
            cout << vv;
        }
        cout << std::endl;
    }

    return 0;
}
#endif
