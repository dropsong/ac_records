#include<bits/stdc++.h>
using namespace std;
int x[25], n, k, cnt;
bool is_prime(long long n)
{
    for (long long i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}
void dfs(int i, int r, long long sum)
{
    if (n - i < r)return;
    if (r == 0) 
    {
        if (is_prime(sum)) cnt++;
        return;
    }
    dfs(i + 1, r - 1, sum + x[i]);
    dfs(i + 1, r, sum);
}
int main()
{
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; ++i)
        scanf("%d",&x[i]);
    dfs(0, k, 0);
    cout << cnt << endl;
}