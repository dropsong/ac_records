// https://leetcode.cn/problems/min-stack/description

#include <algorithm>

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack {
public:
    MinStack():head(nullptr) {}
    
    void push(int val) {
        if(!head) {
            head = new Node(val, val);
        } else {
            head = new Node(val, std::min(head->min_val, val), head); 
        }
    }
    
    void pop() {
        auto cur = head;
        head = head->next;
        delete(cur);
        cur = nullptr;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min_val;
    }

private:
    class Node {
    public:
        int val;    // 当前节点的值
        int min_val;
        Node* next;
        Node(int x, int y, Node* next = nullptr):val(x), min_val(y), next(next) {}
    };
    Node* head;
};

#if 0
int main()
{
    // test case
    return 0;
}
#endif