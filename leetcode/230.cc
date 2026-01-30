// https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/
// 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（k 从 1 开始计数）。

#include <iostream>
#include <queue>
// #define DEBUG

using std::cout;
using std::priority_queue;


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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        out_k = k; work(root);
        return qwq.top();
    }

private:
    void work(TreeNode* x) {
        if(!x) return;
        qwq.push(x->val);
        if(qwq.size() > out_k) qwq.pop();
        work(x->left);
        work(x->right);
    }

    int out_k;
    priority_queue<int> qwq;
};


#ifdef DEBUG
int main()
{
    // test case
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    int k = 2;
    Solution sol;
    cout << sol.kthSmallest(root, k) << '\n';
    return 0;
}
#endif