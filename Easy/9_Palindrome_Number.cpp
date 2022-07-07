class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false; // 負數回傳 false
        // 將數字倒過來
        unsigned int a = 0, b = x;
        while(b)
        {
            a = a*10;
            a += b%10;
            b /= 10;
        }
        return a == x;
    }
};