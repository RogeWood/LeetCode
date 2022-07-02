class Solution {
public:

    long long int findmax(vector<int>& arr) // 找出間距最大值
    {
        long long int maxn = 0;
        for(int i = 1; i < arr.size(); i++)
            maxn = (maxn < arr[i] - arr[i-1]) ? arr[i] - arr[i-1] : maxn;
        return maxn;
    }

    void setCut(vector<int>& arr, int a) // 將頭尾數字加入 vector
    {
        arr.push_back(a);
        arr.push_back(0);
        sort(arr.begin(), arr.end()); // 由小到大排序
        return;
    }

    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        setCut(horizontalCuts, h);
        setCut(verticalCuts, w);

        // 數字極大 開 long long
        return findmax(horizontalCuts) * findmax(verticalCuts) % 1000000007;
    }
};
