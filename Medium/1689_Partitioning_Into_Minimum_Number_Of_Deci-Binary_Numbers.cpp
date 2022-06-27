class Solution {
public:
    int minPartitions(string n) {
        int num = 0;
        for(int i = 0; i < n.length(); i++)
            if(num < n[i]-'0') num = n[i]-'0';
        return num;
    }
};
