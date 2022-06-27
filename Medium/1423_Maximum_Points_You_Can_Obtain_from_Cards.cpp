class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0, len = cardPoints.size();
        for(int i = 0; i < k; i++) sum += cardPoints[i];// 計算第一組
        int maxn = sum;
        for(int i = 0; i < k; i++)
        {
            sum += cardPoints[len-i-1] - cardPoints[k-i-1]; // 加入後面往前，剪掉由前往後
            if(sum > maxn) maxn = sum; // 儲存最大值
        }
        return maxn;
    }
};
