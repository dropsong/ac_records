// // Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* ans = new ListNode();

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* p = ans;
        ListNode* pre = p;

        // 先处理都有的低位
        do{
            int tmp = l1->val + l2->val;

            // 注意顺序
            p->next = new ListNode((p->val+tmp)/10);
            p->val = (p->val + tmp) % 10;

            pre = p;
            p = p->next;
            l1 = l1->next; l2 = l2->next;
        }while(l1 != nullptr && l2 != nullptr);

        // 可能有一个链表比另一个长
        while(l1){
            p->next = new ListNode((p->val+l1->val)/10);
            p->val = (p->val + l1->val) %10;
            pre = p;
            p = p->next;
            l1 = l1->next;
        }

        while(l2){
            p->next = new ListNode((p->val+l2->val)/10);
            p->val = (p->val + l2->val) %10;
            pre = p;
            p = p->next;
            l2 = l2->next;
        }

        // 最后答案要把前导 0 删除
        if(p->val == 0)
        {
            pre->next = nullptr;
        }

        // 最后返回和的链表的头指针
        return ans;
    }
};

/*
# include <iostream>
# include <vector>
using std::vector;
using std::cout;
using std::endl;

// 辅助函数：根据 vector 构造链表
ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); i++){
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

// 辅助函数：打印链表
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // 构造测试数据
    vector<int> values1 = {9,9,9,9,9,9,9};
    vector<int> values2 = {9,9,9,9};
    ListNode* l1 = createList(values1);
    ListNode* l2 = createList(values2);
    
    // 调用解法
    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);
    
    // 输出结果
    printList(result);
    return 0;
}
*/