// https://leetcode.cn/problems/validate-binary-search-tree/description/

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
    bool isValidBST(TreeNode* root) {
        if(!root) return false;

        bool flag1 = true, flag2 = true;
        if(root->left != nullptr) {
            if(Work(root->left) >= root->val) return false; // Work 返回子树最大值
            flag1 = isValidBST(root->left);
        }
        if(root->right != nullptr) {
            if(work(root->right) <= root->val) return false; // work 返回子树最小值
            flag2 = isValidBST(root->right);
        }

        return flag1 && flag2;
    }

private:
    int Work(TreeNode* x) {
        int ans = x->val;
        if(x->left) {
            ans = std::max(Work(x->left), ans);
        }
        if(x->right) {
            ans = std::max(Work(x->right), ans);
        }
        return ans;
    }
    int work(TreeNode* x) {
        int ans = x->val;
        if(x->left) {
            ans = std::min(work(x->left), ans);
        }
        if(x->right) {
            ans = std::min(work(x->right), ans);
        }
        return ans;
    }
};


#ifdef DEBUG
int main()
{
    // test case 1
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    Solution sol;
    cout << sol.isValidBST(root) << "\n";

    // test case 2
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    cout << sol.isValidBST(root2) << "\n";

    return 0;
}
#endif
