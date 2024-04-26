#include <iostream>
#include <vector>
#include <ListNode.h>

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l2;
        ListNode* temp = head;
        int carry = 0;
        int sum = 0;

        while(l1 != nullptr && l2 != nullptr){
            sum = l1->val + l2->val + carry;
            l2->val = sum % 10;
            carry = sum / 10;

            temp = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 != nullptr){
            l2 = l1;
        }
        temp->next = l2;

        while(l2 != nullptr){
            sum = l2->val + carry;
            l2->val = sum % 10;
            carry = sum / 10;

            temp = l2;
            l2 = l2->next;
        }

        if(carry > 0){
            temp->next = new ListNode(carry);
        }

        return head;
    }
};
// @lc code=end

int main()
{

    ListNode* first = ListNode::make_list({9,9,9,9,9,9,9}, true);
    ListNode* second = ListNode::make_list({9,9,9,9}, true);

    Solution solution;
    // ListNode* ret = solution.addTwoNumbers(first, second);
    ListNode* ret = solution.addTwoNumbers(second, first);
    ListNode::print_list(ret);

    return 0;
}

