// link: https://leetcode.cn/problems/longest-common-prefix/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// #define DEBUG

using std::cout;
using std::string;
using std::vector;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = 205;
        for(auto s : strs)
        {
            len = std::min(len, static_cast<int>(s.size()));
        }

        string ans = "";
        for(int pos = 0; pos < len; ++pos)
        {
            char ch = strs[0][pos];
            bool flag = true;
            for(auto s : strs)
            {
                if(s[pos] != ch) {
                    flag = false;
                    goto stop;
                }
            }
            ans += ch;
        }
        stop: {}
        return ans;
    }
};


#ifdef DEBUG
int main()
{
    vector<string> tmp = {"flower", "flow", "flight"};
    Solution S;
    string out = S.longestCommonPrefix(tmp);
    cout << out;
    return 0;
}
#endif
