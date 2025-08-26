class Solution {
public:
    int uniquePaths(int m, int n) 
    {
       vector<vector<int>> dp(m,vector<int>(n,-1));

       int ways =0;
       function<int(int,int)> dfs = [&](int i,int j){
         if(i >= m || j>= n) return 0;
         if(i == m-1 && j == n-1) return 1;
         if(dp[i][j] != -1) return dp[i][j];

         int right = dfs(i,j+1);
         int down = dfs(i+1,j);

        return dp[i][j] = right+down;
       };
       ways = dfs(0,0);
       return ways;
    }
};