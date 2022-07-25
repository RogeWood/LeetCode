// O(n)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size(), fpos = -1, lpos = -1;
        
        for(int i = 0; i < len; i++) // 由前往後找第一個值
            if(target == nums[i])
            {
                fpos = i;
                break;
            }
        
        for(int i = len - 1; i >= fpos && i >= 0; i--) // 由後往前找最後值
            if(target == nums[i])
            {
                lpos = i;
                break;
            }
        
        return {fpos, lpos};
    }
};
// O(log n)
// Solution link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/2329415/C%2B%2B-or-STL-or-5-Line-code-or-Bits-100-or-Test-Time-Saving-Method
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto low = lower_bound(nums.begin(),nums.end(),target);
        auto up = upper_bound(nums.begin(),nums.end(),target);
        
        if(!binary_search(nums.begin(),nums.end(),target))    return {-1,-1};
        
        int first = low - nums.begin();
        int last = up - nums.begin()-1;
        
        return {first ,last};
    }
};