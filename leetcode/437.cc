// https://leetcode.cn/problems/path-sum-iii/description/

// #define DEBUG
#include <iostream>
#include <vector>
#include <unordered_map>

#ifdef DEBUG
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

class Solution_dummy {
public:
    int pathSum(TreeNode* root, long targetSum) {
        target = targetSum;
        ans = 0;
        std::vector<TreeNode*> path;
        work(root, path);
        return ans;
    }

private:
    long target, ans = 0;

    void work(TreeNode* x, std::vector<TreeNode*>& path) {
        if(!x) return;

        path.push_back(x);
        long curSum = 0;
        for(auto it = path.rbegin(); it != path.rend(); ++it) {
            curSum += (*it)->val;
            if(curSum == target) ans++;
        }

        work(x->left, path);
        work(x->right, path);
        path.pop_back();
    }
};

// 思路类似： https://github.com/dropsong/ac_records/blob/master/leetcode/560.cc
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        prefix_sum_count[0] = 1;
        return dfs(root, 0, targetSum);
    }

private:
    std::unordered_map<long, int> prefix_sum_count;

    int dfs(TreeNode* x, long cur_sum, int target) {
        if(!x) return 0;

        cur_sum += x->val;
        int count = 0;

        if(prefix_sum_count.count(cur_sum - target)) {
            count += prefix_sum_count[cur_sum - target];
        }

        prefix_sum_count[cur_sum]++;
        count += dfs(x->left, cur_sum, target);
        count += dfs(x->right, cur_sum, target);
        prefix_sum_count[cur_sum]--;

        return count;
    }
};

#ifdef DEBUG
int main()
{
    // test case: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    int targetSum = 8;

    Solution s;
    std::cout << s.pathSum(root, targetSum) << std::endl;

    return 0;
}
#endif