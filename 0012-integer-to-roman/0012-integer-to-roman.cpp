class Solution {
public:
    vector<string> roman={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    vector<int> val = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string intToRoman(int num) 
    {
        string ans="";
        int i=0;
        while(num > 0)
        {
             if(num >= val[i])
             {
                num -= val[i];
                ans += roman[i];
             }
             else
             i++;
        }
        return ans;   
    }
};