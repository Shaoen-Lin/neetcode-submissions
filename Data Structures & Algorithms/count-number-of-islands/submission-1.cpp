class Solution {
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    // 跑完上下左右各一格的秘法

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool visited[100][100] = {0};

        int ans=0;

        // raw-major
        for(int i=0 ; i<m ; ++i)
        {
            for(int j=0 ; j<n ; ++j)
            {
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    ++ans;
                    visited[i][j]=1;
                    // BFS
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty())
                    {   
                        // pair<int,int> tmp = q.front();
                        // int x = tmp.first; // pop 出的點的 x 座標
                        // int y = tmp.second; // pop 出的點的 y 座標

                        auto [x, y] = q.front();
                        
                        q.pop();
                        for(int k=0; k<4 ; ++k)
                        {
                            int new_x = x + dx[k];
                            int new_y = y + dy[k];

                            if(new_x<0 || new_x>=m || 
                                new_y<0 || new_y>=n)
                                continue;
                            else if(grid[new_x][new_y]=='1' 
                            && visited[new_x][new_y]==0)
                            {
                                visited[new_x][new_y]=1;
                                q.push({new_x,new_y});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
// 解法：BFS
// 先匯至一個 table 叫做 visited
// 之後只要掃到一個 1 就跑 BFS 把相鄰的 1 也在 Table 中標示 1 直到沒有 1 放進去。

// Time:O(m*n)
// Space:O(m*n)

