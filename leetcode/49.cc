// link: https://leetcode.cn/problems/group-anagrams/description/

#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int i = 0;
        for(auto& str : strs)
        {
            string repre = process(str);
            mmap[repre].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto j : mmap)
        {
            ans.push_back(mmap[j.first]);
        }
        return ans;
    }

private:
    string process(string& str)
    {
        int compo[26] = {0};
        for(int i = 0; i < str.size(); ++i)
        {
            compo[str[i]-'a'] ++;
        }
        string neo_str = "";
        for(int i = 0; i < 26; ++i)
        {
            while(compo[i])
            {
                neo_str += char('a'+i);
                compo[i] -= 1;
            }
        }
        return neo_str;
    }
    unordered_map<string, vector<string>> mmap;
};


#if 0
int main()
{
    Solution s;
    vector<string> test = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // vector<string> test = {""};
    // vector<string> test = {"a"};

    vector<vector<string>> toprint = s.groupAnagrams(test);
    for(auto i : toprint)
    {
        for(auto j : i)
        {
            printf("%s ", j.c_str());
        }
        printf("\n");
    }
    return 0;
}
#endif
