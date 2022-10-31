class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int height = matrix.size(), width = matrix[0].size();
        for(int i = 1; i < height; i++)
            for(int j = 1; j < width; j++)
                if(matrix[i][j] != matrix[i-1][j-1])
                    return false;
        return true;
    }
};