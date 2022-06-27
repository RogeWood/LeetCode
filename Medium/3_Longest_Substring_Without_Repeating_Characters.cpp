class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool alpha[300] = {0}; // 出現過的字母

        int head = 0, end = 0; // 連續子字串頭尾 index
        int maxn = 0; // 最大長度

        for(end = 0; end < s.length();end++)
        {
            if(alpha[s[end]])// 如果重複出現過
            {
                // 紀錄最大值
                if(maxn < end - head)
                    maxn = end - head;

                // 將頭的 index 指到重覆字元的下一個
                for(;s[head] != s[end]; head++)
                    alpha[s[head]] = 0;
                head++;
            }
            alpha[s[end]] = 1;
        }

        // 全部都沒重複
        return (maxn < end - head) ? end - head : maxn;
    }
};
