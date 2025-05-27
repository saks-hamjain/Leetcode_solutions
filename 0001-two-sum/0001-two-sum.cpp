class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int> res;
        for(auto i=0;i<nums.size();i++)
        {
           int sec = target- nums[i];
           if(res.find(sec) != res.end())
             return {i,res[sec]};
           else
            res[nums[i]] = i;
        }
        return {-1,-1};
    }
};