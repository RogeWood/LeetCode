class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        int len = s.length();
        for(int i = 0; i < len; i++) // 改第一個遇到的 6 為 9
            if(s[i] == '6')
            {
                s[i] = '9';
                break;
            }
        return stoi(s);
    }
};