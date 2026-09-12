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

    ListNode* dummy;
    ListNode* fast;
    ListNode* slow;

// 詳細資訊可以看 leetcode
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        dummy = new ListNode(0);
        dummy->next = head;

        fast = dummy;
        slow = dummy;

        for(int i=0 ; i<n ; ++i)
        {
            fast = fast->next;
        }

        while(fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // 移除 slow->next
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};
