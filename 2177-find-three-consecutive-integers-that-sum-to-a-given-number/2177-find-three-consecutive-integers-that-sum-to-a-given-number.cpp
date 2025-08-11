class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> temp;
     if(num % 3 != 0) return temp;

     long long mid = num / 3;
     if((3*(mid -1) +3) == num)
     {
        temp.push_back(mid-1);
        temp.push_back(mid);
        temp.push_back(mid+1);
     }
       return temp; 
    }
};