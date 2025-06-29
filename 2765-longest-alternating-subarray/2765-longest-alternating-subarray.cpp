class Solution {
public:
    int alternatingSubarray(vector<int>& arr) 
    {
      int n = arr.size();
      int maxi =-1;
      for(int i =0;i<n;i++)
      {
        for(int j =i+1;j<n;j++)
        {
            if(i%2 == j%2  && arr[j] == arr[i])
                maxi = max(maxi,j-i+1);
            else if(i%2 != j%2 && arr[j] == arr[i] +1)
                maxi = max(maxi,j-i+1);
            else break;

        }
      }
      return maxi;
    }
};