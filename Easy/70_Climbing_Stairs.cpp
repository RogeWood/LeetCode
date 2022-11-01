class Solution {
public:
    int climbStairs(int n) {
        static vector<int> steps(46, 0);
        if(steps[n] != 0) return steps[n];
        if(n <= 1) return 1;
        steps[n] = climbStairs(n-1) + climbStairs(n-2);
        return steps[n];
    }
};