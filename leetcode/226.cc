// https://leetcode.cn/problems/invert-binary-tree/description/
// 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

#include <iostream>
// #define DEBUG

using std::cout;


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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};


#ifdef DEBUG
int main()
{
    Solution s;
    // construct an example if you wish...
    return 0;
}
#endif
