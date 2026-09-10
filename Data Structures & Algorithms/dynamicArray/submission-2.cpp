#include <bits/stdc++.h>

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

    void resize() {
        // 法三 memcpy 
        max *= 2;
        int* new_arr = (int*)malloc(sizeof(int) * max);

        // 直接複製 size 個整數的位元組大小 (新的開頭指標, 舊的開頭指標, 複製大小的東西過去)
        memcpy(new_arr, arr, sizeof(int) * size);

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
