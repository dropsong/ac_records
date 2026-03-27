// https://leetcode.cn/problems/search-a-2d-matrix/description/
// 一般而论，左闭右开二分查找一个升序序列，若未找到，l 会停在第一个大于 target 的位置上

#include <vector>
#include <iostream>
using std::vector;
using std::cout;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size();
        while(l < r) {
            int mid = (l+r) / 2;
            if(matrix[mid][0] == target) return true;
            if(matrix[mid][0] < target) {l = mid+1;}
            if(matrix[mid][0] > target) {r = mid;}
        }
        if(l-1<0) return false;   // shouldn't reach?
        int ll = 0, rr = matrix[0].size();
        while(ll < rr) {
            int mid = (ll + rr) / 2;
            if(matrix[l-1][mid] == target) return true;
            if(matrix[l-1][mid] < target) {ll = mid+1;}
            if(matrix[l-1][mid] > target) {rr = mid;}
        }
        return false;
    }
};

#if 0
int main()
{
    // test case...
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    Solution sol;
    cout << sol.searchMatrix(matrix, target) << "\n";  // expected output: true
    return 0;
}
#endif