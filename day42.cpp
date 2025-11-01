#include <bits/stdc++.h>
using namespace std;

// Function to find Next Greater Element for each element
vector<int> nextGreaterElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> st; // store indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            nge[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return nge;
}

// Function to find Previous Smaller Element for each element
vector<int> previousSmallerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> pse(n, -1);
    stack<int> st; // store indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        if (!st.empty())
            pse[i] = arr[st.top()];

        st.push(i);
    }

    return pse;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    int n = arr.size();

    vector<int> nge = nextGreaterElement(arr);
    vector<int> pse = previousSmallerElement(arr);

    cout << "Element\tPrevSmaller\tNextGreater\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
        if (pse[i] == -1) cout << "-\t\t";
        else cout << pse[i] << "\t\t";

        if (nge[i] == -1) cout << "-";
        else cout << nge[i];
        cout << "\n";
    }

    return 0;
}
