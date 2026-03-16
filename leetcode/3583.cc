// https://leetcode.cn/problems/count-special-triplets/description/

#include <iostream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::vector;


class Solution2 {  // 1100 / 1121 个通过的测试用例
public:
    int specialTriplets(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i]%2) continue;
            for(int j = i+1; j < nums.size(); ++j) {
                if(2*nums[j] != nums[i]) continue;
                for(int k = j+1; k < nums.size(); ++k) {
                    if(nums[k] == nums[i]) {
                        ans++;
                        ans %= 1000000007;
                    }
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        if(nums.size() < 3) return 0;

        std::unordered_map<int, int> r_hash, l_hash;
        for(int i = 2; i < nums.size(); ++i) {
            r_hash[nums[i]]++;
        }   l_hash[nums[0]]++;

        int cnt = 0;
        for(int i = 1; i < nums.size()-1; ++i) {
            int wanted = 2*nums[i];
            cnt += (l_hash[wanted] * 1LL * r_hash[wanted] % 1000000007);
            cnt %= 1000000007;
            l_hash[nums[i]]++;
            r_hash[nums[i+1]]--;
        }
        return cnt % 1000000007;
    }
};


#if 0
int main()
{
    Solution s;
    // vector<int> nums{0, 1, 0, 0};
    vector<int> nums{8, 4, 2, 8, 4};
    cout << s.specialTriplets(nums) << "\n";
    return 0;
}
#endif