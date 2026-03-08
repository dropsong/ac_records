// https://leetcode.cn/problems/reverse-nodes-in-k-group/description/

#include <iostream>
#include <utility>
// #define DEBUG

using std::pair;


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
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            // 这里是 C++17 的写法，也可以写成
            // pair<ListNode*, ListNode*> result = myReverse(head, tail);
            // head = result.first;
            // tail = result.second;
            std::tie(head, tail) = myReverse(head, tail);
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};


#ifdef DEBUG
int  main()
{
    ListNode qwq5(5);
    ListNode qwq4(4, &qwq5);
    ListNode qwq3(3, &qwq4);
    ListNode qwq2(2, &qwq3);
    ListNode qwq1(1, &qwq2);

    Solution S;
    ListNode *p = S.reverseKGroup(&qwq1, 2);
    while(p)
    {
        std::cout << p->val << " ";
        p = p->next;
    }
    return 0;
    return 0;
}
#endif
