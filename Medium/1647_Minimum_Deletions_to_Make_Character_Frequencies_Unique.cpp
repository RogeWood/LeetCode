class Solution {
public:
    int minDeletions(string s) {
        int alpha[26] = {0};

        for(int i = 0; i < s.length(); i++) // 計算字母出現次數
            alpha[s[i] - 'a']++;

        sort(alpha, alpha+26, greater<int>()); // 出現次數由大到小排序

        int count = 0;
        for(int i = 1; i < 26 && alpha[i]; i++)
        {
            if(alpha[i] >= alpha[i-1]) // 如果相同或大於 將字元刪除
            {
                count += alpha[i] - alpha[i-1] + 1;
                alpha[i] = alpha[i-1] - 1;
                if(alpha[i] < 0) // 當小於0，加回為0
                {
                    count -= alpha[i]*-1;
                    alpha[i] = 0;
                }
            }
        }
        return count;
    }
};
