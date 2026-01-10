// https://leetcode.cn/problems/merge-two-sorted-lists/description/
// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

#include <iostream>
// #define DEBUG

using std::cout;


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy; // 虚拟头节点
        ListNode* tail = &dummy; // 指向合并链表的尾部

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // 将剩余的节点接到合并链表后面
        tail->next = list1 ? list1 : list2;

        return dummy.next;
    }
};


#ifdef DEBUG
int main()
{
    Solution s;
    ListNode a3(4), a2(2, &a3), a1(1, &a2);
    ListNode b3(4), b2(3, &b3), b1(1, &b2);
    ListNode* test = s.mergeTwoLists(&a1, &b1);

    while(test) {
        cout << test->val << " ";
        test = test->next;
    }
    return 0;
}
#endif