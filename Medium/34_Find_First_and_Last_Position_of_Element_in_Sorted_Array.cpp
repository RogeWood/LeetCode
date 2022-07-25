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