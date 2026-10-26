class Solution {
private:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int m;
    int n;

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
                    bfs(grid, i, j);
                }
            }
        }
    }

    void bfs(vector<vector<int>>& grid, int x, int y)
    {
        queue<pair<int,int>> q;
        q.push({x,y});

        int dis=0;
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

// 用所有寶箱走 BFS，如果今天可以用這個寶箱走到比較小的數字就換掉，不行就留著
// 這樣也可以保持走不到就是 INT_MAX
// 也可以讓 0 不被換掉。
