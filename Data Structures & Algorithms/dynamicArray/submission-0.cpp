class DynamicArray {

private:

    int size; // size
    int max; // capacity
    int* arr; // resizable array

public:

    // 建構子基本上都是在做初始化
    DynamicArray(int capacity) {
        max = capacity;
        size = 0;
        // arr = malloc(sizeof(int)); // 只能是 1 個 int 大小，但是如果今天傳進來的 capa 不是 1 的大小就完了
        arr = (int*)malloc(sizeof(int)*capacity);

    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    // 重點！這是為什麼能夠自動偵測 resize
    void pushback(int n) {

        // 調整機制
        if(size == max)
        {
            resize();
        }

        // pushback 邏輯
        arr[size] = n;

        size++;
    }

    int popback() {
        return arr[--size];
    }

    void resize() {
        
        max *= 2;
        int* new_arr = (int*)malloc(sizeof(int) * max); 

        // 注意 這裡只需要做到 size 因為題目要求是 陣列 中間沒有空格
        for(int i=0 ; i<size ; ++i)
        {
            new_arr[i] = arr[i]; 
        }

        // 注意！賦予指標的時候千萬要注意 記憶體洩漏 的問題
        free(arr);
        
        arr = new_arr;
        
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return max;
    }
};
