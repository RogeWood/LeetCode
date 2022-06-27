class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a;

        for(int i = 0; i < nums.size(); i++)
        {
            int n = target - nums[i]; // 配對的值
            int findindex = -1;
            for(int j = i+1; j < nums.size(); j++)
            {
                if(n == nums[j]) // 找到值
                {
                    findindex = j;
                    break;
                }
            }
            if(findindex != -1) // 儲存
            {
                a.push_back(i);
                a.push_back(findindex);
                break;
            }
        }
        return a;
    }
};
