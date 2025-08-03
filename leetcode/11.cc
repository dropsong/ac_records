// link: https://leetcode.cn/problems/container-with-most-water/

#include <iostream>
#include <vector>

using std::cout;
using std::vector;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = 0;
        while(l < r) {
            int tmp = std::min(height[l], height[r]) * (r-l);
            ans = std::max(ans, tmp);
            if(height[l] < height[r]) l++;
            else r--;
        }
        return ans;
    }
};


#if 0
int main()
{
    Solution S;
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    cout << S.maxArea(v);
    return 0;
}
#endif
