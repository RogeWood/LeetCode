class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last = digits.size()-1;
        digits[last]++; // 數字 +1
        if(digits[last] < 10) return digits;
        
        for(int i = last; i > 0; i--)
        {
            if(digits[i] < 10) break; // 不需要進位為止
            
            digits[i] %= 10;
            digits[i-1]++;
        }
        
        if(digits[0] > 9) // 檢查最大位數
        {
            digits[0] %= 10;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};