// https://leetcode.cn/problems/diameter-of-binary-tree/description/
// 给你一棵二叉树的根节点，返回该树的 直径 。

#include <iostream>
#include <unordered_map>
// #define DEBUG

using std::cout;
using std::unordered_map;


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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        subdep[nullptr] = 0;
        upd(root);
        return ans;
    }

private:
    int upd(TreeNode* x) {
        if(!x) return 0;
        subdep[x] = std::max(upd(x->left), upd(x->right)) + 1;
        ans = std::max(ans, subdep[x->left] + subdep[x->right]);
        return subdep[x];
    }

    int ans = 0;
    unordered_map<TreeNode*, int> subdep; // 该节点为根的子树的最大深度（包括自己）

};


#ifdef DEBUG
int main()
{
    Solution sol;
    // Test cases
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << sol.diameterOfBinaryTree(root) << "\n"; // Expected output: 3
    return 0;
}
#endif