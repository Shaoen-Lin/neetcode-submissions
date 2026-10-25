class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> min_Heap;

        for(int num : nums)
        {
            min_Heap.push(num);

            if(min_Heap.size() > k)
            {
                min_Heap.pop();
            }
        }
        return min_Heap.top();
    }
};
