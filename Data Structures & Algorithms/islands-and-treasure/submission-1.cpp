class Solution {
private:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int m;
    int n;
    queue<pair<int,int>> q;

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        for(int i=0 ; i<m ; ++i)
        {
            for(int j=0; j<n ; ++j)
            {
                if(grid[i][j] == 0)
                {
                    q.push({i,j});
                }
            }
        }
        bfs(grid);
    }

    void bfs(vector<vector<int>>& grid)
    {
        while(!q.empty())
        {
            auto [a,b] = q.front();
            q.pop();

            for(int i=0 ; i<4 ; ++i)
            {
                int new_x = a+dx[i];
                int new_y = b+dy[i];

                if(new_x<0 || new_x>=m || new_y<0 || new_y>=n)
                    continue;
                else if(grid[new_x][new_y] == -1)
                    continue;

                // 沒有變小沒必要繼續跑 BFS，因為必定可以用其他最小的方法走 
                // 沒有就不要繼續看了
                if(grid[new_x][new_y] > grid[a][b]+1)
                {
                    grid[new_x][new_y] = grid[a][b]+1;
                    q.push({new_x, new_y});
                }
            }
            
        }
    }
};

// 第一次把所有的 source 擺進去 queue，這樣每個格子只要被走到一次
// 因為 每個 INF 格子第一次被 BFS 碰到時，那一定就是它距離「最近寶箱」的最短距離。