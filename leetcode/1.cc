// 复杂度：
// 放入 map:  log1+log2+...+logn = O(logn!) < O(nlogn)
// 线性的查找同时还需要查找 map
// 估计的复杂度是低于 O(n^2) 的

#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m = put_in_map(nums);
        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];
            if(m.find(complement) != m.end() && m[complement] != i){
                return {i, m[complement]};
                // {i, m[complement]} 会构造一个右值 vector<int>，其中包含两个元素：i 和 m[complement]
            }
        }
        return {-1, -1};  // 没有找到
    }

    map<int,int> put_in_map(vector<int>& nums){
        map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]] = i;
        }
        return m;
    }
};