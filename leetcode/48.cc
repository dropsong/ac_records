// https://leetcode.cn/problems/rotate-image/description/
// 先沿着主对角线翻转，再沿着竖直中轴线翻转

#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cout;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = i; j < matrix[0].size(); ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size()/2; ++j) {
                std::swap(matrix[i][j], matrix[i][matrix.size()-j-1]);
            }
        }
    }
};


#if 0
int main()
{
    Solution s;
    // test case...
    return 0;
}
#endif