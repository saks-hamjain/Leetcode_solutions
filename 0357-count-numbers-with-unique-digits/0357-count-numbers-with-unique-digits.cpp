class Solution {
public:
    int countNumbersWithUniqueDigits(int n) 
    {
       if(n== 0) return 1;
       int ans = 10;
       int start = 9;
       int current = 9;
       while(n !=1 && start)
       {
         current *= start;
         start--;
         n--;
         ans += current;
       } 
       return ans;
    }
};