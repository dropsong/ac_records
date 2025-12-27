// https://leetcode.cn/problems/trapping-rain-water/
// 接雨水，2D
// 注意到，由于输入方式的限制，不会出现如下形状的水：
// 
//       w
//     w w w
//   w w w w w 
//
// 下面的水要么和上面一样多，要么更少
// 转换为搜索找出口问题，水可以向左右流动，如果另一格子是水的话也可以流动，如果是墙就不行
// 转换为两边的墙向内水平填充

#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::cout;


class Solution {
public:
    int trap(vector<int>& height) {
        for(int i = 0; i < height.size(); ++i)
        {
            if(height[i] > max_height)
            {
                max_height = height[i];
                max_pos = i;
            }
            blacks += height[i];
        }
        for(int i = 0; i < height.size(); ++i)
        {
            if(i == max_pos) break;
            blanks += max_height - std::max(pre_height, height[i]);
            pre_height = std::max(pre_height, height[i]);
        }
        for(int i = height.size()-1; i >= 0; --i)
        {
            if(i == max_pos) break;
            blanks += max_height - std::max(pre_height2, height[i]);
            pre_height2 = std::max(pre_height2, height[i]);
        }
        return max_height * height.size() - blanks - blacks;
    }

private: 
    int max_height = -1;
    int max_pos = -1;
    int pre_height = 0, pre_height2 = 0;
    int blanks = 0, blacks = 0;
};


#if 0
int main()
{
    Solution s;
    // vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> vec = {4,2,0,3,2,5};
    cout << s.trap(vec);
    return 0;
}
#endif
