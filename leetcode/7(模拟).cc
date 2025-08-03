// link: https://leetcode.cn/problems/reverse-integer/description/

#include <string>
#include <iostream>

using std::string;
using std::cout;


class Solution {
public:
    int reverse(int x) {
        string s = std::to_string(x);
        string ans = "";
        for(auto it = s.end()-1; ; it--) {
            ans += *it;
            if(it == s.begin()) break;
        }

        if(ans == "0" || ans == "-0") return 0;

        int p = 0;
        while(ans[p] == '0') p++;

        string ans2 = "";
        if(s[0] == '-') ans2 += "-";
        for(int i = p; i < ans.size(); ++i)
        {
            ans2 += ans[i];
        }

        long long k = std::stoll(ans2);
        if(k > 2147483647 || k < -2147483648) k = 0;
        return static_cast<int>(k);
    }
};


#if 0
int main()
{
    Solution S;
    int test; std::cin >> test;
    cout << S.reverse(test);
    return 0;
}
#endif
