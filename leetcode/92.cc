// link: https://leetcode.cn/problems/reverse-linked-list-ii/description/
// 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
// 解析见同目录下图片

#include <iostream>
#define DEBUG

using std::cout;


#ifdef DEBUG
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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr) return nullptr;
        if(left == right) return head;

        int pos = 1;  bool flag = false;
        ListNode tmp(0, head);
        if(left == 1) {   // 转化问题
            head = &tmp;
            pos = 0; flag = true;
        }

        ListNode* ans = head;
        ListNode* pioneer = head->next;
        ListNode* pre = nullptr;  // head 的前一个 
        ListNode  *mid_tail, *third_head;

        while(true) {
            if(pos == left) {
                mid_tail = head;
            }

            pre = head;
            head = pioneer;
            pioneer = pioneer->next;
            pos++;

            if(pos == right) {
                head->next = nullptr;
                third_head = pioneer;
                break;
            }
        }
        ans->next = reverseList(mid_tail);
        mid_tail->next = third_head;

        if(flag) return ans->next;  // 转化问题
        return ans;
    }
};


#ifdef DEBUG
int main()
{
    ListNode qwq5(5);
    ListNode qwq4(4, &qwq5);
    ListNode qwq3(3, &qwq4);
    ListNode qwq2(2, &qwq3);
    // ListNode qwq2(5);
    ListNode qwq1(1, &qwq2);

    Solution S;
    ListNode *p = S.reverseBetween(&qwq1, 3, 4);
    // ListNode* p = S.reverseList(&qwq1);
    while(p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}
#endif
