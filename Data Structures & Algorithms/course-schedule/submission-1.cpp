class Solution {
private:
    enum State {
        WHITE = 0,  // 尚未訪問
        GRAY = 1,   // 正在 DFS 路徑中
        BLACK = 2   // DFS 已完成
    };

    vector<int> state;

    // 這是 row size 是 numCourses 的數量。
    vector<vector<int>> adj;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        state.assign(numCourses, WHITE);
        adj.assign(numCourses, {}); 

        // 處理一下 adjList
        for(auto p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }
        // adj[0] = {1, 2}, adj[1] = {3}, adj[2] = {} 
        // [1,0] == 0 -> 1 代表 0 對 1 有依賴性, adj[0] = {1}

        // DFS
        for(int i=0 ; i<numCourses ; ++i)
        {
            if(state[i] == WHITE)
            {
                if(find_cycle_dfs(i))
                    return false;
            }
        }
        return true;
    }

    bool find_cycle_dfs(int node)
    {
        state[node] = GRAY;
        
        for(auto adj_node : adj[node])
        {
            if(state[adj_node] == WHITE)
            {
                if(find_cycle_dfs(adj_node))
                    return true;
            }
               
            else if(state[adj_node] == GRAY)
                return true;
        }

        state[node] = BLACK;
        return false;
    }
};
// 這題是在算 Directed Graph 判斷是否有 cycle => DFS 來做就好了
// 也就是檢查 Directed Graph 是不是 DAG (Acyclic)