class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        int ptr1 = 0;
        int ptr2 = 0;
        do{
            ptr1 = nums[ptr1];
            ptr2 = nums[nums[ptr2]];
        }while(ptr1 != ptr2);
        ptr2 = 0;
        do{
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }while(ptr1 != ptr2);

        return ptr1;
    }
};