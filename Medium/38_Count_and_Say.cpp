class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string s = countAndSay(n-1);
        int count = 1, i = 0;
        string ans = "";
        while(s[i] != '\0')
        {
            if(s[i] != s[i+1])
            {
                ans += (char)(count + '0');
                ans += s[i];
                count = 0;
            }
            count++;
            i++;
        }
        return ans;
    }
};