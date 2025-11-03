#include <bits/stdc++.h>
using namespace std;

// Function to find the largest rectangular area in a histogram
long long largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    long long maxArea = 0;
    int n = heights.size();
    
    for (int i = 0; i <= n; i++) {
        int currHeight = (i == n) ? 0 : heights[i];
        while (!st.empty() && currHeight < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, 1LL * h * width);
        }
        st.push(i);
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area = " << largestRectangleArea(heights) << endl;
    return 0;
}
