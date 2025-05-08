// https://leetcode.cn/problems/longest-palindromic-substring/description/
#include <string>
#include <vector>
using std::string;
using std::vector;


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;

        int max_len = 1, pos = 0;

        vector<vector<bool>> dp(n, vector<bool>(n));
        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = true;
        }

        // 枚举子串长度
        for(int len = 2; len <=n; ++len)
        {
            // 枚举左边界
            for(int i = 0; i < n; ++i)
            {
                int j = i + len - 1;
                if(j >= n) break;

                if(s[i] != s[j])
                {
                    dp[i][j] = false;
                }
                else {
                    if(len <= 2)
                    {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if(dp[i][j] && len > max_len)
                {
                    max_len = len;
                    pos = i;
                }
            }
        }
        return s.substr(pos, max_len);
    }
};


// #include <iostream>
// using std::cout;
// using std::endl;
// int main()
// {
//     Solution sol;
//     string s1 = "a";
//     string s2 = "aa";
//     string s3 = "cbbd";
//     string s4 = "babad";
// 
//     cout << sol.longestPalindrome(s1) << endl;
//     cout << sol.longestPalindrome(s2) << endl;
//     cout << sol.longestPalindrome(s3) << endl;
//     cout << sol.longestPalindrome(s4) << endl;
//     
//     return 0;
// }