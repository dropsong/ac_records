// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using std::string;
using std::unordered_set;
using std::cout;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 1) return 1;

        int p = 0; int q = 0;
        content.insert(s[0]);
        int ans = 0;
        for(int i = 1; i < s.size(); ++i)
        {
            q++;
            if(content.find(s[i]) != content.end())
            {
                // 删除，一直到删除第一个与 s[q] 值相同的元素为止
                while(s[p] != s[q]) {
                    content.erase(s[p]);
                    p++;
                }
                content.erase(s[p++]);
            }
            content.insert(s[i]);
            ans = std::max(ans, q-p+1);
        }
        return ans;
    }

private:
    unordered_set<char> content;
};


#if 0
int main()
{
    Solution S;
    cout << S.lengthOfLongestSubstring(" ");
    return 0;
}
#endif