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
    
public:
    void reorderList(ListNode* head) {

        if(head == nullptr || head->next == nullptr)
            return;
        
        // Step 1
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* right = slow->next;
        slow->next = nullptr;
        ListNode* left = head;

        // Step 2
        ListNode* prev = nullptr;
        ListNode* curr = right;
        while(curr != nullptr)
        {
            ListNode* nextn = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextn;
        }
        right = prev;

        // Step 3
        left = left->next; // 因為第一點必定是 head 在 left 中
        curr = head;
        int flag = 1;
        while(left && right)
        {
            if(flag == 1)
            {
                curr->next = right;
                curr = curr->next;
                right = right->next;
                flag = 0;
            }
            else 
            {
                curr->next = left;
                curr = curr->next;
                left = left->next;
                flag = 1;
            }
        }

        if(left)
            curr->next = left;
        else if(right)
            curr->next = right;
    }
};

// fast & slow 
// reverse 
// reorder

// 1 2 3 N