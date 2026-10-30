/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    unordered_map<Node*,Node*> mp; // old -> new
    Node* new_head;
    Node* new_curr;

    Node* tmp2;
    Node* tmp3;

public:
    Node* copyRandomList(Node* head) {

        // 檢查是不是 0 個點
        if(head == nullptr)
        {
            return head; 
        }

        Node* curr = head;

        // DFS traverse
        while(curr != nullptr)
        {
            if(!mp.count(curr))
            {
                new_curr = new Node(curr->val);
                mp[curr] = new_curr;
            }
            else 
                new_curr = mp[curr];

            // next
            if(curr->next == nullptr)
                tmp2 = nullptr;
            else if(!mp.count(curr->next))
            {
                tmp2 = new Node(curr->next->val);
                mp[curr->next] = tmp2;
            }
            else 
                tmp2 = mp[curr->next];

            // random
            if(curr->random == nullptr)
                tmp3 = nullptr;
            else if(!mp.count(curr->random))
            {
                tmp3 = new Node(curr->random->val);
                mp[curr->random] = tmp3;
            }
            else 
                tmp3 = mp[curr->random];

            
            new_curr->next = tmp2;
            new_curr->random = tmp3;

            new_curr = new_curr->next;   
            curr = curr->next;
        }
        
        // 這樣就不用有 new_head 還要把 "第一個節點" 額外拿出來處裡了
        return mp[head];
    }
};
