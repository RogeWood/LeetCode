class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int width = grid[0].size(), height = grid.size();
        vector<int> ans(width, -1);
        for(int i = 0; i < width; i++)
        {
            int j = 0, direction = grid[0][i], k = i;
            while(j < height)
            {
                direction = grid[j][k];
                k += direction;
                if(k < 0 || k >= width) break;
                else if(grid[j][k] == direction) j++; // 兩邊接成路可以往下
                else break;
            }
            if(j == height) ans[i] = k;
        }
        return ans;
    }
};