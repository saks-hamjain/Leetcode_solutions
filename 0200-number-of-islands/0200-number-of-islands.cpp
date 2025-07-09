class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
          int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> dp(n,vector<bool>(m,false));
        int count =0;
        
        vector<int> row = {-1,0,0,1};
        vector<int>col =  {0,-1,1,0};
        function<void(int,int)> dfs=[&](int i,int j)
        {
           dp[i][j] = true;
           for(int k=0;k<4;k++)
           {
               int nr= i+row[k];
               int nc = j+col[k];
               if(nr >=0 && nr <n && nc >=0 && nc <m && grid[nr][nc] == '1' && !dp[nr][nc])
                dfs(nr,nc);
           }
        };
        
        for(int i= 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == '1' && !dp[i][j])
                {
                    count++;
                    dfs(i,j);
                }
            }
        }
        
        return count;
    }
};