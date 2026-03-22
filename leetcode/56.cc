// https://leetcode.cn/problems/merge-intervals/description/

#include <vector>
#include <algorithm>
#include <cstdio>

using std::vector;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return {};

        std::sort(intervals.begin(), intervals.end(),
                  [](const auto& a, const auto& b){ return a[0] < b[0]; });

        vector<vector<int>> ans;
        for(const auto& interval : intervals) {
            // 如果结果集为空，或者当前区间与结果集最后一个区间不重叠
            if(ans.empty() || interval[0]>ans.back()[1]) {
                ans.push_back(interval);
            } else { // 重叠时，更新右边界
                ans.back()[1] = std::max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};


#if 0
int main()
{
    Solution s;
    // test case
    vector<vector<int>> intervals1 = {{1,3},{2,6},{8,10},{15,18}};
    auto ans1 = s.merge(intervals1);
    // expected output: [[1,6],[8,10],[15,18]]
    for(const auto& e : ans1) {
        printf("[%d, %d] ", e[0], e[1]);
    }
    return 0;
}
#endif