class Solution {
public:
    int isPossible(vector<int>& nums,int sum,int index,vector<vector<int>>& dp)
    {
       if(index == nums.size() && sum == 0) return 1;

       if(index == nums.size() || sum < 0 ) return 0;

       if(dp[index][sum] != -1) return dp[index][sum];

       bool take = false;
       if(nums[index] <= sum)
        take = isPossible(nums,sum-nums[index],index+1,dp);
       
       bool not_take = isPossible(nums,sum,index+1,dp);
       return dp[index][sum] = take || not_take;
    }
    bool canPartition(vector<int>& nums) 
    {
           long long total =0;
           total = accumulate(nums.begin(),nums.end(),0);
           if(total % 2 != 0) return false;
           total = total/2;
        //    vector<vector<int>> dp(nums.size(),vector<int>((total/2)+1,-1));
        //    bool answer = isPossible(nums,total/2,0,dp);
        vector<bool> dp(total+1,false);
        dp[0] = true;
         for(auto num :nums)
         {
            for(int j = total;j>=num;j--)
               dp[j]  = dp[j] || dp[j-num];
         }
           return dp[total]; 
    }
};