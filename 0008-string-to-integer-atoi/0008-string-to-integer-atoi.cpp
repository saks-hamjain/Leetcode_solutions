class Solution {
public:
    int myAtoi(string s) 
    {
        long res = 0;
       int num =1;
       int i=0;
       int n = s.size();
       while(i < n && s[i] ==' ') i++;
       if(s[i] =='-' || s[i] =='+')
       {
          if(s[i] =='-') num=-1;
          i++;
        }
        while(i < n && isdigit(s[i]))
        {
            res = res*10 + (s[i] -'0');
            if(res > INT_MAX) break;
           i++;
        }
        res *= num;

        if(res > INT_MAX) return INT_MAX;
        if(res < INT_MIN) return INT_MIN;
        return res;
    }
};