// https://www.luogu.com.cn/problem/P1015
// 一个 N（2≤N≤10 或 N=16）进制数 M（100 位之内），求最少经过几步可以得到回文数。

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int n; std::string m;

inline int convert2int(char x) {
    if('a' <= x && x <= 'z') return (x-'a')+10;
    if('A' <= x && x <= 'Z') return (x-'A')+10;
    if('0' <= x && x <= '9') return (x-'0');
}

char convert2char(int x) {
    if(0 <= x && x <= 9) return char('0'+x);
    if(10 <= x && x <= 15) return char('a'+x-10);
}

string reverse(string x) {
    string tmp = "";
    for(int i = x.size()-1; i >= 0; --i) {
        tmp += x[i];
    }
    return tmp;
}

string add(string a) {
    string b = reverse(a);
    string r_result = "";
    int pre = 0;
    for(int i = a.size()-1; i >= 0; --i) {
        int ab = convert2int(a[i]) + convert2int(b[i]);
        r_result += convert2char((pre+ab) % n);
        pre = (pre + ab) / n;    // pre will not exceed 1
    }
    if(pre) r_result += '1';
    return r_result;
}

bool check(string x) {
    for(int i = 0; i < x.size()/2; ++i) {
        if(x[i] != x[x.size()-i-1]) return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= 30; ++i) {
        m = add(m);
        if(check(m)) {
            cout << "STEP=" << i;
            return 0;
        }
    }

    cout << "Impossible!";
    return 0;
}