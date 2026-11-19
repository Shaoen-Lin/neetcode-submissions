class Solution {
private:
    vector<vector<pair<int,int>>> adjlist;
    vector<int> dis;
    vector<bool> visited;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;    

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();

        // 跑所有點的連線來初始化 adjlist 
        adjlist.resize(n+1);
        for(int i=0; i<n ; ++i)
        {
            for(int j=i+1; j<n ; ++j)
            {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            
                adjlist[i].push_back({j, distance});
                adjlist[j].push_back({i, distance});
            }
        }

        // 初始化 dis & visited
        dis.resize(n, INT_MAX);
        dis[0] = 0; // 設第一點為起點。
        visited.resize(n, false);

        // 初始化 pq
        pq.push({0,0});
        
        int total=0;

        // Prim's Algorithm
        while(!pq.empty())
        {
            auto [distance, u] = pq.top();
            pq.pop();

            // 已經加入 MST，不需重複處理
            if(visited[u])
                continue;

            visited[u] = true;
            total += distance;

            for(auto [v, weight] : adjlist[u])
            {
                if(!visited[v])
                    relax(v, weight);
            }
        }

        return total;
    }


    // 注意 Prim's 的 relax 不需要使用到 dis[u]，他要比較的是現在到我的距離，和
    bool relax(int v, int distance)
    {
        if(dis[v] > distance)
        {
            dis[v] = distance;
            
            pq.push({distance, v});

            return true;
        }

        return false;
    }
};
