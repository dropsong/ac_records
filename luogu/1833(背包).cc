// Author: dropsong, https://github.com/dropsong
// link: https://www.luogu.com.cn/problem/P1833
// ideas: https://github.com/tianyicui/pack/blob/master/V2.pdf

# include <iostream>
# include <string>

const int MAXN = 1e4 + 5;
int n, t[MAXN], c[MAXN], p[MAXN], f[1005];


int calc_time(const std::string& ts, const std::string& te)
{
    int hour = stoi(te.substr(0, te.find_first_of(":") + 1))
               - stoi(ts.substr(0, te.find_first_of(":") + 1));
    int minute = stoi(te.substr(te.find_first_of(":") + 1))
                 - stoi(ts.substr(ts.find_first_of(":") + 1));
    return hour * 60 + minute;
}


int main()
{
    std::string ts, te;
    std::cin >> ts >> te >> n;
    int total_time = calc_time(ts, te);

    for(int i = 1; i <= n; ++i)
    {
        std::cin >> t[i] >> c[i] >> p[i];
    }

    for(int i = 1; i <= n; ++i)
    {
        for(int v = total_time; v >= 0; --v)
        {
            // p[i] = 0 means unlimited
            for(int k = 0; k <= (p[i]==0 ? 9999:p[i]); ++k)
            {
                if(v - k * t[i] < 0) break;
                f[v] = std::max(f[v], f[v - k * t[i]] + k * c[i]);
            }
        }
    }

    int ans = 0;
    for(int v = total_time; v >= 0; --v)
    {
        ans = std::max(ans, f[v]);
    }

    std::cout << ans;
    return 0;
}