class Solution {
private:
    enum State {
        White,
        Gray,
        Black
    };

    vector<vector<int>> adj;
    vector<int> state;
    vector<int> ans;

    bool dfs(int cur)
    {
        state[cur] = Gray;

        for(int next : adj[cur])
        {
            if(state[next] == Gray)
                return false;   // cycle

            if(state[next] == White)
            {
                if(!dfs(next))
                    return false;
            }
        }

        state[cur] = Black;

        // cur 的所有後續課程都處理完了
        ans.push_back(cur);

        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        adj.assign(numCourses, {});
        state.assign(numCourses, White);

        for(auto& p : prerequisites)
        {
            int course = p[0];
            int pre = p[1];

            adj[pre].push_back(course);
        }

        for(int i = 0; i < numCourses; ++i)
        {
            if(state[i] == White)
            {
                if(!dfs(i))
                    return {};
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};