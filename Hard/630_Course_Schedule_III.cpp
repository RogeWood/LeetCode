class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

    int scheduleCourse(vector<vector<int>>& courses) {

        // 排序期限由小到大
        sort(courses.begin(), courses.end(), compare);

        // 加入的最大天數
        priority_queue<int> que;
        int days = 0, count = 0;

        for(int i = 0; i < courses.size(); i++)
        {
            days += courses[i][0];
            que.push(courses[i][0]);
            count++;

            // 如果時間超過，排除之前最大的
            if(days > courses[i][1])
            {
                days -= que.top();
                count--;
                que.pop();
            }
        }

        return count;
    }
};
