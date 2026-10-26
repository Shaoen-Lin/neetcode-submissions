class Solution {
private:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int m;
    int n;
    queue<pair<int,int>> q;

    int num; // 沒有 rotten 的水果的數量
    int rot_time[11][11]={0}; // 紀錄每一格水果腐壞的時間點

public:
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        num=0;
        for(int i=0 ; i<m ; ++i)
        {
            for(int j=0 ; j<n ; ++j)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    // rot_time[i][j]=0;
                }
                else if(grid[i][j]==1)
                    num++;
            }
        }
        if(num==0)
            return 0;
        return bfs(grid);
    }

    // 把數字轉乘
    int bfs(vector<vector<int>>& grid)
    {
        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();

            for(int i=0 ; i<4 ; ++i)
            {
                int new_x = x+dx[i];
                int new_y = y+dy[i];

                if(new_x<0 || new_x>=m || new_y<0 || new_y>=n)
                    continue;

                if(grid[new_x][new_y] == 1)
                {
                    grid[new_x][new_y] = 2; 
                    // 這裡就要改避免 queue 裡面有一堆一樣的
                    q.push({new_x, new_y});

                    // 紀錄腐壞時間
                    rot_time[new_x][new_y] = rot_time[x][y]+1;

                    // 好水果數量 -1 
                    num--;

                    if(num==0)
                        return rot_time[new_x][new_y];
                }
            }
        }

        // if(num!=0)
        return -1;
    }
};

// 這題也是 Multi-source BFS