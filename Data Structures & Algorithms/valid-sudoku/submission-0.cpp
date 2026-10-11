class Solution {
private:
    int dx[9] = {0,1,2,0,1,2,0,1,2};
    int dy[9] = {0,0,0,1,1,1,2,2,2};

public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // row check (0,0) (0,1) (0,2) 
        for(int i=0 ; i<9 ; ++i)
        {
            unordered_set<char> set;
            for(int j=0; j<9 ; ++j)
            {
                if(board[i][j]=='.')
                    continue;

                if(set.count(board[i][j]))
                    return false;
                set.insert(board[i][j]);
            }
        }

        // col check (0,0) (1,0) (2,0) 
        for(int i=0 ; i<9 ; ++i)
        {
            unordered_set<char> set;
            for(int j=0; j<9 ; ++j)
            {
                if(board[j][i]=='.')
                    continue;

                if(set.count(board[j][i]))
                    return false;
                set.insert(board[j][i]);
            }
        }

        // block check (0,0) (3,3) (6,6) | (0,3) (3,3) (6,3)
        for(int i=0 ; i<9 ; ++i) // 9 個 block
        {
            int x = dx[i]*3;
            int y = dy[i]*3;

            unordered_set<char> set;
            for(int j=0; j<9 ; ++j)
            {
                int block_x = x+dx[j];
                int block_y = y+dy[j];

                if(board[block_x][block_y]=='.')
                    continue;
                
                if(set.count(board[block_x][block_y]))
                    return false;
                set.insert(board[block_x][block_y]);
            }
        }
        return true;
    }
};
