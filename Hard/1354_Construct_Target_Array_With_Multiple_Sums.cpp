class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> que(begin(target), end(target));
        long sum = accumulate(begin(target), end(target), 0LL);
        while(true)
        {
            int m = que.top();
            que.pop();
            sum -= m;
            if(m == 1) return true; // 最大數字為1
            if(sum == 1) return true; // [1, x] 的情況
            if(sum == 0 || sum >= m) return false; //[x] 或是 剩下和大於最大值
            int r = m % sum;
            if(!r) return false; // 最大為剩下的和的因數
            que.push(r);
            sum += r;
        }
        return true;
    }
};
