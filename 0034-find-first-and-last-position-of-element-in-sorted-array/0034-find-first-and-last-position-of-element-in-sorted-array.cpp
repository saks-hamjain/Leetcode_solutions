class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
         if(nums.size() == 0) return {-1,-1};


        // int st = -1,end=-1;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i] == target && st ==-1)
        //      {
        //         st = i;
        //         end = i;
        //      }
        //      else if(nums[i] == target)
        //      {
        //         end = i;
        //      }
        // }
        // return {st,end};
     





      int st =0,end =nums.size()-1;
      int first = -1;
      int sec= -1;
      while(st <= end)       //code for lower bound
      {
        int mid = st+(end-st) /2;

        if(nums[mid] >= target)
          end = mid-1;   
        else 
            st= mid+1;
      }
      if(st < nums.size() && nums[st] == target)
        first = st;
      else
       return {-1,-1};

        st =0,end =nums.size()-1;

       
        while(st <= end)
      {
        int mid = st+(end-st) /2;

        if(nums[mid] <= target )
            st = mid +1;
        else 
            end= mid-1;
    }
    sec = end;

    return {first,sec};
    }
};