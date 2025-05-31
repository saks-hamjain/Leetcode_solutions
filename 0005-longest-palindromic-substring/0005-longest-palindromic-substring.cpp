class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<bool>>memo(n,vector<bool>(n,false));
        int start =0,maxlen=1;
         for(int i=0;i<n;i++)
          memo[i][i] = true;
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i] ==s[i+1])
            {
                memo[i][i+1] = true;
                if(maxlen<2)
                {
                    start =i;
                    maxlen =2;
                }
            }
        }
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j = i+k-1;

                if(memo[i+1][j-1] && s[i] == s[j]){
                  memo[i][j] = true;
                if(k> maxlen)
                {
                    start = i;
                    maxlen = k;
                }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};