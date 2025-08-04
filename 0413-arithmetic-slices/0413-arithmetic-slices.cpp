class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
     int n = nums.size();
     if(n <= 2) return 0;

     int left = 0,leftnext =1,right =2,res =0,count =0;
     while(right <n)
     {
         if(nums[right] - nums[leftnext] == nums[leftnext] - nums[left])
         {
            int diff = nums[leftnext] - nums[left];
            count =1;
            res += count; 
            while(right+1 < n && (nums[right+1] - nums[right]) == diff)
            {
              right++;
              count++;
              res += count;
            }
            count=0;
         }
        if(right != leftnext+1)
        {
            left = right+1;
            leftnext = left+1;
            right = leftnext+1;
        }
        else
        {
            left++;
            leftnext++;
            right++;
        }
     }
     return res;
    }
};