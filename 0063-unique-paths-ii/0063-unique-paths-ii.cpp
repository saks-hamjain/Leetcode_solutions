class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,1));

        for(int i =0;i<m;i++)
        {
            for(int j = 0;j <n;j++)
            {
                if(obstacleGrid[i][j])
                {
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(obstacleGrid[i][j]) continue;
               
                if(i-1 >= 0 && j-1 >= 0)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else if(i-1 >=0)
                  dp[i][j] = dp[i-1][j];
                else if(j-1 >= 0)
                dp[i][j] = dp[i][j-1];
                
            }
        }

        return dp[m-1][n-1];
    }
};