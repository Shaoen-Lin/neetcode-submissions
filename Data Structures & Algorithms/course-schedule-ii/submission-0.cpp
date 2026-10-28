class Solution {
private:
    enum State{
        White = 0,
        Gray = 1,
        Black = 2
    };

    vector<int> state;
    vector<vector<int>> adj_list;

    vector<int> start;  
    vector<int> finish;

    vector<int> ans;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // adj_list
        adj_list.assign(numCourses, vector<int>({}));
        for(auto& prerequisite : prerequisites)
        {
            int b = prerequisite[0];
            int a = prerequisite[1];

            adj_list[a].push_back(b);
        }

        int time=0;

        // assign 不能只給 numCourses 還要給 -1
        start.assign(numCourses, -1); 
        finish.assign(numCourses, -1);

        state.assign(numCourses, White);
        for(int i=0 ; i<numCourses ; ++i)
        {
            if(state[i] == White)
            {
                if(dfs_find_cycle(i, time)) 
                    return ans; // 直接 return empty
            }
        }

        // 取得所有的 finish time & start time 後
        topology_sort();
        return ans;
    }

    bool dfs_find_cycle(int i, int& time)
    {
        state[i] = Gray;
        start[i] = time++;

        for(int node : adj_list[i])
        {
            if(state[node] == White)
            {
                if(dfs_find_cycle(node, time))
                    return true;
            }
            else if(state[node] == Gray)
            {
                // finish[i] = time++; 可以不紀錄了，畢竟 return true
                return true;
            }
                
        }

        state[i] = Black;
        finish[i] = time++;
        return false;
    }

    void topology_sort()
    {
        vector<pair<int,int>> arr;
        for(int i=0 ; i<finish.size() ; ++i)
        {
            arr.push_back({finish[i], i});
        }

        sort(arr.begin(), arr.end(), greater<>()); // 要大到小排

        for(auto element : arr)
        {
            ans.push_back(element.second);
        }
    }
};
