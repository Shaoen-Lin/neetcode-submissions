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
    bool hasCycle(ListNode* head) {

        // 宣告一個存節點指標的 Hash Set
        std::unordered_set<ListNode*> visited;

        while(head != nullptr)
        {
            // 檢查某個節點有沒有走過
            if (visited.count(head)) {
                return true;
            }

            // 把節點放進去 (注意，我寫 head 是指放進節點的指標)
            visited.insert(head);

            head = head->next;
        }

        return false;
    }
};
