class Solution {
public:
    int lengthOfLastWord(string s) {
        int start = 0, end = 0, len = s.length(), isWord = false;
        for(int i = 0; i < len; i++)
        {
            if(isalpha(s[i]))
            {
                if(isWord) end++;
                else
                {
                    isWord = true;
                    start = i;
                    end = i;
                }
            }
            else isWord = false;
        }
        return end - start + 1;
    }
};