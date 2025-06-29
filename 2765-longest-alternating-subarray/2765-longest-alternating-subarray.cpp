class Solution {
public:
    int alternatingSubarray(vector<int>& arr) 
    {
      int n = arr.size();
      int maxi =-1;
      int start =-1;
      for(int j=1;j<n;j++)
      {
            if(start ==-1 && arr[j] - arr[j-1] == 1)
            {
                 start = j-1;
                 maxi = max(maxi,2);
            }
            else if(start != -1 && (j-start)%2 ==0 && arr[j] == arr[start])
            maxi = max(maxi,j-start+1);
            else if(start != -1 && (j-start) %2 ==1 && arr[j] == arr[start + 1])
            maxi = max(maxi,j-start+1);
            else 
            {
                if(arr[j] - arr[j-1] == 1)
                {
                    start = j-1;
                 maxi = max(maxi,2);
                }
                else
                start = -1;
            }
      }
      return maxi;
    }
};