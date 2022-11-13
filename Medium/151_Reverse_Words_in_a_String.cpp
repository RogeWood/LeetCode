class Solution {
public:
    string reverseWords(string s) {
        int len = s.length(), start = 0;
        bool isWord = false;
        string ans = "";
        for(int i = len-1; i >= 0; i--)
        {
            if(s[i] != ' ')
            {
                if(!isWord)
                {
                    ans += " ";
                    isWord = true;
                    start = i;
                }
            }
            else if(isWord)
            {
                isWord = false;
                ans += s.substr(i+1, start-i);
            }
        }
        if(isWord) ans += s.substr(0, start+1);
        return ans.substr(1);
    }
};