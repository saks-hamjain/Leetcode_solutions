class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));

        function<int(int,int)> dfs = [&](int i,int j){
          if(i == n-1) return triangle[i][j];
          if(dp[i][j] != INT_MAX) return dp[i][j];

          int same = dfs(i+1,j);
          int right = dfs(i+1,j+1);

          return dp[i][j] = min(same,right)+triangle[i][j];
        };
        int ans = dfs(0,0);
        return ans;
    }
};