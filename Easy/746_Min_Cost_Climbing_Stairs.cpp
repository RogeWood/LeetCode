class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        cost.push_back(0); // 終點
        vector<int> dp(len+1, 0); // 記錄到此層的最少花費
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < len+1; i++)
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i]; // 往前 1 2 層，取最小值
        return dp[len];
    }
};