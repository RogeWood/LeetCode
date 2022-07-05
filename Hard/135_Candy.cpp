// Solution 1
class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        if(len == 1) return 1; // 只有一個元素
        
        vector<int> cookies(len, 1); // 儲存每個人的餅乾數量
        queue<int> que; // 儲存 rating 優先度(小的在前面)
        
        // 先找出最小的位置當出發點 儲存起來
        if(ratings[0] <= ratings[1]) que.push(0);
        if(ratings[len-1] <= ratings[len-2]) que.push(len-1);
        for(int i = 1; i < len-1; i++)
            if(ratings[i] <= ratings[i-1] && ratings[i] <= ratings[i+1])
                que.push(i);
        
        // 往外擴展到全部都走過
        while(que.size())
        {
            int i = que.front();
            if(i-1 >= 0 && ratings[i-1] > ratings[i])
            {
                cookies[i-1] = max(cookies[i-1], cookies[i]+1);
                que.push(i-1);
            }
            if(i+1 < len && ratings[i+1] > ratings[i])
            {
                cookies[i+1] = max(cookies[i+1], cookies[i]+1);
                que.push(i+1);
            }
            que.pop();
        }
        
        return accumulate(cookies.begin(), cookies.end(), 0); // 所有人的餅乾總和
    }
};

// Solution 2 link : https://leetcode.com/problems/candy/discuss/2234774/C%2B%2B-USING-TWO-ARRAYS-oror-EASY-TO-UNDERSTAND-WITH-COMMENTS
class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0, n= ratings.size();
        
        // 先判斷左邊，需大於的+1
        vector<int>L_candy(n,1);
        for(int i=1; i<n; i++){
            if(ratings[i]>ratings[i-1] )
                L_candy[i]=L_candy[i-1]+1;
        }
        
        // 後判斷右邊，需大於+1
        vector<int> R_candy(n,1);
        for(int i=n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1] )
                R_candy[i] = R_candy[i+1]+1;
        }
        
        // 從左右兩邊取出最大值，最後合起來 
        for(int i=0; i<n; i++){
            ans += max(L_candy[i], R_candy[i]);
        }
        return ans;
    }
};