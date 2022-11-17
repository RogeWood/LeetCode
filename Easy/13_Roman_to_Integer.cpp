class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        int len = s.length(), n = 0;
        for(int i = 0; i < len; i++)
        {
            if(mp[s[i]] >= mp[s[i+1]]) n += mp[s[i]];
            else n -= mp[s[i]];
        }
        return n;
    }
};