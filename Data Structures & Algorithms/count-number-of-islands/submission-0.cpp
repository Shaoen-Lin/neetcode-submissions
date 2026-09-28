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
                        pair<int,int> tmp = q.front();
                        int x = tmp.first; // pop 出的點的 x 座標
                        int y = tmp.second; // pop 出的點的 y 座標
                        q.pop();
                        for(int k=0; k<4 ; ++k)
                        {
                            if(x+dx[k]<0 || x+dx[k]>=m || 
                                y+dy[k]<0 || y+dy[k]>=n)
                                continue;
                            else if(grid[x+dx[k]][y+dy[k]]=='1' 
                            && visited[x+dx[k]][y+dy[k]]==0)
                            {
                                visited[x+dx[k]][y+dy[k]]=1;
                                q.push({x+dx[k],y+dy[k]});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
// BFS -> 先匯至一個 table 叫做 visited
// 只要掃到一個 1 就跑 BFS 把相鄰的 1 也在 Table 中標示 1 直到沒有 1 放進去。