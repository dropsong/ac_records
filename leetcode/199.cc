// https://leetcode.cn/problems/binary-tree-right-side-view/description/
// 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

#include <vector>
#include <queue>
#include <unordered_map>
// #define DEBUG
using std::vector;
using std::queue;
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

// bfs, find the last node within a layer
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        queue<TreeNode*> qwq; vector<int> ans;
        unordered_map<TreeNode*, int> depth;
        qwq.push(root); depth[root] = 1;
        int prepopdepth = 1; TreeNode* pre = root;

        while(!qwq.empty()) {
            TreeNode* x = qwq.front(); qwq.pop();
            if(depth[x] > prepopdepth) { ans.push_back(pre->val); }
            prepopdepth = depth[x]; pre = x;

            if(x->left) {
                qwq.push(x->left); depth[x->left] = depth[x]+1;
            }
            if(x->right) {
                qwq.push(x->right); depth[x->right] = depth[x]+1;
            }
        }
        ans.push_back(pre->val);

        return ans;
    }
};

#ifdef DEBUG
int main()
{
    return 0;
}
#endif