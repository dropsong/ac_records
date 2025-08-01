// link: https://leetcode.cn/problems/zigzag-conversion/

#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::vector;


class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.size() <= numRows) return s;

        vector<string> rows(numRows);
        int current_row = 0, dir = -1;
        for(char c : s)
        {
            rows[current_row] += c;
            if(current_row == 0 || current_row == numRows-1)
            {
                dir *= -1;
            }
            current_row += dir;
        }

        string ans_str = "";
        for(const string& row_str : rows) {
            ans_str += row_str;
        }

        return ans_str;
    }
};


#if 0
int main()
{
    Solution S;
    cout << S.convert("PAYPALISHIRING", 4);
    return 0;
}
#endif
