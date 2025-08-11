class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
       
        int maxi =0,n = special.size();
        sort(special.begin(),special.end());
        for(int i=1;i<n;i++)
        {
            maxi = max(maxi,special[i] - special[i-1]-1);
        }
        maxi = max(maxi, top - special[n-1]);
        maxi = max(maxi, special[0] - bottom);
        
        return maxi;
    }
};