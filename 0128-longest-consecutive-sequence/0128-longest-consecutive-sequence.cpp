class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        // int n = nums.size();

        // if(n <= 1)
        // return n;

        // int maxi = 1;
        // int count=0;
        // unordered_set<int> st;

        // for(int i =0;i<n;i++)
        // st.insert(nums[i]);
         
        //  for(auto it : st)
        //  {
        //     if(st.find(it-1) == st.end())
        //     {
        //     count =1;
        //     int x = it;
        //     while(st.find(x+1) != st.end())
        //     {
        //         count++;
        //         x++;
        //     }
        //  }
        //  maxi = max(maxi,count);
        //  }
        //  return maxi;



        int n = nums.size();
        if(n<=1) return n;

        int maxi = 1,count =1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            while(i<n && nums[i] == nums[i-1]) i++;
            if(i<n && nums[i-1] == nums[i] - 1)
            {
                count++;
                maxi = max(maxi,count);
            }
            else
            {
                count =1;
            }
        }
        return maxi;
    }
};