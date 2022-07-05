// Solution 1
// Time Complexity: O(nlog n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //排序
        
        int maxlen = 0, len = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1]) continue; // 重複跳過
            else if(nums[i] != nums[i-1] + 1) // 如果不連續，紀錄當前最常值
            {
                if(len > maxlen) maxlen = len;
                len = 0;
            }
            len++;
        }
        
        return (nums.size()) ? max(len, maxlen) : 0; // 如果沒有東西，回傳 0
    }
};

// Solution 2 link: https://leetcode.com/problems/longest-consecutive-sequence/discuss/2239045/C%2B%2B-oror-BEATS-95-oror-O(N)-ororOPTIMIZED
// Time Complexity: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_len = 0;
        unordered_set<int> num_set(nums.begin(), nums.end());
        for (int num : nums) {
            if (num_set.find(num - 1) == num_set.end()) {
                int curr_num = num;
                int curr_len = 1;
                while (num_set.find(curr_num + 1) != num_set.end()) {
                    curr_num++;
                    curr_len++;
                }
                max_len = max(max_len, curr_len);
            }
        }
        return max_len;
    }
};