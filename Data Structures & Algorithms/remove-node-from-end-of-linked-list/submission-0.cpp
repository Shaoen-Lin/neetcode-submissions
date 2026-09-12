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
    ListNode* curr;
    ListNode* prev;
    ListNode* nextn;

    ListNode* dummy;

    int size;
    int num; // 順序數過去要砍掉第幾個

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        curr = head;
        size = 0;
        while(curr != nullptr)
        {
            size++;
            curr = curr->next;      
        }

        // 考慮到 head 刪除的問題 => dummy node 解決 && 不會有沒有 node 的情型

        num = size - n;

        dummy = new ListNode();
        dummy->next = head;

        prev = dummy;
        curr = head;
        nextn = curr->next;

        for(int i=0 ; i<num ; ++i)
        {
            prev = curr;
            curr = nextn;
            nextn = curr->next;
        }
        prev->next = nextn;

        return dummy->next;
    }
};
