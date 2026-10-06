class Solution {
public:
    int uniquePaths(int m, int n) {

        int dp[101][101]={0};
        dp[1][1] = 1;

        for(int round=1; round<=max(m,n) ; ++round)
        {
            if(round!=1)
                dp[round][round] = dp[round][round-1]+dp[round-1][round];

            for(int i=round+1 ; i<=n ; ++i)
                dp[round][i]=dp[round][i-1]+dp[round-1][i];
            for(int j=round+1 ; j<=m ; ++j)
                dp[j][round]=dp[j][round-1]+dp[j-1][round];

                // cout << round << endl;
        }
        return dp[m][n];
    }
};
// 定義 dp[x][y] 是在 (x,y) 座標時，有幾種 unique path 走到終點

// dp[x][y] = 1, if x==0 && y==0 
// dp[x][y] = dp[x][y-1] + dp[x-1][y]

// 0 0 0 0 0 0 0 0 
// 0 1 1 1 1 1 1 1
// 0 1 2 ...
// 0 1 .   
// 0 1 .
// 0 1 .
// 0 1

// 1,1
// 1,2, 1,3, 1,4, 1,5, 1,6 ...
// 2,2, 3,2, 4,2,  

// 2,2, 
// 2,3, 2,4, 2,5, 2,6 ...
// 3,3, 3,4, 3,5, 

// 3,3, 
// 3,4, 3,5, 3,6 ...
// 4,3, 5,3, 6,3, 