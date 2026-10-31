class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v)
    {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

// Front 當作 MRU，Tail 當作 LRU 
class LRUCache {
private:
    int capa;
    unordered_map<int, Node*> mp;

    // 頭尾都補 Dummy Node 就不會有太多問題
    Node* dummy_head; 
    Node* dummy_tail;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nextt = node->next;

        prev->next = nextt;
        nextt->prev = prev;
    }

    void insertToFront(Node* node) {
        Node* first = dummy_head->next;

        // node 
        node->next = first;
        node->prev = dummy_head;

        // head
        dummy_head->next = node;

        // first 
        first->prev = node;
    }

    void removeLRU()
    {
        Node* tail = dummy_tail->prev;
        // Node* prev_tail = tail->prev;

        // prev_tail->next = dummy_tail;
        // dummy_tail->prev = prev_tail;

        remove(tail);

        mp.erase(tail->key); // 這就是為什麼 Node Structure 需要有個 key 
        delete(tail);
    }


public:
    LRUCache(int capacity) {
        capa = capacity;

        dummy_head = new Node(0, 0);
        dummy_tail = new Node(0, 0);

        // 初始化 dummy 指標，但不要兩個 prec 都
        dummy_head->next = dummy_tail;
        // dummy_head->prev = dummy_tail;

        dummy_tail->prev = dummy_head;
        // dummy_tail->prev = dummy_head;
    }
    
    int get(int key) {

        if(!mp.count(key))
            return -1; // 找不到
        
        Node* node = mp[key];
        remove(node); // 先把點移掉
        insertToFront(node); // 新增一點到最前面去
        return node->val;
    }
    
    void put(int key, int value) {
        
        if(mp.count(key)) // 已有這格 index
        {
            Node* node = mp[key];
            node->val = value;

            remove(node);
            insertToFront(node);
        }
        else // 沒有這個 index
        {
            if(mp.size() >= capa) // 先砍掉一個 LRU
            {
                removeLRU();
            }

            Node* node = new Node(key, value);
            mp[key] = node;
            insertToFront(node); // 新增一點到最前面去
        }
    }
};
