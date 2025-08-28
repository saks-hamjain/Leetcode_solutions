class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector(n,0));
        // function<int(int,int)> dfs = [&](int i,int j){
        //     if(i == m-1 && j == n-1) return grid[m-1][n-1];
        //     if(i >=m || j>=n) return INT_MAX;
        //     if(dp[i][j] != -1) return dp[i][j];
        //     int right = dfs(i,j+1);
        //     int down = dfs(i+1,j);
            
        //     return dp[i][j] = min(right,down)+ grid[i][j];
        // };
        // int answer = dfs(0,0);

        for(int i=0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i==0 && j== 0)
                  dp[i][j] = grid[i][j];
                else if(i==0)
                  dp[i][j] = dp[i][j-1] + grid[i][j];
                else if(j==0)
                  dp[i][j] = grid[i][j]+ dp[i-1][j];
                else
                  dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
                
            }
        }
        return dp[m-1][n-1];
    }
};