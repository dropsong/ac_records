// not done

// link: https://www.acwing.com/problem/content/description/5021/
// author: https://github.com/dropsong
// 逻辑运算转化为集合运算

#include <algorithm>
#include <iterator>
#include <string>
#include <map>
#include <set>
#include <iostream>

using std::string;
using std::map;
using std::set;
using std::cin;

map<int, map<int, set<int>>> mp;  // key -> (value -> users)
map<int, set<int>> all_specific_usrs; // 这个 key 的所有用户


int findClosing(const string &s, int start)
{
    int cnt = 0;
    for (int i = start; i < s.size(); i++) {
        if (s[i] == '(') cnt++;
        else if (s[i] == ')') cnt--;
        if (cnt == 0) return i;
    }
    return -1; // 找不到匹配的右括号，错误
}


set<int> work(string s)
{
    if(s.empty()) return {};

    // 遇到(),对()内的内容 work，返回一个 set
    if(s[0] == '(' && s[s.size() - 1] == ')')
    {
        string sub_s = s.substr(1, s.size() - 2);
        return work(sub_s);
    }

    // 遇到 & 或 |，后面必然跟着两个()，对()内的内容 work，返回两个 set，作集合运算
    if(s[0] == '&' || s[0] == '|')
    {
        int firstClose = findClosing(s, 1);
        string sub_s1 = s.substr(1, firstClose+1-1);
        set<int> v1 = work(sub_s1);

        string sub_s2 = s.substr(firstClose+1, findClosing(s, firstClose+1)+1 -firstClose-1);
        set<int> v2 = work(sub_s2);

        set<int> tmpAns;

        if(s[0] == '&')
            std::set_intersection(v1.begin(), v1.end(),
                                  v2.begin(), v2.end(),
                                  std::inserter(tmpAns, tmpAns.begin()));

        if(s[0] == '|')
            std::set_union(v1.begin(), v1.end(),
                           v2.begin(), v2.end(),
                           std::inserter(tmpAns, tmpAns.begin()));

        return tmpAns;
    }

    // 原子表达式，格式为以下两者之一：
    // <key>:<value>
    // <key>~<value>
    size_t pos = s.find_first_of("~:"); // 取出 key
    if(pos != std::string::npos){
        int key = std::stoi(s.substr(0, pos));
        char op = s[pos];
        int value = std::stoi(s.substr(pos + 1));

        auto it = mp.find(key);
        // it->second  这是 map: value->users

        if(op == ':') return it->second[value];
        else if(op == '~') // 取补集
        {
            auto tmp = it->second[value];
            // 取 tmp 在 all_specific_usrs[key] 中的补集
            set<int> complement;
            std::set_difference(all_specific_usrs[key].begin(), all_specific_usrs[key].end(),
                                tmp.begin(), tmp.end(),
                                std::inserter(complement, complement.begin()));
            return complement;
        }
    }

    return {};
}


int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(0);

    int n; cin >> n;
    for(int i = 1; i <=n; ++i)
    {
        int usr, tmp_cnt;
        // scanf("%d%d", &usr, &tmp_cnt);
        cin >> usr >> tmp_cnt;
        while(tmp_cnt--)
        {
            int k, v;
            // scanf("%d%d", &k, &v);
            cin >> k >> v;
            mp[k][v].insert(usr);
            all_specific_usrs[k].insert(usr);
        }
    }

    int m; cin >> m;
    while(m--)
    {
        string s; cin >> s;
        set<int> ans = work(s);

        for(auto& i : ans)
            std::cout << i << " ";
        std::cout << "\n";
    }

    return 0;
}