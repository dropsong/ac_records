// link: https://www.luogu.com.cn/problem/P1563
// github: https://github.com/dropsong

#include <iostream>
#include <string>

// (7+1)%7 = 1, (1-1+7)%7, (1-2+7)%7 

int n, m;
std::string names[100005];  // 从 1 开始存储
bool face2[100005];         // 0: 内 1: 外

int main()
{
    std::cin >> n >> m;
    for(int i=1; i <= n; ++i)
    {
        bool tmp; std::cin >> tmp;
        face2[i] = tmp;
        std::string name; std::cin >> name;
        names[i] = name;
    }

    int pos = 1;
    for(int i = 1; i <= m; ++i)
    {
        int a, s;
        std::cin >> a >> s;
        // 内面：左数，-；右数，+
        // 外面：左数，+；右数，-
        if(face2[pos])  // 外面
        {
            if(a == 0) pos = (pos + s ) % n;  // 左数
            else pos = (pos - s + n) % n;             // 右数
            if(pos == 0) pos = n;  // 保证pos在1~n之间
        }
        else  // 内面
        {
            if(a == 0) pos = (pos - s + n) % n;  // 左数
            else pos = (pos + s ) % n;             // 右数
            if(pos == 0) pos = n;  // 保证pos在1~n之间
        }
        // std::cout << pos << std::endl;
    }

    std::cout << names[pos];
    return 0;
}