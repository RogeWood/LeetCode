class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size(), i, j;
        for(i = 0, j = len - 1; i < j; i++)
        {
            if(nums[i] == val) // 遇到 key
            {
                while(i < j && nums[j] == val) j--; // 由後往前找非 key 的值
                if(i >= j) break;
                swap(nums[i], nums[j]); // 交換
                j--;
            }
        }
        return (i == j && nums[i] != val) ? i + 1 : i;
    }
};