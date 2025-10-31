#include <bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(vector<int>& price) {
    int n = price.size();
    vector<int> span(n);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        // Pop elements while stack not empty and current price >= top price
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();

        // If stack empty, span = i + 1, else = i - st.top()
        span[i] = (st.empty()) ? (i + 1) : (i - st.top());

        // Push current index
        st.push(i);
    }
    return span;
}

int main() {
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = calculateSpan(price);

    cout << "Stock Span values: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
