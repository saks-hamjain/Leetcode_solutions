class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        // vector<vector<int>> dp(n,vector<int>(n,INT_MAX));

        // function<int(int,int)> dfs = [&](int i,int j){
        //   if(i == n-1) return triangle[i][j];
        //   if(dp[i][j] != INT_MAX) return dp[i][j];

        //   int same = dfs(i+1,j);
        //   int right = dfs(i+1,j+1);

        //   return dp[i][j] = min(same,right)+triangle[i][j];
        // };
        // int ans = dfs(0,0);
        
        vector<int> dp1(n,INT_MAX);
        vector<int> dp2(n,INT_MAX);

        for(int i = n-1;i>= 0;i--)
         dp2[i] = triangle[n-1][i];

         for(int i = n-2;i>=0;i--)
         {
            for(int j = i;j>=0;j--)
            {
                dp1[j] = min(dp2[j],dp2[j+1]) + triangle[i][j];
            }
            dp2 = dp1;
         }
        
        return dp2[0];
    }
};