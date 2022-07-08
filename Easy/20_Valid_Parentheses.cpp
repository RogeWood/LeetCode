class Solution {
public:
    bool isValid(string s) {
        stack<int> sta;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            if(s[i] == ')')
            {
                if(sta.size() && sta.top() == '(') sta.pop();
                else return false;
            }
            else if(s[i] == ']')
            {
                if(sta.size() && sta.top() == '[') sta.pop();
                else return false;
            }
            else if(s[i] == '}')
            {
                if(sta.size() && sta.top() == '{') sta.pop();
                else return false;
            }
            else sta.push(s[i]);
        }
        return !sta.size();
    }
};