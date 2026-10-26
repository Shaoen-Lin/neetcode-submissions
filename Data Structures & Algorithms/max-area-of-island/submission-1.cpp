class Solution {
private:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    int m;
    int n;

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int max_area=0;
        for(int i=0; i<m ; ++i)
        {
            for(int j=0 ; j<n ; ++j)
            {
                if(grid[i][j] == 1)
                {
                    int area = bfs(grid, i, j);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }

    int bfs(vector<vector<int>>& grid, int x, int y)
    {
        queue<pair<int, int>> q;
        q.push({x,y});
        grid[x][y]=0; // 改這裡

        int area=0;
        while(!q.empty())
        {
            area++;
            auto [a,b] = q.front();
            // grid[a][b]=0; 擺在這會有問題，因為同一個格子可能在被 pop 之前，被不同鄰居重複 push 進 queue。
            q.pop();

            for(int i=0; i<4 ; ++i)
            {
                int new_a = a+dx[i];
                int new_b = b+dy[i];

                if(new_a<0 || new_a>=m || new_b<0 || new_b>=n)
                    continue;

                if(grid[new_a][new_b] == 1)
                {
                    q.push({new_a, new_b});
                    grid[new_a][new_b]=0; // 和改這裡
                }
            }    
        }
        return area;
    }
};
