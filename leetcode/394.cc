// https://leetcode.cn/problems/decode-string/description/
// 给定一个经过编码的字符串，返回它解码后的字符串。
// 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    string decodeString(string s) {
        string tmp;
        for(int i = 0; i < s.size(); ++i) {
            if(isdigit(s[i])) {
                string num; num += s[i];
                while(isdigit(s[++i])) num += s[i];
                --i;
                int k = std::stoi(num);

                int flag = 0;   // 用于 [] 匹配
                bool collecting = false, run = true;
                string sub_s;

                do {
                    ++i;
                    if(flag == 1) collecting = true;
                    if(s[i] == '[') flag++;
                    else if(s[i] == ']') flag--;
                    if(flag == 0) { collecting = false; run = false; }
                    if(collecting) sub_s += s[i];
                } while(run);

                while(k--) { tmp += decodeString(sub_s); }
                continue;
            }
            tmp += s[i];
        }
        return tmp;
    }
};

#if 0
int main()
{
    // test case
    string pattern = "3[a2[c]]";     // accaccacc
    string pattern2 = "10[leetcode]";
    Solution sol;
    cout << sol.decodeString(pattern) << endl;
    cout << sol.decodeString(pattern2) << endl;
    return 0;
}
#endif