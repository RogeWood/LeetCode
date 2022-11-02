//BFS
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int bankLen = bank.size();
        unordered_set<string> dictionary;

        for(int i = 0; i < bankLen; i++) dictionary.insert(bank[i]);
        if(dictionary.find(end) == dictionary.end()) return -1; // end 沒再基因 bank 裡就結束

        char available[4] = {'A', 'C', 'G', 'T'};
        unordered_set<string> visited; // bank裡改動過的string
        int count = 0;
        queue<string> q;
        q.push(start);
        visited.insert(start);

        while(!q.empty())
        {
            int len = q.size();
            while(len--) // 擴展 同一 level 的 string
            {
                string currString = q.front();
                q.pop();

                if(currString == end) return count; // 找到end

                for(int i = 0; i < 8; i++) // 字串裡的每個基因
                {
                    char origChar = currString[i]; // 紀錄原本這個位置的基因符號

                    for(int j = 0; j < 4; j++) // 4個符號個改一次並檢查是否有在 bank 裡面
                    {
                        currString[i] = available[j];
                        if(dictionary.find(currString) != dictionary.end() && visited.find(currString) == visited.end())
                        {
                            q.push(currString);
                            visited.insert(currString);
                        }
                    }
                    currString[i] = origChar;
                }
            }
            count++;
        }
        return -1;
    }
};