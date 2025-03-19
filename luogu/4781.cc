#include <cstdio>

using ll = long long;


namespace LagrangeInterpolation {

static const int MOD = 998244353;

ll qpow (ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

ll inv (ll x) {
    return qpow (x, MOD - 2);
}

/**
 * 用 n 个点 (x[1], y[1]), (x[2], y[2]), ..., (x[n], y[n])
 * 插值得到 n - 1 次多项式 L，直接求解 L(x0) 的值
 *
 * 时间复杂度: O(n^2)
 * 空间复杂度：O(1)
*/
ll lagrange_interpolation (ll x0, ll *x, ll *y, int n) {
    for (int i = 1; i <= n; ++i) {
        if (x0 == x[i]) {
            return y[i];
        }
    }
    ll Lx0 = 0;
    ll P = 1;
    for (int i = 1; i <= n; ++i) {
        P = P * (x0 - x[i] + MOD) % MOD;
    }
    for (int i = 1; i <= n; ++i) {
        ll q = 1;
        for (int j = 1; j <= n; ++j) {
            if (j == i) {
                continue;
            }
            q = q * (x[i] - x[j] + MOD) % MOD;
        }
        ll p = P * inv (x0 - x[i] + MOD) % MOD;
        ll lix0 = p * inv (q) % MOD;
        Lx0 = (Lx0 + lix0 * y[i] % MOD) % MOD;
    }
    return Lx0;
}

};

const ll MAXN = 2e3+5;
ll xx[MAXN], yy[MAXN];

int main()
{
    ll n, k;
    scanf("%lld%lld", &n, &k);
    for(int i = 1; i <= n; i++){
        ll x, y;
        scanf("%lld%lld", &x, &y);
        xx[i] = x;
        yy[i] = y;
    }

    printf("%lld", LagrangeInterpolation::lagrange_interpolation(k, xx, yy, n));
    return 0;
}