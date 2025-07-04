class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        if(n == 1) return {{1}};
        if(n == 2) return {{1,2},{4,3}};
        vector<vector<int>> res(n,vector<int>(n,0));
        int rs = 0,re = n-1,cs =0,ce =n-1;
        int k = 1;
        while(rs <= re and cs <= ce)
        {
            for(int i = cs;i <= ce;i++)
                res[rs][i] = k++;
                rs++;

            for(int i = rs;i<= re;i++)
                res[i][ce] = k++;
            ce--;
            if(rs <= re){
              for(int i = ce;i>=cs;i--)
               res[re][i] = k++;
               re--;
            }
               if(cs <= ce)
               {
                 for(int i= re;i>= rs;i--)
                   res[i][cs] = k++;
                   cs++;
               }
        }
      return res;
    }
};