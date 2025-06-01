class Solution {
public:
    bool palindrome(string str)
    {
        int n = str.length();
        int i=0, j = n-1;
        if(n == 0) return true;
        
        while(i < j)
        {
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s)
    {
        string removed = "";
        for(auto i : s)
        {
            if(isalnum(i))
            {
                removed += tolower(i);
            }
        }
        
        return palindrome(removed);
    }
};