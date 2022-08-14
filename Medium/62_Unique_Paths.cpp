class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1; // 其中是 1 只會有一種走法
        // 將上方和左方一格的方法數相加
        vector<int> grid(n, 1);// 第一排只有一種走法，最左邊走法也只有1
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                grid[j] += grid[j-1];
        return grid[n-1];
    }
};
