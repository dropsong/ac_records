// https://leetcode.cn/problems/minimum-window-substring/description/
// 给定两个字符串 s 和 t，长度分别是 m 和 n，返回 s 中的 最短窗口 子串，使得该子串包含 t 中的每一个字符（包括重复字符）。如果没有这样的子串，返回空字符串 ""。
// 测试用例保证答案唯一。

#include <string>
#include <iostream>
#include <unordered_map>
using std::cout;
using std::endl;
using std::string;

// 双指针移动，每找到一个符合要求的就记录窗口大小，然后 shrink length l++，直到不满足要求为止。每次移动 r++，直到找到一个符合要求的窗口。
class Solution {   // 超赞模拟人脑法
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        tmap.clear(); wmap.clear();
        for(char c : t) tmap[c]++;
        int l = 0, r = 0, valid = 0;
        int ans = 1e6, ansl = -1;

        while(l<=r && r < s.size()) {
            if(tmap.count(s[r])) {
                wmap[s[r]]++;
                if(wmap[s[r]] == tmap[s[r]]) valid++;
                while(valid == tmap.size()) {
                    if(r-l+1 < ans) {
                        ans = r-l+1;
                        ansl = l;
                    }
                    if(tmap.count(s[l])) {
                        if(wmap[s[l]] == tmap[s[l]]) valid--;
                        wmap[s[l]]--;
                    }
                    l++;
                }
            }
            ++r;
        }
        if(ans == 1e6) return "";
        return s.substr(ansl, ans);
    }

private:
    std::unordered_map<char, int> wmap;  // map inside the sliding window, counting the letters
    std::unordered_map<char, int> tmap;  // map counting the t's letters
};

#if 0
int main() {
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC") << std::endl;
    cout << s.minWindow("a", "a") << std::endl;
    cout << s.minWindow("a", "aa") << std::endl;
    cout << s.minWindow("a", "b") << std::endl;
    cout << s.minWindow("ab", "b") << std::endl;   // "b"
    cout << s.minWindow("abc", "b") << std::endl;  // "b"
    return 0;
}
#endif