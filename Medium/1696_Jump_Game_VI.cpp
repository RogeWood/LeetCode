class Solution {
public:
    int maxResult(vector<int>& nums, int k)
    {
        int len = nums.size();
        priority_queue<pair<int, int>> pq; // 儲存最大值
        
        pq.push({nums[0], 0});
        for(int i = 1; i < len; i++)
        {
            while(pq.size() && pq.top().second < i - k) pq.pop(); // 間距小於限制 k 
            pq.push({nums[i] + pq.top().first, i}); // 加上目前最大值後加入pq
        }
        
        while(pq.top().second != len - 1) pq.pop(); // 去掉非最後一個
        return pq.top().first;
    }
};