class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare); // 用權重排序

        int sum = 0;
        for(int i = 0; i < boxTypes.size(); i++)
        {
            if(boxTypes[i][0] >= truckSize) // 擁有數量大於等於剩下空間
            {
                sum += boxTypes[i][1] * truckSize;
                break;
            }
            else
            {
                sum += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
        }

        return sum;
    }
};
