class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) 
    {
        int n = arr.size();
        if(n <= 1) return n;
        int maxi =1;

        for(int i = 0;i<n-1;i++)
        {
           int first = arr[i];
           int sec = arr[i+1];
           if(first < sec || first > sec) maxi = max(maxi,2);

           for(int j = i+2;j<n;j++)
           {
             if(first > sec)
             {
                if((j-i) % 2 == 0 && arr[j-1] < arr[j])
                maxi = max(maxi,j-i+1);
                else if((j-i) %2 == 1 && arr[j] < arr[j-1])
                maxi = max(maxi,j-i+1);
                else break;
             }
             else if(first < sec)
             {
                if((j-i) % 2 == 0 && arr[j-1] > arr[j])
                maxi = max(maxi,j-i+1);
                else if((j-i) %2 == 1 && arr[j] > arr[j-1])
                maxi = max(maxi,j-i+1);
                else break;
             }
             else break;
           }            
        }
        return maxi;
    }
};