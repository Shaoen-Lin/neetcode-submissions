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
    ListNode* prev;
    ListNode* curr;
    ListNode* tmp;

public:
    ListNode* reverseList(ListNode* head) {
        
        if(head != nullptr)
        {
            prev = head;
            curr = head->next; // 注意，這步驟要 head != null
            
            prev->next = nullptr;

            while(curr != nullptr)
            {
                tmp = curr->next;
                curr->next = prev;

                prev = curr;
                curr = tmp;                
            }

            return prev;
        }
        else 
            return head;
    }
};
