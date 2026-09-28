/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(node == nullptr)
            return node;
        
        unordered_map<Node*, Node*>mp; // 紀錄 “舊的” 對應到 “新的”
        queue<Node*> q; // 放的都是 "舊的 node"

        Node* first_node = new Node(node->val);
        mp[node] = first_node;
        q.push(node);
        while(!q.empty())
        {   
            Node* old = q.front();
            q.pop();
            // 因為跑到那點之前，那點的 new node 必定在之前就放好了，所以不用建新點。

            // 接下來要看連線
            for(Node* n: old->neighbors)
            {
                // 去看有沒有建立對應就知道新點建了沒
                if(mp.find(n) == mp.end()) 
                {
                    // Node* new_neighbor = new Node(n->val);
                    mp[n] = new Node(n->val);
                    q.push(n);
                }
                mp[old]->neighbors.push_back(mp[n]);
            }
        }
        return first_node;
    }
};
// BFS 來走完整張圖



