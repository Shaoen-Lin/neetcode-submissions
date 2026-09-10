class DynamicArray {

private:

    int size; // size
    int max; // capacity
    int* arr; // resizable array 重點如果一開始給他陣列就會導致不能擴充

public:

    // 建構子基本上都是在做初始化
    DynamicArray(int capacity) {
        max = capacity;
        size = 0;
        // arr = malloc(sizeof(int)); // 只能是 1 個 int 大小，但是如果今天傳進來的 capa 不是 1 的大小就完了
        arr = (int*)malloc(sizeof(int)*capacity);
        // 注意 malloc 一定要加上 （轉型） 因為他預設是 void*

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
        return arr[--size]; // 因為是 0~n-1 所以拿到減過的會剛好
    }

    // 法二 realloc 可以直接擴充原本的記憶體位置 => 最快 而且也不用 free
    void resize() {
        max *= 2;
        int* new_arr = (int*)realloc(arr, sizeof(int) * max);

        // arr = (int*)realloc(arr, new_size); 
        // 危險寫法！因為記憶體不足的話會 return null 導致 arr 原本的空間被洗掉

        // 內部行為有三種可能：
        //     1. 就地擴充(最快)：如果原本記憶體後方剛好有連續的空閒空間，作業系統/記憶體配置器會直接拉大該區塊。ptr 位址不變，資料不需要被搬移，花費 $O(1)$ 時間。
        //     2. 異地重配：如果後方空間不夠，它會在堆疊區（Heap）另尋一塊足夠大的新空間，自動幫你把舊資料 memcpy 過去，並自動 free 掉舊的 ptr，最後回傳新的記憶體位址。
        //     3. 配置失敗：空間不足時回傳 NULL，原區塊不變。

        arr = new_arr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return max;
    }
};
