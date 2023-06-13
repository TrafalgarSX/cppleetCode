/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

#include "ListNode.h"
#include <iostream>

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
    ListNode* deleteDuplicates(ListNode* head) {
        // return deleteDuplicates_solution(head);
        return deleteDuplicates_fs(head);
    }

    ListNode* deleteDuplicates_solution(ListNode* head){
        if(head == nullptr){
            return head;
        }
        ListNode *cur = head;
        while(cur->next != nullptr){
            if(cur->val == cur->next->val){
                cur->next = cur->next->next;
            }else{
                cur = cur->next;
            }
        }

        return head;
    }



    ListNode* deleteDuplicates_fs(ListNode* head){
        if(head == nullptr){
            return head;
        }
        ListNode *dummy = new ListNode(-1, head);
        ListNode *fast, *slow;
        fast = head->next;
        slow = head;

        while(fast != nullptr){
            if(fast->val == slow->val){
                fast = fast->next;
            }else{
                slow->next = fast;
                slow = fast;
                fast = fast->next;
            }
        }
        slow->next = fast;
        return dummy->next;
    }
};
// @lc code=end

