class Solution {
public:
    bool isVowels(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        stack<char> vowels;
        int len = s.length();
        int i = 0, j = len - 1;
        while(i < j)
        {
            if(!isVowels(s[i])) i++;
            else if(!isVowels(s[j])) j--;
            else if(isVowels(s[i]) && isVowels(s[j]))
            {
                swap(s[i], s[j]);
                i++, j--;
            }
        }
        
        return s;
    }
};