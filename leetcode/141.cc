// https://leetcode.cn/problems/linked-list-cycle/description/

#include <iostream>
// #define DEBUG

using std::cout;


#ifdef DEBUG
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        while(head != nullptr)
        {
            if(head->val == 114514) return true;
            head->val = 114514; // 丑陋做法，把这个标记当成 vis，脏了原数据
            head = head->next;
        }
        return false;
    }
};


#ifdef DEBUG
int main()
{
    Solution s;
    // construct an example, if you wish...
    return 0;
}
#endif
