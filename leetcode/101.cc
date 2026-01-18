// https://leetcode.cn/problems/symmetric-tree/description/
// 给你一个二叉树的根节点 root ， 检查它是否轴对称。
// 左的右的左 == 右的左的右

#include <iostream>
#include <string>
#include <unordered_map>
// #define DEBUG

using std::cout;
using std::string;
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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        work(root, "");
        for(auto i : lookup) {
            if(lookup.count(get_inverse(i.first)) == 0) return false;
            if(i.second != lookup[get_inverse(i.first)]) return false;
        }
        return true;
    }

private: 
    void work(TreeNode* x, string s) {
        if(x == nullptr) return;
        lookup[s] = x->val;
        work(x->left, s+"1"); work(x->right, s+"0");
    }

    string get_inverse(string s) {
        for(auto& c : s) c = c=='1'?'0':'1';
        return s;
    }

    unordered_map<string, int> lookup;
};


#ifdef DEBUG
int main()
{
    Solution s;
    /*
    TreeNode a1(3), a2(4), a3(4), a4(3);
    TreeNode b1(2, &a1, &a2), b2(2, &a3, &a4);
    TreeNode c1(1, &b1, &b2);
    cout << s.isSymmetric(&c1);
    */

    /*
    TreeNode a1(3), a2(3);
    TreeNode b1(2, nullptr, &a1), b2(2, nullptr, &a2);
    TreeNode c1(1, &b1, &b2);
    cout << s.isSymmetric(&c1);
    */

    TreeNode a1(0), b1(1, &a1, nullptr);
    cout << s.isSymmetric(&b1);

    return 0;
}
#endif