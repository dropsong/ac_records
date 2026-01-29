// https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
// #define DEBUG

using std::cout;
using std::vector;
using std::queue;
using std::unordered_map;


#ifdef DEBUG
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif


// resize(n) 分配内存并创建对象，将 size 和 capacity 都设为 n。
// 适用于需要直接使用下标访问或默认填充数据的情况。
class Solution {
public:
    // one layer in one vector
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return ans;
        ans.resize(1);
        qwq.push(root); ans[0].push_back(root->val); dep[root] = 0;
        while(!qwq.empty()) {
            TreeNode* a = qwq.front(); qwq.pop();
            TreeNode *l = a->left, *r = a->right;
            if(l) {
                dep[l] = dep[a] + 1;
                if(ans.size() <= dep[l]) ans.resize(dep[l] + 1);
                ans[dep[l]].push_back(l->val);
                qwq.push(l);
            }
            if(r) {
                dep[r] = dep[a] + 1;
                if(ans.size() <= dep[r]) ans.resize(dep[r] + 1);
                ans[dep[r]].push_back(r->val);
                qwq.push(r);
            }
        }
        return ans;
    }

private: 
    queue<TreeNode*> qwq;
    vector<vector<int>> ans;
    unordered_map<TreeNode*, int> dep;
};


#ifdef DEBUG
int main()
{
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>> res = s.levelOrder(root);
    for (const auto& layer : res) {
        for (int val : layer) {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}
#endif