class Solution {
private:
    vector<vector<int>>adj;
    vector<bool>visited;
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        // 初始化 adj_list
        adj.assign(n, {}); 
        for(int i=0 ; i<edges.size() ; ++i)
        {
            vector<int> edge = edges[i];

            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            // 兩行都要加因為不加入會變成有向圖
            // 導致:
            //  0 <- 1 -> 2
            // 導致跑到 0 就結束了 
        }

        // 初始化 visited
        visited.assign(n, false);

        if(isConnected(n) && edges.size() == n-1 )
            return true;
        return false;
    }

    bool isConnected(int n)
    {
        // 假設第0個點跑進來
        visited[0] = true;
        dfs(0);

        for(int i=0 ; i<n ; ++i)
        {
            if(visited[i] == false)
                return false;
        }
        return true;
    }

    void dfs(int node)
    {
        // visited[node] = true;

        for(auto adj_node : adj[node])
        {
            if(visited[adj_node] != true)
            {
                visited[adj_node] = true;
                dfs(adj_node);
            }
                // dfs(adj_node);
        }
    }
};
// Tree ⇔ connected && E = V - 1
// connected ⇔ DFS 其中一點看是不是所有點都是 visited
