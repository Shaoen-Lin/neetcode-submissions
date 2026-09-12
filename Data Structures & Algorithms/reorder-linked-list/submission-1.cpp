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

// 這題分成幾個步驟
// 1. 切一半 (一定會是前半多，後半少，不然就一樣)
// 2. reverse 後半段
// 3. 兩串相接

class Solution {
private:

    ListNode* fast;
    ListNode* slow;

    ListNode* l1;
    ListNode* l2;

    ListNode* prev;
    ListNode* curr;
    ListNode* nextptr;

    ListNode* ans_head;
    ListNode* ans_curr;

public:
    void reorderList(ListNode* head) {
        if(head == nullptr)
        {
            return;
        }
        else
        {
            // Find Middle

            fast = head;
            slow = head;

            while(fast->next != nullptr && fast->next->next != nullptr )
            {
                slow = slow->next;
                fast = fast->next->next;
            } // 停下來那刻就是會停在中心點

            l1 = head;
            l2 = slow->next;

            slow->next = nullptr;
            // fast->next = nullptr; // 注意這裡很重要因為 fast->next 還有可能是有值

            // Reverse 

            // 千萬不能先給他個 dummy 之後再把 dummy 調成 nullptr 這樣 prev 不會跟者變動 => 見筆記
            prev = nullptr;
            curr = l2;

            while(curr != nullptr)
            {
                nextptr = curr->next;
                curr->next = prev;

                prev = curr;
                curr = nextptr;
            }

            // dummy = nullptr;
            l2 = prev;

            // Combine
            
            ans_curr = l1;
            l1 = l1->next;
            // ans_head = ans_curr;

            bool flag = 1;
            while(l1 != nullptr || l2 != nullptr) 
            {
                if(flag == 0)
                {
                    ans_curr->next = l1;
                    l1 = l1 -> next;
                    flag = 1;
                }
                else 
                {
                    ans_curr->next = l2;
                    l2 = l2 -> next;
                    flag = 0;
                }

                ans_curr = ans_curr->next;
            }

            // head = ans_head;
            // 根本就不用 ans_head 因為 head 是 copy by value 所以他的記憶體位置都不會變 
            // 原本的第一個 node 也是 後來的第一個 node
        }
    }
};
