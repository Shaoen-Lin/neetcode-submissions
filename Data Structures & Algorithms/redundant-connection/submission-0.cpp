class Solution {
private:
    vector<int> parent; // Disjoint set 本人就是在記錄 parent 

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        // Initialization
        parent.resize(n + 1);
        // 一開始每個 node 都是自己的 root
        for(int i = 1; i <= n; ++i)
        {
            parent[i] = i;
        }

        // 一個edge 一個edge 去做 unite
        for(auto& edge : edges)
        {
            int x = edge[0];
            int y = edge[1];

            if(!unite(x, y))
            {
                return {x, y};
            }
        }
        return {};
    }

    // find 就是找到這個 root 的 Function
    int find(int x)
    {
        if(parent[x] == x)
            return x;

        // path compression
        parent[x] = find(parent[x]);
        // 而不是單獨做
        // find(parent[x]);

        return parent[x];
    }

    bool unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if(rootX == rootY)
            return false;

        parent[rootY] = rootX;

        return true;
    }
};