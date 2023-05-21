/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

#include "include/ListNode.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 快慢指针, leetcode中c/c++代码不释放空间
    // 栈的思路也很有意思， 相当于把链表逆转了，不过要依赖一个栈
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast, *slow, *dummy, *temp;
        dummy = new ListNode(-1, head);
        fast = slow = dummy;
        int count = 0;
        while(fast->next != nullptr){
            if(count != n){
                count++;
            }else{
                slow = slow->next;
            }
            fast = fast->next;
        }
        // temp = slow->next;
        slow->next = slow->next->next;
        // delete temp;
        return dummy->next;
    }
};
// @lc code=end

