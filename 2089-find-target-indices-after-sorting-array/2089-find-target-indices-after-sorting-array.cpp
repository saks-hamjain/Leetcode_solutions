class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) 
    {
        vector<int> vec;
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i] == target)
            vec.emplace_back(i);
        }
        return vec;
    }
};