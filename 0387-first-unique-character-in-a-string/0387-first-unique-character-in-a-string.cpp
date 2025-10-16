class Solution {
public:
    int firstUniqChar(string s) 
    {
        int res = -1;
       unordered_map<char,int> mp;
       queue<char> q;
       for(auto ch : s)
       {
          mp[ch]++;
          q.push(ch);
       }   
       while(!q.empty())
       {
         if(mp[q.front()] == 1)
          break;

          q.pop();
       }
       
       if(q.empty()) return -1;

       return s.find(q.front());
    }
};