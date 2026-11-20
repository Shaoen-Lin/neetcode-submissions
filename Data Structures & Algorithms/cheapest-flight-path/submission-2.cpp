class Solution {
private:
    vector<int> dist;   // 每輪給 "改" 的
    vector<int> tmp_dist; // 每輪給 "看" 的
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        dist.resize(n, INT_MAX/4); // 節點編號為 0 ~ n-1
        dist[src] = 0;

        // k+1 輪的 relax
        for(int i=0; i<k+1 ; ++i)
        {
            tmp_dist = dist; // 關鍵：備份上一輪的距離狀態每次看這個，但不改這個。

            bool update = false;
            for(auto flight : flights)
            {
                int u = flight[0];
                int v = flight[1];
                int weight = flight[2];

                if(relax(u, v, weight))
                    update = true;
            }

            if(!update)
                break;
        }

        //不檢查負環了

        return (dist[dst]==INT_MAX/4) ? -1 : dist[dst];
    }

    // 為了 update 才改用 bool 
    bool relax(int u, int v, int weight)
    {
        if(dist[v] > tmp_dist[u] + weight)
        {
            dist[v] = tmp_dist[u] + weight; // 注意！這裡是 tmp_dist
            return true;
        }
        return false;
    }
};

// 去看 HackMD 筆記