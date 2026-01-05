// https://leetcode.cn/problems/palindrome-linked-list/description/
// 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

#include <iostream>
#include <vector>
// #define DEBUG

using std::cout;
using std::vector;
 

#ifdef DEBUG
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif
 

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        while(head != nullptr) {
            qwq.push_back(head->val);
            head = head->next;
        }
        int p = 0, q = qwq.size()-1;
        do {
            if(qwq[p] != qwq[q]) return false;
            p++; q--;
        } while(p < q);
        return true;
    }

private:
    vector<int> qwq;
};


#ifdef DEBUG
int main()
{
    Solution s;
    // construct an example if you wish...
    return 0;
}
#endif
