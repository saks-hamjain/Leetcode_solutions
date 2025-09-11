class Solution {
public:
   bool match(string a,string b)
   {
      return a.substr(0,b.size()) == b;
   }
    string replaceWords(vector<string>& dictionary, string sentence) 
    {
        vector<string> st;
        string res = "";
        stringstream ss(sentence);
        string word ="";
        while(ss >> word)
        {
           st.push_back(word);
        }
         for (int i=0;i<st.size();i++)
         {  
            word = st[i];
            string mini ="";
            for(int j =0;j<dictionary.size();j++)
            {
                if(match(word,dictionary[j]))
                    if(mini.size() == 0 || dictionary[j].size() < mini.size())
                       mini = dictionary[j];  
            }
            res +=(mini.empty() ? word : mini) +" ";
         }
        if(!res.empty()) res.pop_back();

        return res; 
    }
};