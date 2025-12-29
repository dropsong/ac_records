// https://leetcode.cn/problems/binary-tree-inorder-traversal/description/

#include <iostream>
#include <vector>
// #define DEBUG

using std::cout;
using std::vector;


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
    vector<int> inorderTraversal(TreeNode* root) {
        work(root);
        return ans;
    }

private:
    void work(TreeNode* root) {
        if(!root) return;
        work(root->left);
        ans.push_back(root->val);
        work(root->right);
    }

    vector<int> ans;
};


#ifdef DEBUG
int main()
{
    Solution s;
    TreeNode a(3);
    TreeNode b(2, &a, nullptr);
    TreeNode c(1, nullptr, &b);
    vector<int> output = s.inorderTraversal(&c);
    // vector<int> output = s.inorderTraversal(&a);
    for(auto e : output) { cout << e;}
    return 0;
}
#endif
