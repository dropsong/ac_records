// link: https://leetcode.cn/problems/longest-consecutive-sequence/description/

#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using std::vector;
using std::cout;
using std::unordered_set;
using std::unordered_map;


class USet {
public:
    USet() = default;

    void add(int x)
    {
        _uset[x] = x;
        _flagsize[x] = 1;
    }

    int find(int x)
    {
        if (x != _uset[x]) _uset[x] = find(_uset[x]);
        return _uset[x];
    }

    int get_size(int x)
    {
        x = find(x);
        return _flagsize[x];
    }

    void union_set(int x, int y)
    {
        x = find(x);
        y = find(y);
        if(x == y) return;
        _uset[x] = y;
        _flagsize[y] += _flagsize[x];
    }

private:
    std::unordered_map<int, int> _uset;
    std::unordered_map<int, int> _flagsize;// 仅维护代表节点的 size, 非代表节点的 size 可以不准确
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        for(int num : nums)
        {
            if(check_map.find(num) != check_map.end()) continue; // 这个数之前读过
            _myUset.add(num);
            check_map.insert(num);

            if(check_map.find(num-1) != check_map.end()) _myUset.union_set(num-1, num);
            if(check_map.find(num+1) != check_map.end()) _myUset.union_set(num+1, num);

            ans = std::max(ans, _myUset.get_size(num));
        }
        return ans;
    }

private:
    USet _myUset;
    unordered_set<int> check_map;
};


#if 0
int main()
{
    Solution s;
    // vector<int> input = {100, 4, 200, 1, 3, 2};
    // vector<int> input = {0,3,7,2,5,8,4,6,0,1};
    // vector<int> input = {1,2,0,1};
    // vector<int> input = {0, -1};
    vector<int> input = {1, 0, 1, 2};
    cout << s.longestConsecutive(input);
    return 0;
}
#endif
