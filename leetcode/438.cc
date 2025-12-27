// https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
// p.size() 长度范围内，每个字母出现多少次
// util[s.len][a-z]   // O(n) to calc
// for i: 0 -> ?? 
// for 'a' -> 'z': 
//     util[i+1]['a'] = util[i]['a'] - (s[i]=='a') + (s[i+p.len]=='a')
// p 的特征？
// O(n) 遍历一遍 s，符合特征的记下位置

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using std::cout;
using std::vector;
using std::string;


class Solution {
public:
    Solution() {
        memset(util, 0, sizeof(util));
        memset(pattern, 0, sizeof(pattern));
    }

    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) {
            return vector<int>();
        }

        for(int i = 0; i < p.size() ; ++i)
        {
            util[0][s[i]-'a']++;
            pattern[p[i]-'a']++;
        }

        {
        bool front_flag = true;
        for(int j = 0; j < 26; ++j)
            if(util[0][j] != pattern[j]) front_flag = false;
        if(front_flag) ans.push_back(0);
        }
        
        for(int i = 0; ; ++i)
        {
            bool flag = true;
            for(int j = 0; j < 26; ++j)
            {
                if(i+p.size() < s.size())
                    util[i+1][j] = util[i][j] - (s[i]-'a' == j) + (s[i+p.size()]-'a' == j);
                else goto AKASHI;
                if(util[i+1][j] != pattern[j]) flag = false;
            }
            if(flag) ans.push_back(i+1);
        }
        AKASHI: {}
        return ans;
    }

private:
    int util[30005][26];
    int pattern [26];
    vector<int> ans;
};


#if 0
int main()
{
    Solution so;
    // string s = "cbaebabacd";
    // string p = "abc";
    string s = "abab";
    string p = "ab";

    vector<int> getAns = so.findAnagrams(s, p);
    for(auto e : getAns)
        cout << e;
    return 0;
}
#endif
