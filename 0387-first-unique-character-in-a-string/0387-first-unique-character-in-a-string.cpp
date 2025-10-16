class Solution {
public:
    int firstUniqChar(string s) 
    {
        int res = -1;
       unordered_map<char,int> mp;
       for(auto ch : s)
       {
          mp[ch]++;
       }   
       
       for(int i=0;i<s.length();i++)
       {
         if(mp[s[i]] == 1) return i;
       }

       return -1;
    }
};