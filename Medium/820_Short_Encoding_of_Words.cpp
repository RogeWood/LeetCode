class Solution {
public:
    // 長度大的牌前面
    static bool compare (string& a, string& b) {
        return a.size() > b.size();
    }

    int minimumLengthEncoding(vector<string>& words) {
        // 字串的集合
        unordered_map<string, int> mp;

        // 排序
        sort(words.begin(), words.end(), compare);

        // 紀錄出現過的字串
        for(int i = 0; i < words.size(); i++)
            mp[words[i]]++;

        int ans = 0;
        // 從長的計算總長度
        for(int i = 0; i < words.size(); i++)
        {
            if(mp[words[i]])
                ans += words[i].length() + 1;

            // 將出擁有的子字串歸零
            for(int j = words[i].length(); j >= 0; j--)
            {
                mp[words[i].substr(j, words[i].length()-j)] = 0;
            }
        }
        return ans;
    }
};
