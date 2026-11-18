class Solution {
private:
    vector<vector<pair<int,int>>> adjlist;
    // 格式是 adjlist[u1] = {[v1, w1], [v2, w2]} 
    //       adjlist[u2] = {[v1, w1], [v2, w2]} 

    int d[101]; // d[n] 紀錄從 root 要抵達 n 時，需要多長的距離。

    // 初始化 pq => 元素是 <距離, node編號> 才可以用 pq 排距離
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq; 

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // 建立 Adjacency List
        adjlist.resize(n + 1);

        // 處理矩陣 times
        for(auto time: times)
        {
            int u = time[0];
            int v = time[1];
            int w = time[2];

            // 因為這步驟會 access adjlist 所以必須要在上面給他 resize
            adjlist[u].push_back({v,w}); 
        }

        // 初始化 d[i]
        for(int i=0 ; i<=n ; ++i) // 1 對到 node 1, 2 對到 node 2 ...
            d[i] = INT_MAX / 4; // 因為後面要加 dis 導致我們如果用 INT_MAX 就會 overflow 
        d[k] = 0;

        pq.push({0, k});
        while(!pq.empty())
        {
            auto min_dis = pq.top();
            pq.pop();
            int u = min_dis.second;

            // 省略比較長的去檢查 relax  
            if(min_dis.first > d[u])
                continue;

            for(auto adjnode : adjlist[u]) // u 可以到的每個點
            {
                int v = adjnode.first;
                int distance = adjnode.second;
                relax(u, v, distance);
            }
        }

        // 回傳 d[i] 最大值即為距離 root 的最遠距離
        int ret=-1;
        for(int i=1 ; i<=n ; ++i) 
        {
            if(d[i] == INT_MAX/4)
                return -1;

            ret = max(ret, d[i]);
        }
        return ret;
    }

    void relax(int u, int v, int distance)
    {
        if(d[v] > d[u] + distance)
        {
            d[v] = d[u] + distance;

            // 注意！每動距離還要去更新 pq 裡面的值
            // 只是不刪除原本 pq 中的 {d[v], v} 裡面可能就會多一個 {d[v], v} 但不影響
            // 因為必定會先跑的 relax 完的而不是比較長的那個 + 然後比較長的必定不會 relax 到
            // 所以上面擺了一段加速
            pq.push({d[v], v});
        }
    }
};

// 因為這題要找最短路徑
// 1. Single Source 
// 2. 沒有 negative edge 
// => Dijkstra Algo
// Time: O(VlogV + E), if 用 Fibnacci heap 實作
