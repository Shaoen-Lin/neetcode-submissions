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

        ListNode* l1_curr = l1;
        ListNode* l2_curr = l2;

        ListNode* dummy = new ListNode(0);
        ListNode* ans_curr = dummy;

        int carry=0;
        // while(l1_curr != nullptr && l2_curr != nullptr) // 但是只這樣寫有可能兩串跑完了 但是 carry 還有值
        while(l1_curr != nullptr || l2_curr != nullptr || carry != 0)
        {
            // null 不能取 val 
            int sum = 0;
            if(l1_curr != nullptr)
                sum += l1_curr->val;
            if(l2_curr != nullptr)
                sum += l2_curr->val;
            sum += carry;

            carry = sum / 10;

            ListNode* tmp = new ListNode(sum%10);
            ans_curr->next = tmp;

            ans_curr = ans_curr->next;

            if(l1_curr != nullptr) // 走到 null 為止
                l1_curr = l1_curr->next;
            if(l2_curr != nullptr)
                l2_curr = l2_curr->next;
        }

        return dummy->next;
    }
};
