class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n <= 1) return n;
        vector<int> tmp(n,1);
        for(int i = 0;i<n;i++)
        {
            int lc =0,left = i;
            int rc =0,right=i;
            while(left > 0 && ratings[left-1] < ratings[left])
            {
                lc++;
                left--;
            }
            while(right < n-1 && ratings[right+1] < ratings[right])
            {
                right++;
                rc++;
            }
            tmp[i] += max(lc,rc);
        }

    
        return accumulate(tmp.begin(),tmp.end(),0);
    }
};