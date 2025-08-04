// link: https://leetcode.cn/problems/3sum/description/
// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
// 313 / 314 个通过的测试用例

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
                int subsum = nums[i] + nums[j];
                int l = j+1, r = nums.size(), mid = -1;
                bool flag = false;
                while(l < r) {
                    mid = (l+r)/2;
                    if(subsum + nums[mid] == 0) {
                        flag = true;
                        break;
                    }
                    else if(subsum + nums[mid] < 0) {l = mid + 1;}
                    else {r = mid;}
                }

                if(flag) {
                    if(mymap.count({nums[i], nums[j], nums[mid]}) == 0) {
                        ans.push_back({nums[i], nums[j], nums[mid]});
                        mymap.insert({nums[i], nums[j], nums[mid]});
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
            cout << vv << " ";
        }
        cout << std::endl;
    }

    return 0;
}
#endif
