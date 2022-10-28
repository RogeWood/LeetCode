class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        int len = strs.size();
        for(int i = 0; i < len; i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto i : mp)
            ans.push_back(i.second);

        return ans;
    }
};