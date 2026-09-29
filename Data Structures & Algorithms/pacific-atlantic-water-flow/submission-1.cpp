
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();

        // Memorziation 就是 visited 
        vector<vector<bool>> pac(m, vector<bool>(n, false)); // m*n 初始化是 fasle，代表已經檢查過 pac
        vector<vector<bool>> atl(m, vector<bool>(n, false)); // m*n 標記是否已經檢查過 pac
        // 不初始化會導致存取 pac[i][0] 出事

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        queue<vector<int>> q;

        // =========================
        // Pacific BFS
        // =========================

        // 第一行、第一列都是 Pacific 的起點
        for(int i = 0; i < m; ++i)
        {
            pac[i][0] = true;
            q.push({i, 0});
        }
        for(int j = 0; j < n; ++j)
        {
            if(!pac[0][j])
            {
                pac[0][j] = true;
                q.push({0, j});
            }
        }

        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();

            int x = cur[0];
            int y = cur[1];

            for(int k = 0; k < 4; ++k)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                // 1. 邊界檢查
                if(nx < 0 || nx > m-1 || ny < 0 || ny > n-1)
                    continue;

                // 2. 已經標記過
                if(pac[nx][ny])
                    continue;

                // 如果是流的過來的板塊
                if(heights[nx][ny] >= heights[x][y])
                {
                    // 3. 標記並加入 Queue
                    pac[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        // =========================
        // Atlantic BFS
        // =========================

        // 最後一行、最後一列都是 Atlantic 的起點
        for(int i = 0; i < m; ++i)
        {
            atl[i][n-1] = true;
            q.push({i, n-1});
        }
        for(int j = 0; j < n; ++j)
        {
            if(!atl[m-1][j]) // 避免重複放 [m-1][n-1]
            {
                atl[m-1][j] = true;
                q.push({m-1, j});
            }
        }

        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();

            int x = cur[0];
            int y = cur[1];

            for(int k = 0; k < 4; ++k)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                // 1. 邊界檢查
                if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                // 2. 已經標記過
                if(atl[nx][ny])
                    continue;

                // 反向水流
                if(heights[nx][ny] >= heights[x][y])
                {
                    atl[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        // =========================
        // Find intersection
        // =========================

        vector<vector<int>> ans;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(pac[i][j] && atl[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
