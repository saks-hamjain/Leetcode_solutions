class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector(n,-1));
        function<int(int,int)> dfs = [&](int i,int j){
            if(i == m-1 && j == n-1) return grid[m-1][n-1];
            if(i >=m || j>=n) return INT_MAX;
            if(dp[i][j] != -1) return dp[i][j];
            int right = dfs(i,j+1);
            int down = dfs(i+1,j);
            
            return dp[i][j] = min(right,down)+ grid[i][j];
        };
        int answer = dfs(0,0);
        return answer;
    }
};