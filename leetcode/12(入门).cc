// link: https://leetcode.cn/problems/integer-to-roman/description/
#include <cstdio>
#include <string>

using std::string;


class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        if(num > 999)
        {
            int qian = num / 1000;
            while(qian--) ans += "M";
        }
        if(num > 99)
        {
            int bai = (num % 1000) / 100;
            if(bai < 4)
            {
                while(bai--) ans += "C";
                goto AYAKA;
            }
            if(bai == 4)
            {
                ans += "CD";
                goto AYAKA;
            }
            if(bai > 4 && bai < 9)
            {
                ans += "D";
                bai -= 5;
                while(bai--) ans += "C";
                goto AYAKA;
            }
            if(bai == 9)
            {
                ans += "CM";
                goto AYAKA;
            }
        }
        AYAKA: {}
        if(num > 9)
        {
            int shi = (num % 100) / 10;
            if(shi < 4)
            {
                while(shi--) ans += "X";
                goto YOMIYA;
            }
            if(shi == 4)
            {
                ans += "XL";
                goto YOMIYA;
            }
            if(shi > 4 && shi < 9)
            {
                ans += "L";
                shi -= 5;
                while(shi--) ans += "X";
                goto YOMIYA;
            }
            if(shi == 9)
            {
                ans += "XC";
                goto YOMIYA;
            }
        }
        YOMIYA: {}
        int ge = num % 10;
        if(ge < 4) 
        {
            while(ge--) ans += "I";
            goto FURINA;
        }
        if(ge == 4)
        {
            ans += "IV";
            goto FURINA;
        }
        if(ge > 4 && ge < 9)
        {
            ans += "V";
            ge -= 5;
            while(ge--) ans += "I";
            goto FURINA;
        }
        if(ge == 9)
        {
            ans += "IX";
            goto FURINA;
        }
        FURINA: {}
        return ans;
    }
};


#if 0
int main()
{
    Solution s;
    int n; scanf("%d", &n);
    printf("%s\n", s.intToRoman(n).c_str());
    return 0;
}
#endif
