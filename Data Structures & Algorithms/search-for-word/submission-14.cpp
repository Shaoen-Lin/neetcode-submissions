class Solution {
private:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};

    bool visited[6][6]={0}; // 避免重複走

public:
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for(int i=0 ; i<m ; ++i)
        {
            for(int j=0 ; j<n ; ++j)
            {
                if(board[i][j] == word[0])
                {
                    if(dfs(i, j, 1, board, word))
                        return true;
                }
            }
        }
        return false;
    }

    bool dfs(int x, int y, int match_size, vector<vector<char>>& board, string word)
    {
        if(match_size==word.length())
            return true;

        visited[x][y] = true;

        for(int i=0 ; i<4 ; ++i)
        {
            int new_x = x+dx[i];
            int new_y = y+dy[i];

            // 很重要！要使用 dx 就要寫這個
            if(new_x < 0 || new_x >= board.size() ||
                new_y < 0 || new_y >= board[0].size())
            {
                continue;
            } 

            // new 檢查要在前面不然怕這步驟會存取失敗
            if(visited[new_x][new_y] == true)
                continue;

            if(match_size<word.length() 
                && (board[new_x][new_y] == word[match_size])) // 注意這裡填的是 match_size 不是 +1
            {
                match_size++;

                if(dfs(new_x, new_y, match_size, board, word))
                {
                    visited[x][y] = false; // 可改可不改
                    return true;
                }

                match_size--;
            }
        }
        visited[x][y] = false;
        return false;
    }
};