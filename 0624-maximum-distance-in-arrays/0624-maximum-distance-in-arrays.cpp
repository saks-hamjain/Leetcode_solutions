class Solution 
{
    public:
    int maxDistance(vector<vector<int>>& arrays) 
    {
        int m = arrays.size();
        int res = 0;
        int mini =arrays[0][0];
        int maxi = arrays[0].back();
        for(auto ar=1;ar<m;ar++)
        {  
            res = max(res,abs(arrays[ar].back()-mini));
            res = max(res,abs(maxi - arrays[ar].front()));
            mini = min(mini,arrays[ar].front());
            maxi = max(maxi,arrays[ar].back());
        }
        return res;
    }
};