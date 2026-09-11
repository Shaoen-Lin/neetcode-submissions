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
 
// 快慢指標做法 空間複雜度就可以是 O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // 只要兔子還能往前走兩步，就繼續跑
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          
            fast = fast->next->next;    

            // 兔子套圈追上烏龜了！
            if (slow == fast) {
                return true;
            }
        }

        // 兔子跑到了終點 (null)，代表是一條直線，沒有環
        return false;
    }
};
