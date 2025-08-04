// link: https://leetcode.cn/problems/reverse-linked-list/
// 反转链表

#include <iostream>

using std::cout;


/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode* pioneer = head->next;
        ListNode* pre = nullptr;  // head 的前一个 

        while(true) {
            head->next = pre;
            pre = head;
            head = pioneer;
            if(head == nullptr) break;
            pioneer = pioneer->next;
        }
        return pre;
    }
};


#if 0
int main()
{
    Solution S;
    cout << "懒得搞了";
    return 0;
}
#endif
