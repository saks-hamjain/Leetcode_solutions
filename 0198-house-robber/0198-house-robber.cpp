class Solution {
public:
int calc(vector<int>& nums,int n,vector<int>& dp)
{
    if(n == 0) return 0;
    if(n== 1) return nums[0];

    if(dp[n] != -1) return dp[n];

    int loot = nums[n-1]+calc(nums,n-2,dp);
    int notloot= calc(nums,n-1,dp);
    return dp[n]=max(loot,notloot);
    }

    int rob(vector<int>& nums) 
    {
      int n = nums.size();
      if(n== 0) return 0;
      if(n==1) return nums[0];

     int sl=0;
     int l = nums[0];
      int rev;
      for(int i =2;i<=n;i++)
      {
        rev = max(nums[i-1] +sl,l);
        sl = l;
        l= rev;
      }
      return l;
    }
};