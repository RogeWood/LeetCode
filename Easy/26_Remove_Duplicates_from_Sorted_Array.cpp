// Solution 1:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size();)
            if(nums[i] == nums[i-1]) nums.erase(nums.begin() + i);
            else i++;
        
        return nums.size();
    }
};

// Solution

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for(int i = 1; i < nums.size(); i++)
            if(nums[i] != nums[i-1]) nums[k++] = nums[i];
        
        return k;
    }
};