class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int start =0,end = nums.size()-1;
        int mid;
        while(start <= end)
        {
            mid = (start + end)/2;

            if(nums[mid] == target)
            return mid;
            
            //left sorted array.
            if(nums[start] <= nums[mid])
            {
                if(nums[start]<=target  && target<= nums[mid])
                  end = mid-1;
                else
                  start = mid+1;
            }
            else // right sorted array 
            {
               if(nums[mid] <= target && target <= nums[end])
                start = mid+1;
                else
                end = mid-1;
            }
        }
       return -1; 
    }
};