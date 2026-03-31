// https://leetcode.cn/problems/daily-temperatures/description/
// 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。

#include <vector>
#include <cstdio>
#include <stack>
using std::vector;

class Solution_tle {  // O(n^2)，暴力解法，超时
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<bool> done(temperatures.size(), false);
        vector<int> ans(temperatures.size(), 0);  // 这里的语法不熟练，需要掌握

        int p = 1;
        while(p < temperatures.size()) {
            for(int i = 0; i < p; ++i) {
                if(done[i]) continue;
                if(temperatures[p] > temperatures[i]) {
                    ans[i] = p - i;
                    done[i] = true;
                }
            }
            ++p;
        }
        return ans;
    }
};

class Solution_dummy {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> stac; // 单调栈，存编号，从底到顶对应元素值越来越小
        vector<int> ans(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); ++i) {
            while(!stac.empty() && temperatures[i] > temperatures[stac.back()]) {
                ans[stac.back()] = i-stac.back();
                stac.pop_back();
            }
            stac.push_back(i);
        }
        return ans;
    }
};

class Solution {  // 这个似乎还更慢了
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> stac; // 单调栈，存编号，从底到顶对应元素值越来越小
        vector<int> ans(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); ++i) {
            while(!stac.empty() && temperatures[i] > temperatures[stac.top()]) {
                ans[stac.top()] = i-stac.top();
                stac.pop();
            }
            stac.push(i);
        }
        return ans;
    }
};

#if 0
int main()
{
    // test case
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution sol;
    vector<int> ans = sol.dailyTemperatures(temperatures);
    for(int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}
#endif