class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h = matrix.size(), w = matrix[0].size();
        int i = h-1, j = 0;
        
        while(i >= 0 && j < w)
        {
            if(target < matrix[i][j]) i--;
            else if(target > matrix[i][j]) j++;
            else return true;
        }
        
        return false;
    }
};