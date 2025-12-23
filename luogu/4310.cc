// link: https://www.luogu.com.cn/problem/P4310
// ref: https://www.luogu.com.cn/problem/solution/P4310
// ref-author: 灵乌路空
// 实际上这个思路是，把序列中的每个数用二进制画出来，人脑怎么解题，代码就去模拟这个过程

#include <cstdio>
#include <cmath>
#include <algorithm>

const int MAXN = 1e5+5;
int dp[MAXN], bit[32], ans;

int lowbit(int x) { return x & (-x); }

int main()
{
    int n; scanf("%d", &n);
    for(int i = 1; i <=n; ++i)
    {
        int tmp; scanf("%d", &tmp);
        int ones[32], p = 0;
        while(tmp)
        {
            int pos = std::log2(lowbit(tmp));
            ones[p++] = pos;
            dp[i] = std::max(dp[i], bit[pos]+1);
            tmp ^= lowbit(tmp);
        }
        for(int j = 0; j < p; ++j) bit[ones[j]] = dp[i];
        ans = std::max(ans, dp[i]);
    }

    printf("%d\n", ans);
    return 0;
}
