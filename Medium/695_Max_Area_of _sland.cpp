class Solution {
public:
    int DFS(int x, int y, int h, int w, vector<vector<int>>& visited, vector<vector<int>>& grid)
    {
        // 非地面和已拜訪過的回傳0
        if(x < 0 || x >= h || y < 0 || y >= w || visited[x][y] || !grid[x][y]) return 0;
        
        visited[x][y] = 1; // 紀錄拜訪過
        int next[4][2] = {{0, 1},{0, -1},{1, 0},{-1, 0}};
        int sum = 0;
        
        // 檢查上下左右
        for(int i = 0; i < 4; i++)
        {
            int nextx = x + next[i][0], nexty = y + next[i][1];
            sum += DFS(nextx, nexty, h, w, visited, grid);
        }

        return sum + 1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size(), maxn = 0;
        vector<vector<int>> visited(h, vector<int>(w, 0));
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                if(grid[i][j] && !visited[i][j])
                {
                    int sum = DFS(i, j, h, w, visited, grid);
                    if(maxn < sum) maxn = sum;
                }
         return maxn;
    }
};