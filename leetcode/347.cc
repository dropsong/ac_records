// https://leetcode.cn/problems/top-k-frequent-elements/description/

#include <vector>
#include <cstdio>
#include <queue>
#include <unordered_map>
using std::vector;
using std::priority_queue;
using std::unordered_map;

struct node {
    int val;
    int cnt;
    bool operator < (const node& rhs) const {
        return cnt > rhs.cnt;
    }
};

class Solution_dummy {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(const auto& num : nums) {
            map[num]++;
        }
        for(const auto& e : map) {
            if(qwq.size() < k) {
                qwq.push(node{e.first, e.second});
                continue;
            }
            // qwq.size() == k
            if(e.second > qwq.top().cnt) {   // 当前频次大于堆顶，才入堆
                qwq.pop();
                qwq.push(node{e.first, e.second});
            }
        }
        vector<int> ans;
        while(!qwq.empty()) {
            node front = qwq.top(); 
            ans.push_back(front.val);
            qwq.pop();
        }
        return ans;
    }

private:
    priority_queue<node> qwq;   // 小根堆
    unordered_map<int, int> map;
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for(const auto& num : nums) {
            map[num]++;
        }
        for(const auto& e : map) {
            qwq.push(node{e.first, e.second});
            if(qwq.size() > k) qwq.pop();
        }
        vector<int> ans;
        while(!qwq.empty()) {
            node front = qwq.top(); 
            ans.push_back(front.val);
            qwq.pop();
        }
        return ans;
    }

private:
    priority_queue<node> qwq;
    unordered_map<int, int> map;
};

#if 0
int main()
{
    // test case
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution sol;
    vector<int> ans = sol.topKFrequent(nums, k);
    for(const auto& e : ans) {
        printf("%d ", e);
    }  // expected output: 1 2
    return 0;
}
#endif