// link: https://www.luogu.com.cn/problem/P3741
// github: https://github.com/dropsong

#include <string>
#include <iostream>

int main()
{
    int n; std::cin >> n; // 没用

    std::string s;
    std::cin >> s;

    // 先统计 VK 的个数，然后统计非 VK 的地方有没有连续两个以上的位置（且必须是 VV 或者 KK）
    int cnt = 0;
    bool flag = false;
    for(auto it = s.begin(); it != s.end(); ++it)
    {
        if(*it == 'V' && (it + 1) != s.end() && *(it + 1) == 'K')
        {
            cnt++;
            it++; // 跳过 K
            continue;
        }
        if(flag) continue;
        if((*it == 'V' && (it + 1) != s.end() && *(it + 1) == 'V') || 
           (*it == 'K' && (it + 1) != s.end() && *(it + 1) == 'K'))
        {
            flag = true;
            if(*it == 'V' && *(it+1)== 'V' && *(it+2)== 'K') flag = false; // 特例不算
        }
    }

    if(flag) cnt++;
    std::cout << cnt;

    return 0;
}
