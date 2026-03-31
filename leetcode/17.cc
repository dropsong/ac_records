// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/

#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        ans.clear();
        work(0, "", digits);
        return ans;
    }

private:
    static const vector<string> i2str;
    vector<string> ans;

    void work(int pos, string str, const string& digits) {
        if(pos == digits.size()) {
            ans.push_back(str);
            return;
        }
        string ch = i2str[digits[pos]-'0'];
        for(int i = 0; i < ch.size(); ++i) {
            work(pos+1, str+ch[i], digits);
        }
    }
};

const vector<string> Solution::i2str = {
    "",    "",    "abc",  "def",  "ghi",  "jkl",  "mno",  "pqrs", "tuv",  "wxyz" 
};

#if 0
int main()
{
    // test case
    string digits = "23";
    Solution sol;
    vector<string> ans = sol.letterCombinations(digits);
    for(int i = 0; i < ans.size(); ++i) {
        printf("%s\n", ans[i].c_str());
    }
    return 0;
}
#endif