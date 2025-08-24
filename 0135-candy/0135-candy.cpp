class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n <= 1) return n;
        vector<int> tmp(n,1);
        for(int i = 1;i<n;i++)
        {
            if(ratings[i] > ratings[i-1])
             tmp[i] = max(tmp[i],tmp[i-1]+1);
        }
        for(int i= n-2;i>=0;i--)
        {
            if(ratings[i] > ratings[i+1])
            tmp[i] = max(tmp[i],tmp[i+1]+1);
        }

    
        return accumulate(tmp.begin(),tmp.end(),0);
    }
};