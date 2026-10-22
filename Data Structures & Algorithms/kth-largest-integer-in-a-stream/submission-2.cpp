class KthLargest {
private:

    priority_queue<int, vector<int>, greater<>> minHeap;
    int num_k;

public:
    KthLargest(int k, vector<int>& nums) {
        num_k = k;

        for(int num : nums)
        {
            minHeap.push(num); // 這個 heap 大小是 k+1

            if(minHeap.size() > num_k)
                minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val); // 這個 heap 大小是 k+1

        if(minHeap.size() > num_k)
            minHeap.pop();

        return minHeap.top();
    }
};