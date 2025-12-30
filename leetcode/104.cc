// https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
// 给定一个二叉树 root ，返回其最大深度。

#include <iostream>
#include <algorithm>
// #define DEBUG

using std::cout;


#ifdef DEBUG
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return std::max(maxDepth(root->left) , maxDepth(root->right)) + 1;
    }
};


#ifdef DEBUG
int main()
{
    Solution s;
    TreeNode a(15); TreeNode b(7); TreeNode c(20, &a, &b);
    TreeNode d(9); TreeNode e(3, &d, &c);
    cout << s.maxDepth(&e);
    return 0;
}
#endif
