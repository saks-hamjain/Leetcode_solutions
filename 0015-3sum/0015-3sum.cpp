class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        int n = nums.size();

        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int j = i+1;
            int k = n-1;
            if(i > 0 && nums[i] == nums[i-1])  
            {
               continue;
            }
            while(j < k)
            {
                int sum = nums[i] +nums[j]+ nums[k];
                if(sum < 0)
                {
                    j++;
                }
                else if(sum >0)
                {
                    k--;
                }
                else
                {
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1])
                    {
                        j++;
                    }
                    while(j<k && nums[k] == nums[k+1])
                    {
                        k--;
                    }
                }
            }
        }
        return res;
    }
};