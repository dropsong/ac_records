// https://leetcode.cn/problems/product-of-array-except-self/description/
// 前缀积和后缀积

#include <vector>
#include <cstdio>
using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        s[0] = nums[0]; b[nums.size()-1] = nums[nums.size()-1];
        for(int i = 1; i < nums.size(); ++i) {
            s[i] = s[i-1] * nums[i];
        }
        for(int i = nums.size()-2; i >= 0; --i) {
            b[i] = b[i+1] * nums[i];
        }

        vector<int> ans; ans.push_back(b[1]);
        for(int i = 1; i < nums.size()-1; ++i) {
            ans.push_back(s[i-1]*b[i+1]);
        }
        ans.push_back(s[nums.size()-2]);

        return ans;
    }

private:
    int s[100005], b[100005];
};

#if 0
int main()
{
    Solution s;
    // test case 1
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> ans1 = s.productExceptSelf(nums1);
    for (int i : ans1) {
        printf("%d ", i);
    }
    return 0;
}
#endif