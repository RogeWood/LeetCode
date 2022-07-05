// Soltion 1
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        
        int pri = nums[1] - nums[0]; // 儲存上一個值
        int count = (pri) ? 1 : 0;
        for(int i = 2; i < nums.size(); i++)
        {
            int n = nums[i] - nums[i-1];
            if(n && !pri) // 出現不重複的值
            {
                pri = n;
                count = 1;
            }
            if(pri * n < 0) // 正負不同，存起來
            {
                count++;
                pri = n;
            }
        }
        
        return count+1;
    }
};

// Solution 2

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size=nums.size(), peak=1, valley=1;
        for(int i=1; i<size; ++i){ // 畫成折線圖，紀錄出現波峰和波谷的頂點
            if(nums[i]>nums[i-1]) peak = valley + 1;
            else if(nums[i]<nums[i-1]) valley = peak + 1;
        }
        return max(peak , valley );
    }
};