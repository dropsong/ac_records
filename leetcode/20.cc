// https://leetcode.cn/problems/valid-parentheses/description/
// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

#include <iostream>
#include <string>

using std::cout;
using std::string;


class Solution {
public:
    bool isValid(string s) {
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(') stac[++top] = '(';
            else if(s[i] == '[') stac[++top] = '[';
            else if(s[i] == '{') stac[++top] = '{';

            else if(s[i] == ')') {
                if(stac[top] != '(') return false;
                else --top;
            }
            else if(s[i] == ']') {
                if(stac[top] != '[') return false;
                else --top;
            }
            else if(s[i]== '}') {
                if(stac[top] != '{') return false;
                else --top;
            }
        }
        if(top) return false;
        return true;
    }

private:
    int top = 0;
    char stac[10005];
};


#if 0
int main()
{
    // write an example if you wish...
    return 0;
}
#endif