// https://leetcode.cn/problems/intersection-of-two-linked-lists/description/
// 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null

#include <iostream>
#include <unordered_set>
// #define DEBUG

using std::unordered_set;
using std::cout;


#ifdef DEBUG
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode* p = nullptr) : val(x), next(p) {}
};
#endif


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA) { mySet.insert(headA); headA =  headA->next; }
        while (headB) {
            if(mySet.count(headB)) return headB;
            headB = headB->next;
        }
        return nullptr;
    }

private:
    std::unordered_set<ListNode*> mySet;
};


#ifdef DEBUG
int main()
{
    Solution s;
    ListNode c3(1); ListNode c2(2, &c3); ListNode c1(9, &c2);
    ListNode a2(4, &c1); ListNode a1(5, &a2);
    ListNode b3(3, &c1); ListNode b2(4, &b3); ListNode b1(2, &b2);
    if(s.getIntersectionNode(&b1, &a1) == nullptr) cout << "nullptr\n";
    else cout << s.getIntersectionNode(&b1, &a1)->val;
    return 0;
}
#endif
