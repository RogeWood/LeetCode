class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) // 找到輪轉中最小的子字串
        {
            string alls = s+s;
            int len = s.length();
            for(int i = 0; i < len; i++)
                s = min(s, alls.substr(i, len));
        }
        else sort(s.begin(), s.end()); // k > 1 的 s 皆為完整排序的值(可以輪轉全部或只輪轉第一個以外的字串，這樣一定能找到完整排序後的字串)
        return s;   
    }
};