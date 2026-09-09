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

class LinkedList {

private: 
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }  

    int get(int index) {

        if(index >= size)
        {
            return -1;
        }
        else 
        {
            Node* tmp = head;
            for(int i=0 ; i<index ; ++i) // 第一步不用走在上面 少走一步
            {
                tmp = tmp->next;
            }

            return tmp->value;
        }
    }

    void insertHead(int val) {
        Node* tmp = new Node(val);

        tmp->next = head;
        head = tmp;

        size++;

        if(size == 1)
            tail = tmp;
    }
    
    void insertTail(int val) {
        Node* tmp = new Node(val);

        // 不能這樣寫 因為有可能一開始就敲 insert tail 導致 tail 為空的
        // tail->next = tmp;

        // 注意 接的前面不能是 nullptr，但接的人的可以，因為上面是 ok 的
        if(tail == nullptr) // 代表 size == 0
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }

        size++;
    }

    // 這解法還是需要去判斷刪尾巴的問題 所以要改一種 if else  特別討了頭和尾
    // bool remove(int index) {

    //     // 注意，remove 
    //         // 1. 想到 ”刪開頭“ 要特別處理。
    //         // 2. 想到 “剩一個節點的問題” 刪掉就沒有的問題 => 只會發生在刪頭的時候，因為刪其他地方會需要跑回圈所以肯定不會刪掉剩一個
    //     if(index >= size)
    //     {
    //         return false;
    //     }
    //     else 
    //     {
    //         Node* prev = nullptr;
    //         Node* tmp = head;

    //         if(index == 0)
    //         {
    //             if(size == 1)
    //             {
    //                 head = nullptr;
    //                 tail = nullptr;
    //             }
    //             else
    //             {
    //                 head = tmp->next;
    //             }
    //         }
    //         else 
    //         {
    //             for(int i=1 ; i<=index ; ++i)
    //             {
    //                 prev = tmp;
    //                 tmp = tmp->next;
    //             }

    //             prev->next = tmp->next;
    //         }

    //         free(tmp);
    //         size--;

    //         return true;
    //     }
    // }

    bool remove(int index) {
        if (index < 0 || index >= size) {
            return false;
        }

        Node* tmp = head;

        // 情況 1：刪除頭節點 (index == 0)
        if (index == 0) {
            head = head->next;
            delete tmp;
            size--;

            // 如果刪完後串列變空了，tail 也要跟著清空
            if (size == 0) {
                tail = nullptr;
            }
            return true;
        }

        // 情況 2：刪除中間或尾端節點 (index > 0)
        Node* prev = nullptr;
        for (int i = 0; i < index; ++i) {
            prev = tmp;
            tmp = tmp->next;
        }

        prev->next = tmp->next;

        // 如果刪除的剛好是尾巴，把 tail 往前拉回 prev
        if (index == size - 1) {
            tail = prev;
        }

        delete tmp;
        size--;
        return true;
    }

    vector<int> getValues() {
        vector<int> ret;

        Node* tmp = head;
        
        // 背好這個 “走訪鏈結串列” 最標準的寫法
        while (tmp != nullptr) {
            ret.push_back(tmp->value);
            tmp = tmp->next;
        }

        // 這寫法會死，因為碰到空的回圈就死了
        // for(int i=0 ; i<size ; ++i)
        // {
        //     ret.push_back(tmp->value); 
        //     tmp = tmp->next;
        // }

        return ret;
    }
};
