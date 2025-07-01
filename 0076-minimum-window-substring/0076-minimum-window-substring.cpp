class Solution {
public:
    string minWindow(string s, string t) 
    {
        if(t.size() > s.size()) return "";

        unordered_map<char,int>tmp,window;
        int start = -1,left =0,mini = INT_MAX,count = 0;

        for(auto i: t)
          tmp[i]++;
        
        for(int right = 0;right < s.size();right++)
        {
            window[s[right]]++;

            if(tmp.count(s[right]) && tmp[s[right]] == window[s[right]]) count++;

            while(count == tmp.size())
            {
                if(mini > right-left+1){
                    start= left;
                    mini = right-left+1;
                }

                window[s[left]]--;
                if(tmp.count(s[left]) && window[s[left]] < tmp[s[left]]) count--;

                left++;
            } 
        }
      if(start == -1) return "";

      return s.substr(start,mini);
    }
};