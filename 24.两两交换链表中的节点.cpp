/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *temp, *cur;
        cur = dummy;

        while(cur->next != nullptr && cur->next->next != nullptr){
            temp = cur->next;
            cur->next  = cur->next->next;
            temp->next = cur->next->next;
            cur->next->next = temp;
            cur = cur->next->next;
        }

        return dummy->next;
    }
};
// @lc code=end

