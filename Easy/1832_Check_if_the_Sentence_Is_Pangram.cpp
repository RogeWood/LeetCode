// Solution 1

class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool isappear[26] = {false};
        int len = sentence.length();
        for(int i = 0; i < len; i++) isappear[sentence[i] - 'a'] = true;
        for(int i = 0; i < 26; i++)
            if(!isappear[i]) return false;
        return true;
    }
};

//Solution 2
//https://leetcode.com/problems/check-if-the-sentence-is-pangram/solutions/2711868/all-languages-only-1-line/
class Solution {
public:
    bool checkIfPangram(string sentence) {
        return unordered_set<char>(sentence.begin(), sentence.end()).size() == 26;
    }
};