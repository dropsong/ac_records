// https://leetcode.cn/problems/rotate-array/description/

#include <vector>
#include <algorithm>
using std::vector;

class Solution_dummy {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        vector<int> ans;
        // nums.size()-k ~ nums.size()-1   put to front
        for(int i = nums.size()-k; i < nums.size(); ++i) {
            ans.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size()-k; ++i) {
            ans.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size(); ++i) {
            nums[i] = ans[i];
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin()+k);
        std::reverse(nums.begin()+k, nums.end());
    }

};

#if 0
int main()
{
    // test case...
    return 0;
}
#endif