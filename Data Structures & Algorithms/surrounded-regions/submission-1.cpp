class Solution {
private:
    int m;
    int n; 
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    queue<pair<int,int>> q;

public:
    void solve(vector<vector<char>>& board) {
        
        m = board.size();
        n = board[0].size();

        for(int i=0 ; i<m ; i+=m-1)
        {
            if(i==m-1 && m-1==0)
                break;

            for(int j=0; j<n ; ++j)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='S';
                    q.push({i,j});
                }
            }
        }

        for(int j=0; j<n ; j+=n-1)
        {
            if(j==n-1 && n-1==0)
                break;

            for(int i=0 ; i<m ; ++i)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='S';
                    q.push({i,j});
                }
            }
        }
        
        bfs(board);

        for(int i=0; i<m ; ++i)
        {
            for(int j=0 ; j<n ; ++j)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='S')
                    board[i][j]='O';
            }
        }
    }

    void bfs(vector<vector<char>>& board)
    {
        while(!q.empty())
        {
            auto [a,b] = q.front();
            q.pop();

            for(int i=0; i<4 ; ++i)
            {
                int new_x = a+dx[i];
                int new_y = b+dy[i];

                if(new_x<0 || new_x>=m-1 || new_y<0 || new_y>=n-1)
                    continue;
                if(board[new_x][new_y] == 'X' || 
                    board[new_x][new_y] == 'S')
                    continue;

                board[new_x][new_y]='S';
                q.push({new_x, new_y});
            }
        }
    }
};
// 這題可以從兩個角度下手：
// 1. 從 "所有的點" 做 BFS  Time 變成 O(k*m*n), k 為所有 O 的數量
// 2. 只從外圍的 0 下手，必定小於 k 點所以第二種數量比較快， 
    // Time: O((m+n) * m*n) 
// 3. 但我們只要讓每一個最多跑到一次時間就會變成 Time: O(m*n)
    // 把跑過不能跑到外面的 O 直接改成 X 這樣就不會被跑到第二次了  