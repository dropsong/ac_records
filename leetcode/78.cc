// https://leetcode.cn/problems/subsets/description/

#include <vector>
#include <cstring>
#include <cstdio>

using std::vector;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        vector<int> path;
        work(0, nums, path);
        return ans;
    }

private:
    vector<vector<int>> ans;
    void work(int pos, vector<int>& nums, vector<int> path) {
        if(pos == nums.size()) {
            ans.push_back(path);
            return;
        }
        path.push_back(nums[pos]);
        work(pos+1, nums, path);
        path.pop_back();
        work(pos+1, nums, path);
    }
};


#if 0
int main()
{
    Solution s;
    vector<int> case1 = {1, 2, 3};
    vector<vector<int>> ans1 = s.subsets(case1);
    for(auto e : ans1) {
        for(auto ee : e)
            printf("%d ", ee);
        printf("\n");
    }
    return 0;
}
#endif