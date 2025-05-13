// link: https://www.acwing.com/problem/content/description/5021/
// author: https://github.com/dropsong
// 逻辑运算转化为集合运算

/*
NON_ZERO_DIGIT =  "1" / "2" / "3" / "4" / 
                  "5" / "6" / "7" / "8" / "9"
DIGIT          =  "0" / NON_ZERO_DIGIT
NUMBER         =  NON_ZERO_DIGIT / (NON_ZERO_DIGIT DIGIT*)
ATTRIBUTE      =  NUMBER
VALUE          =  NUMBER
OPERATOR       =  ":" / "~"
BASE_EXPR      =  ATTRIBUTE OPERATOR VALUE
LOGIC          =  "&" / "|"
EXPR           =  BASE_EXPR / (LOGIC "(" EXPR ")" "(" EXPR ")")

EASY_EXPR      =  BASE_EXPR / 
                  (LOGIC "(" BASE_EXPR ")" "(" BASE_EXPR ")")
*/

#include <algorithm>
#include <string>
#include <unordered_map>
#include <bitset>
#include <iostream>
#include <vector>

using std::string;
using std::unordered_map;
using std::bitset;
using std::cin;
using std::vector;

unordered_map<int, unordered_map<int, bitset<2505>>> mp;  // key -> (value -> users)
unordered_map<int, bitset<2505>> all_specific_usrs;       // 这个 key 的所有用户
int q[2505]; // user_id


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


bitset<2505> work(string s)
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
        bitset<2505> v1 = work(sub_s1);

        string sub_s2 = s.substr(firstClose+1, s.size() - firstClose - 1);
        bitset<2505> v2 = work(sub_s2);

        bitset<2505> tmpAns;

        if(s[0] == '&')
            tmpAns = v1 & v2;

        else if(s[0] == '|')
            tmpAns = v1 | v2;

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

        if(op == ':') return mp[key][value];
        else if(op == '~') // 取补集
        {
            bitset users_with_kv = mp[key][value];
            bitset users_with_k = all_specific_usrs[key];
            return (~users_with_kv) & users_with_k;
        }
    }

    return {};
}


int main()
{
    int n; scanf("%d", &n);
    for(int i = 1; i <=n; ++i)
    {
        int tmp_cnt;
        scanf("%d%d", &q[i], &tmp_cnt);
        while(tmp_cnt--)
        {
            int k, v;
            scanf("%d%d", &k, &v);
            mp[k][v].set(i);
            all_specific_usrs[k].set(i);
        }
    }

    int m; scanf("%d", &m);
    while(m--)
    {
        string s; cin >> s;
        bitset<2505> ans = work(s);
        vector<int> sorted_ans;

        for(int i = 1; i <= n; ++i)
            if(ans[i]) sorted_ans.push_back(q[i]);

        sort(sorted_ans.begin(), sorted_ans.end());

        for(int i = 0; i < sorted_ans.size(); ++i)
        {
            printf("%d ", sorted_ans[i]);
        }
        printf("\n");
    }

    return 0;
}

/*  正确
8
1 2 1 2 2 3
2 2 1 2 3 1
3 1 1 3
4 3 1 2 2 3 3 1
5 2 2 3 3 2
6 2 1 3 3 1
7 1 2 3
8 2 1 2 3 2
6
1:2
1 2 4 8 
1~2
3 6 
&(1:2)(3:1)
2 4 
|(1~2)(2:3)
1 3 4 5 6 7 
&(|(1:2)(3:1))(1:2)
1 2 4 8 
&(1:2)(&(3:1)(|(1~2)(3:2)))

*/