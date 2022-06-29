class Solution {
public:

    static bool compare(vector<int> &a, vector<int> &b)
    { // 1.如果前面的人數相同，將高度高的排前面 2.前面人數小的排前面
        return (a[1] == b[1]) ? a[0] > b[0] : a[1] < b[1];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compare);

        vector<vector<int>> ans;
        for(int i = 0; i < people.size(); i++)
        {
            int k = 0;
            // 計算要插入哪個 index
            for(int count = 0; k < ans.size() && count < people[i][1]; k++)
                if(ans[k][0] >= people[i][0])
                    count++;

            ans.insert(ans.begin() + k, people[i]);
        }
        return ans;
    }
};
