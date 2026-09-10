struct Node{
    int value;
    Node* next;

    // 最標準直觀的建構子寫法 注意！！沒有給 tmp = head 就需要改成 new Node()
    Node(int v) {
        value = v;
        next = nullptr;
    }
};
// struct 和 class 基本上是一樣的，只是 struct 沒有支援 private


// dummy => head => ... => tail 的版本就可以少掉 remove 頭要特別寫的問題
class LinkedList {

private: 
    Node* dummy; // 這裡就不宣告 head 了
    Node* tail;
    int size;

public:
    LinkedList() {
        size = 0;
        dummy = new Node(0); // 注意一開始 dummy 就要被建出來了
        tail = dummy; // 一開始 tail = dummy 後
    }  

    int get(int index) {

        if(index >= size)
        {
            return -1;
        }
        else 
        {
            Node* tmp = dummy;
            for(int i=0 ; i<=index ; ++i) 
            {
                tmp = tmp->next;
            }

            return tmp->value;
        }
    }

    void insertHead(int val) {
        // 如果是空的話 不會有影響 => 不會 不用 if else 寫了
        Node* tmp = new Node(val);

        tmp->next = dummy->next;
        dummy->next = tmp;

        size++;

        if(size == 1)
            tail = tmp;
    }
    
    void insertTail(int val) {
        Node* tmp = new Node(val);

        // 不會碰到空的問題 不用 if else 了
        
        tail->next = tmp;
        tail = tmp;

        size++;
    }

    bool remove(int index) {

        // 題目要求
        if (index < 0 || index >= size) {
            return false;
        }
    
        // dummy node 不會有刪除頭的問題(因為是 dummy)，所以不用怕
        // 要刪的節點從 head 出發 
        Node* tmp = dummy->next;
        Node* prev = dummy;

        for (int i = 0; i < index; ++i) {
            prev = tmp;
            tmp = tmp->next;
        }

        prev->next = tmp->next;

        // 如果刪除的剛好是尾巴，因為多設計了 tail 指標，所以要比平常多把 tail 往前拉回 prev
        if (index == size - 1) {
            tail = prev;
        }

        delete tmp;
        size--;
        return true;
    }

    vector<int> getValues() {
        vector<int> ret;

        Node* tmp =dummy->next;
        
        // 背好這個 “走訪鏈結串列” 最標準的寫法
        while (tmp != nullptr) {
            ret.push_back(tmp->value);
            tmp = tmp->next;
        }

        return ret;
    }
};

// link list 在插入跟刪除都要想到幾個點
//  1. 插入 時是 空的串列 情況 /  刪除 時是 空的串列 情況 => 核心問題是：接的前面不能是 nullptr，但接的人的可以
//  2. remove 時頭尾的問題 => 用 dummy node 解決頭的問題 但 尾巴的問題一樣不能解決
//  3. 提醒：走訪全部的寫法可以用 tmp = head && while(tmp != nullptr) 來寫
