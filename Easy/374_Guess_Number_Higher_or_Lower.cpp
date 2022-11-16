class Solution {
public:
    int guessNumber(int n) {
        if(!guess(n)) return n;
        int start = 0;
        while(start < n)
        {
            int middle = start/2 + n/2 + (start%2&&n%2);
            cout << middle << endl;
            if(!guess(middle)) return middle;
            if(guess(middle) == -1) n = middle;
            else start = middle+1;
        }
        return -1;
    }
};