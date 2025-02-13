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
        auto pre = dummy;
        auto cur = head;
        while(cur && cur->next) {
            auto temp = cur->next->next;
            pre->next = cur->next;
            cur->next->next = cur;
            cur->next = temp;

            pre = cur;
            cur = temp;
        }

        return dummy->next;
    }
};
// @lc code=end

