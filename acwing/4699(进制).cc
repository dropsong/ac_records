// https://www.acwing.com/problem/content/description/4702/
// 若链接无效可在 archive.org 上搜索

#include <cstdio>

const int MAXN = 24;
int a[MAXN], c[MAXN], b[MAXN], n, m;

int main()
{
    scanf("%d%d", &n, &m);
    c[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        c[i] = c[i-1] * a[i];
    }

    for(int i = n; i >= 1; i--)
    {
        b[i] = m / c[i-1];
        m = m - c[i-1] * b[i];
    }

    for(int i = 1; i <= n; i++)
    {
        printf("%d ", b[i]);
    }

    return 0;
}