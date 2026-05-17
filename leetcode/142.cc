// https://leetcode.cn/problems/linked-list-cycle-ii/description/
// 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null

#include <unordered_map>
// #define DEBUG

using std::unordered_map;

#ifdef DEBUG
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
#endif

class Solution_dummy {   // 最朴素的想法，用一个哈希表判断有没有来过
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        unordered_map<ListNode*, bool> vis;
        while(head != nullptr) {
            if(vis[head]) return head;
            vis[head] = true;
            head = head->next;
            if(head == nullptr) return nullptr;
        }
        return nullptr;
    }
};

class Solution { // 快慢指针
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode *fast = head, *slow = head, *ans = head;
        do {
            fast = fast->next;
            if(fast == nullptr) return nullptr;
            fast = fast->next;
            if(fast == nullptr) return nullptr;
            slow = slow->next;
        } while(fast != slow);

        while(slow != ans) {
            slow = slow->next;
            ans = ans->next;
        }
        return ans;
    }
};

#ifdef DEBUG
int main() {
    // test case...
    return 0;
}
#endif