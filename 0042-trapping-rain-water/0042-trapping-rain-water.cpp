class Solution {
public:
    int trap(vector<int>& height) 
    {
        int  n = height.size();
        int res = 0;
        int lmax = height[0];
        int rmax = height[n-1];
        int left = 1;
        int right = n-2;
        
        while(left <= right)
        {
            if(lmax <= rmax)
            {
                lmax = max(lmax,height[left]);
                res += max(0,lmax - height[left]);
                left++; 
            }
            else
            {
                rmax= max(rmax,height[right]);
                res += max(0,rmax - height[right]);
                right--; 
            }
        }
       return  res;

    }
};