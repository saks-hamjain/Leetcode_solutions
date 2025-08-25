class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
         int m = board.size();int n = board[0].size();
         vector<vector<int>> dp(m,vector<int>(n,0));
         vector<int> row ={-1,0,0,1};
         vector<int> col = {0,-1,1,0};

         function<bool(int,int ,int)> dfs = [&](int i,int j,int index)
         {
            if(index == word.length()) return true;
        
            if(i >= m || i < 0 || j >=n || j < 0) return false;

            if(dp[i][j] !=1 && word[index] == board[i][j])
            {
                dp[i][j] = 1;
                    for(int d=0;d<4;d++)
                    {
                        if(dfs(i+row[d],j+col[d],index+1)) 
                         return true;
                    }
                
                dp[i][j] =0;
            } 
            return false;       
         };
         for(int i=0;i<m;i++)
         {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == word[0]){
                    if(dfs(i,j,0)) return true;
                }
            }
         }
       return false;
    }
};