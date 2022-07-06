// Solution 1
class Solution {
public:
    int fib(int n) { // 遞迴法
        if(!n || n == 1) return n;
        return fib(n-1) + fib(n-2);
    }
};

// Solution 2
class Solution {
public:
    int fib(int n) {
        if(n == 1) return n;
        int ans = 0, a = 0, b = 1;
        // 遞迴 + 動態規劃，可省去重複數字運算的時間
        for(int i = 2; i <= n; i++)
        {
            int curr = a + b;
            a = b;
            b = curr;
            ans = curr;
        }
        return ans;
    }
};