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

    Node* tmp1;
    Node* tmp2;
    Node* tmp3;
    Node* tmp4;
    Node* tmp5;
public:
    Node* copyRandomList(Node* head) {

        // 檢查是不是 0 個點
        if(head == nullptr)
        {
            return head; 
        }
        
        // head
        if(!mp.count(head))
        {
            new_head = new Node(head->val);
            mp[head] = new_head;
        }
            
        // next
        if(head->next == nullptr) // 是 null 
            tmp4 = nullptr;
        else if(!mp.count(head->next)) // 不是 null，但還沒建立
        {
            tmp4 = new Node(head->next->val);
            mp[head->next] = tmp4;
        }
        else                    // 不是 null，但已經建立
            tmp4 = mp[head->next];

        // random
        if(head->random == nullptr) // 是 null 
            tmp5 = nullptr;
        else if(!mp.count(head->random)) // 不是 null，但還沒建立
        {
            tmp5 = new Node(head->random->val);
            mp[head->random] = tmp5;
        }
        else                    // 不是 null，但已經建立
            tmp5 = mp[head->random];

        new_head->next = tmp4;
        new_head->random = tmp5;

        // 檢查是不是只有一個點
        head=head->next;
        new_curr = new_head->next;
        if(head == nullptr)
        {
            return new_head; 
        }

        // DFS traverse
        while(head != nullptr)
        {
            // next
            if(head->next == nullptr)
                tmp2 = nullptr;
            else if(!mp.count(head->next))
            {
                tmp2 = new Node(head->next->val);
                mp[head->next] = tmp2;
            }
            else 
                tmp2 = mp[head->next];

            // random
            if(head->random == nullptr)
                tmp3 = nullptr;
            else if(!mp.count(head->random))
            {
                tmp3 = new Node(head->random->val);
                mp[head->random] = tmp3;
            }
            else 
                tmp3 = mp[head->random];

            
            new_curr->next = tmp2;
            new_curr->random = tmp3;

            head = head->next;
            new_curr = new_curr->next;   
        }
        
        return new_head;
    }
};
