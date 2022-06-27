int next_n(int n) // 計算下一個數字
{
    int r = 0;
    while(n != 0)
    {
        int d = n%10;
        r += d*d;
        n /= 10;
    }
    return r;
}

bool contains(int* history, int size, int n) // 檢查數字是否出現過
{
    for(int i=0; i < size; i++)
        if(history[i] == n) return true;
    return false;
}
bool isHappy(int n){

    int history[100000];
    int size = 0;

    n = next_n(n);

    while(!contains(history, size, n)) // 當數字沒出現過，持續計算
    {
        history[size] = n;
        size++;

        n = next_n(n);
    }

    return n == 1;
}
