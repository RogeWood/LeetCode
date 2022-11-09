class StockSpanner {
public:
    StockSpanner() {}
    
    int next(int price) {
        int span = 1;
        while(!st.empty() && price >= st.top().first) // 找到前面小於的天數
        {
            span += st.top().second;
            st.pop(); // 將小於的天數踢掉(次數記錄在目前的值)
        }
        st.emplace(price, span); // 目前的天數存到 stack 裡面
        return span;
    }
    
private:
    stack<pair<int, int>> st; // 固定的 stack
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */