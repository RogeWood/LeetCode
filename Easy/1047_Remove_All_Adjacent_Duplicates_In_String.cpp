
// Solution 1:
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            if(!st.empty() && st.top() == s[i]) st.pop();
            else st.push(s[i]);
        }
        string ans = "";
        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

// Solution 2:
class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(ans.size() && ans.back() == s[i]) ans.pop_back();
            else ans.push_back(s[i]);
        }
        return ans;
    }
};