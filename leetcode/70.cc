// https://leetcode.cn/problems/climbing-stairs/description/
// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

#include <iostream>


class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int pre2 = 1, pre1 = 2, pos = 2;
        int now = -1;
        while(pos != n) {
            now = pre1 + pre2;
            pre2 = pre1;
            pre1 = now;
            pos++;
        }
        return now;
    }
};


#if 0
int main()
{
    Solution s;
    for(int i = 1; i < 10; ++i)
        std::cout << s.climbStairs(i) << " ";
    return 0;
}
#endif
