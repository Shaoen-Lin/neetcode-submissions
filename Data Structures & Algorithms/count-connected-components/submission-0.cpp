class Solution {
private:
    vector<bool> visited;
    vector<vector<int>> adj;
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        adj.assign(n, {});
        for(int i=0; i<edges.size() ; ++i)
        {
            vector<int> edge = edges[i];
            int x = edge[0];
            int y = edge[1];

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        visited.assign(n,false);

        int cnt=0;
        for(int i=0; i<n ; ++i)
        {
            if(visited[i]==false)
            {
                dfs(i);
                cnt++;
            }
        }
        return cnt;
    }

    void dfs(int node)
    {
        visited[node] = true;

        for(auto adj_node : adj[node])
        {
            if(visited[adj_node] == false)
                dfs(adj_node);
        }
    }
};
// DFS 算 Connected Components
