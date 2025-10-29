class Solution {
public:
    bool checkParenthesis(string str)
    {
        int count = 0;
        for(auto i : str)
        {
            if(i == '(')
            count++;
            else
            {
                if(count == 0) return false;
                else 
                count--;
            }
        }
        return count == 0;
    }
    void allpairs(string &str,int n,vector<string> &generated)
    {
        if(str.length() == n){ 
         generated.push_back(str);
         return;
        }
         str.push_back('(');
         allpairs(str,n,generated);

         str.pop_back();

         str.push_back(')');
         allpairs(str,n,generated);
         str.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> generated;
        vector<string> res;
        string str = "";
        allpairs(str,2*n,generated);

        for(auto ele:generated)
        {
            if(checkParenthesis(ele))
            {
                res.push_back(ele);
            }
        }
        return res;
    }
};