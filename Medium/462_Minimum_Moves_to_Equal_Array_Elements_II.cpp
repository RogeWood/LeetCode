class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());// 排序找中位數

        int t = nums[len/2], sum = 0;
        for(int i = 0; i < len; i++) // 將所有差距加起來
            sum += abs(nums[i] - t);
        return sum;
    }
};
