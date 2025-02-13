/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    MyLinkedList() {
        dummy = new ListNode(-1);
        size = 0;
    }
    
    int get(int index) {
        if(index >= size || index < 0) {
            return -1;
        }
        auto cur = dummy;
        for(int i = 0; i <= index; ++i) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        dummy->next = new ListNode(val, dummy->next);
        ++size;
    }
    
    void addAtTail(int val) {
        auto pre = dummy;
        while(pre->next != nullptr) {
            pre = pre->next;
        }
        pre->next = new ListNode(val);
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) {
            return;
        }
        auto pre = dummy;
        for(int i = 0; i < index; ++i) {
            pre = pre->next;
        }
        pre->next = new ListNode(val, pre->next);
        ++size;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size || index < 0) {
            return;
        }
        auto pre = dummy;
        for(int i = 0; i < index; ++i) {
            pre = pre->next;
        }
        auto tmp = pre->next;
        pre->next = pre->next->next;
        --size;
        delete tmp;
        tmp = nullptr;
    }
private:
    struct ListNode {
        int val = 0;
        ListNode* next = nullptr;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
    ListNode* dummy = nullptr;
    int size = 0;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

