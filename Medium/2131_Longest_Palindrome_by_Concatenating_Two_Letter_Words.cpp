class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int countAlpha[26][26] = {0};
        int len = words.size(), ans = 0;
        for(string s:words)
        {
            int a = s[0] - 'a', b = s[1] - 'a';
            if(countAlpha[b][a]) // 反過來有出現過
            {
                ans += 4; // ab ba 或 aa aa長度加上 4
                countAlpha[b][a]--; // 找到對應的後減一
            }
            else countAlpha[a][b]++; // 沒出現過則記錄下來
        }

        // 處理兩個相同字元且只有一組(aa, gg)
        for(int i = 0; i < 26; i++)
            if(countAlpha[i][i])
            {
                ans += 2;
                break;
            }

        return ans;
    }
};
