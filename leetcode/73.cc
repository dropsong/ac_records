// https://leetcode.cn/problems/set-matrix-zeroes/description/
// 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

#include <vector>

using std::vector;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool has_zero0 = false, has_zero1 = false;

        for(int j = 0; j < n; ++j) if(!matrix[0][j]) has_zero0 = true;
        for(int i = 0; i < m; ++i) if(!matrix[i][0]) has_zero1 = true;

        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                if(!matrix[i][j])
                    matrix[0][j] = 0, matrix[i][0] = 0;

        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                if(!matrix[0][j] || !matrix[i][0]) matrix[i][j] = 0;

        if(has_zero0) for(int j = 0; j < n; ++j) matrix[0][j] = 0;
        if(has_zero1) for(int i = 0; i < m; ++i) matrix[i][0] = 0;
    }
};


#if 0
int main()
{
    Solution s;
    // construct a sample, 暇なら、どうぞ
    return 0;
}
#endif
