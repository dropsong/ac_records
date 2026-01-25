// https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/
// 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。

// #define DEBUG
#include <iostream>
#include <vector>

using std::cout;
using std::vector;


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


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid = nums.size() / 2;
        TreeNode* m_root = new TreeNode(nums[mid]);

        // left
        if (mid > 0) {
            vector<int> left_nums(nums.begin(), nums.begin() + mid);
            m_root->left = sortedArrayToBST(left_nums);
        }

        // right
        if (mid + 1 < nums.size()) {
            vector<int> right_nums(nums.begin() + mid + 1, nums.end());
            m_root->right = sortedArrayToBST(right_nums);
        }

        return m_root;
    }
};


#ifdef DEBUG
int main()
{
    Solution sol;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* bst_root = sol.sortedArrayToBST(nums);
    // ... 
    return 0;
}
#endif