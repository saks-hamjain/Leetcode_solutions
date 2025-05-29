class Solution {
public:
    vector<vector<int>> ans;
    void allsubset(vector<int>&nums,vector<int> li,int k)
    {
        if(k >= nums.size())
        {
           ans.push_back(li);
           return;
        }
        li.push_back(nums[k]);
        allsubset(nums,li,k+1);
        li.pop_back();
        allsubset(nums,li,k+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> li;
        allsubset(nums,li,0);
       return ans; 
    }
};