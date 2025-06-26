class Solution {
public:
    int longestPalindrome(string s, string t) 
    {
        int n = s.size();
        int m = t.size();
        vector<int>maxStart(n);
        vector<int>maxEnd(m);
        int ans =0;
        vector<vector<bool>>pal(n,vector<bool>(n,false));
        for(int i = n-1;i>=0;i--){
            for(int j = i;j<n;j++)
            {
                pal[i][j] = ((i==j) || (j ==i+1 && s[i]==s[j]) || (pal[i+1][j-1] && s[i]==s[j]));
                if(pal[i][j])
                {
                    maxStart[i] = max(maxStart[i],j-i+1);
                    ans = max(ans,j-i+1);
                }
            }
        }
        vector<vector<bool>> pal1(m,vector<bool>(m,false));
        for(int i = m-1;i>=0;i--){
            for(int j =i;j<m;j++)
            {
                pal1[i][j] = ((i==j) || (j==i+1 && t[i] == t[j]) || (pal1[i+1][j-1] && t[i] == t[j]));
                if(pal1[i][j])
                {
                    maxEnd[j] = max(maxEnd[j],j-i+1);
                    ans = max(ans,j-i+1);
                }
            }
        }
         
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j = m-1;j>=0;j--)
            {
                if(s[i] == t[j])
                {
                    if(i >0 && j <m-1)
                    dp[i][j] = max(dp[i][j],2+dp[i-1][j+1]);
                    else
                    dp[i][j] = 2;
                   
                   int toadd = 0;
                   if(i+1 <n)
                   toadd = max(toadd,maxStart[i+1]);
                   if(j-1 >=0)
                   toadd = max(toadd,maxEnd[j-1]);

                   ans = max(ans,dp[i][j]+toadd);
                }
            }
        }
        return ans;

    }
};