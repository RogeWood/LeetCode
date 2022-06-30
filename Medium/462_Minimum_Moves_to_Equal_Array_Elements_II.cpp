class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        int sum = 0;
        if(len%2)
        {
            int target = nums[len/2];
            for(int i = 0; i < len; i++)
                sum += abs(nums[i] - target);
        }
        else
        {
            int t1 = nums[len/2], sum1 = 0;
            int t2 = nums[len/2 - 1], sum2 = 0;
            for(int i = 0; i < len; i++)
            {
                sum1 += abs(nums[i] - t1);
                sum2 += abs(nums[i] - t2);
            }
            sum = (sum1 < sum2) ? sum1 : sum2;
        }
        return sum;
    }
};
