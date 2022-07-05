class Solution {
public:
    int reverse(int x) {
        long long int a = 0;
        while(x)
        {
            a = a*10 + x % 10;
            x /= 10;
            if(a > INT_MAX || a < INT_MIN) return 0; // 超過 int 範圍，回傳 0
        }
        
        return (int)a;
    }
};