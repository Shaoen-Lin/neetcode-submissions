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

private:
    ListNode* ans_curr = new ListNode(); // 預設第一個節點為 0
    ListNode* ans_head;

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ans_head = ans_curr;

        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
            {
                ans_curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                ans_curr->next = list2;
                list2 = list2->next;
            }

            ans_curr = ans_curr ->next;
        }

        if(list1 != nullptr)
        {
            ans_curr->next = list1;
        }
        else
        {
            ans_curr->next = list2;
        }

        return ans_head->next;
    }
};
