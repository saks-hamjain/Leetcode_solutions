class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        if(n <= 10) return {};
    vector<string> res;
    unordered_map<string,int> hash;
    for(int i=0;i<=n-10;i++)
        hash[s.substr(i,10)]++;

        for(auto str : hash)
        if(str.second >1)
         res.push_back(str.first);

         return res;
    }
};