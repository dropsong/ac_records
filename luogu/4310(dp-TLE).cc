// link: https://www.luogu.com.cn/problem/P4310
// 注意理解题意，这个子序列在原序列中不一定是连续的
// 思路：仿照最长上升子序列的动态规划即可

#include <cstdio>
#include <algorithm>

int a[100005], dp[100005], ans;

int main()
{
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    dp[1] = 1, ans = 1;
    for(int i = 2; i <=n; ++i)
    {
        for(int j = 1; j < i; ++j)
        {
            if(a[j] & a[i])
            dp[i] = std::max(dp[i], dp[j]+1);
        }
        ans = std::max(ans, dp[i]);
    }

    printf("%d", ans);
    return 0;
}
