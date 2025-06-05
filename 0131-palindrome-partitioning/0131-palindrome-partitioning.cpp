class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
       int n = s.length();
       vector<vector<bool>> dp(n,vector<bool>(n,false));
       for(int i=0;i<n;i++)
        dp[i][i] =true;  // length of 1 palindromes
       
       for(int k =2;k <= n;k++)
       {
         for(int i=0;i<= n-k ;i++)
         {
            int j = i+k-1;
            if(s[i] == s[j])
             {
                if(k==2 || dp[i+1][j-1])
                 dp[i][j] = true;
             }
         }
       }

       vector<vector<string>> res;
       vector<string> temp;

       function<void(int)> dfs = [&](int start){
         
         if(start == n) 
         {
            res.push_back(temp);
            return;
         }
         for(int end = start;end < n;end++)
         {
            if(dp[start][end])
            {
                temp.push_back(s.substr(start,end-start+1));
                dfs(end+1);
                temp.pop_back();
            }
         }
       };
       dfs(0);
       return res;
    }
};