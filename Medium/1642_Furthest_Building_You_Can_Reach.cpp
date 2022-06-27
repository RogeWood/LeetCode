class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> maxBrick; // 用過最多磚塊的數量
        int i; // index

        for(i = 0; i < heights.size()-1; i++)
        {
            int distants = heights[i+1] - heights[i];

            if(distants < 0) // 矮房子直接過
                continue;

            bricks -= distants; //直接用磚塊
            maxBrick.push(distants);

            if(bricks < 0) // 磚塊不夠把前面用最多的拿出來改梯子
            {
                bricks += maxBrick.top();
                maxBrick.pop();
                ladders--;
            }

            if(ladders < 0) // 連梯子都不構就不能過了
                break;
        }
        return i;
    }
};
