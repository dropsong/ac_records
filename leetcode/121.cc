// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;

        int pre_min = prices[0], ans = 0;
        for(int i = 1; i < prices.size(); ++i) {
            if(pre_min < prices[i]) ans = std::max(ans, prices[i]-pre_min);
            pre_min = std::min(pre_min, prices[i]);
        }

        return ans;
    }
};


#if 0
int main()
{
    // test case...
    return 0;
}
#endif