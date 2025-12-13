// link: https://leetcode.cn/problems/palindrome-number/
#include <cstdio>
#include <list>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        while(x)
        {
            lis.push_back(x%10);
            x /= 10;
        }
        auto p1 = lis.begin();
        std::list<int>::reverse_iterator p2 = lis.rbegin();

        int cnt1 = 0;
        while(cnt1 < lis.size()/2)
        {
            if(*p1 != *p2) return false;
            cnt1++; p1++; p2++;
        }
        return true;
    }

private:
    std::list<int> lis;
};


#if 0
int main()
{
    Solution s; int n;
    scanf("%d", &n);

    if(s.isPalindrome(n)) printf("yes.\n");
    else printf("no.\n");

    return 0;
}
#endif
