// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
// 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

#include <vector>
#include <unordered_map>
// #define DEBUG
using std::vector;
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size()) return nullptr;
        for(int i = 0; i < inorder.size(); ++i) {
            pos[inorder[i]] = i;
        }
        return work(preorder, 0, preorder.size()-1,
                    inorder, 0, inorder.size()-1);
    }

private:
    // 在逻辑上，我们考虑 preorder 和 inorder 的子集
    TreeNode* work(vector<int>&pre, int pl, int pr,
                   vector<int>&in, int il, int ir) {
        if(pl > pr || il > ir) return nullptr;

        TreeNode* root = new TreeNode(pre[pl]);
        int k = pos[pre[pl]];
        int leftSize = k-il;  // 相对于中序遍历的位置

        root->left = work(pre, pl+1, pl+leftSize,
                          in, il, il+leftSize-1);
        root->right = work(pre, pl+leftSize+1, pr,
                           in, il+leftSize+1, ir);
        return root;
    }

    unordered_map<int, int> pos;
};

#ifdef DEBUG
int main()
{
    // test case
    return 0;
}
#endif