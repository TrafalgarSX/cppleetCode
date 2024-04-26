#pragma once

 #include <vector>
 #include <iostream>
 #include <array>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}

    static ListNode* make_list(const std::vector<int> &nums){
        ListNode dummy;
        ListNode* temp = &dummy;

        for(const auto& num : nums){
            temp->next = new ListNode(num);
            temp = temp->next;
        }

        temp = dummy.next;

        return dummy.next;
    }

    static ListNode* make_list(const std::vector<int> &nums, bool flag){
        ListNode** head = nullptr;
        ListNode** temp = head;

        for(const auto& num : nums){
            *temp = new ListNode(num);
            temp = &((*temp)->next);
        }

        return *head;
    }

    static void print_list(ListNode* head){
        while(head != nullptr){
            std::cout << head->val << "," << std::endl;
            head = head->next;
        }
    }
 };


