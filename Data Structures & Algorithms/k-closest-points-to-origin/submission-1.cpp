class Solution {
private:
    priority_queue<pair<double, vector<int>>> max_heap;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> ans;

        for(vector<int> point : points)
        {
            double tmp = sqrt(point[0]*point[0] + point[1]*point[1]);
            max_heap.push({tmp, point});

            if(max_heap.size() > k)
            {
                max_heap.pop();
            }
        }

        while(!max_heap.empty())
        {
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
        
        return ans;
    }
};

// 要 return 第幾小的題目必定是 pq 題目 -> 不可能用 array 達成。
// 要第 k 小 => 做一個 size 為 k 的 max heap 的 top 就是第 k 小

// 雖然說可以用 heap 大小是 k 可以讓 space 變成 O(k)
// 但還是會需要 O(n) space 來幫助我們回傳座標 -> 就是用 Hash map 解。

// 但其實解答需要 O(k) 的 space 我們就必須要把座標一起傳進去 pq 裡面一起排序就可以不用額外對應了