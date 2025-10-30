#include <bits/stdc++.h>
using namespace std;

// Function to check if parentheses are valid
bool isValidParenthesis(const string &s) {
    stack<char> st;

    for (char ch : s) {
        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // If closing bracket, check top of stack
        else {
            if (st.empty()) return false; // No opening bracket available

            char top = st.top();
            st.pop();

            // Check for matching pair
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // Valid if stack is empty at the end
    return st.empty();
}

int main() {
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;

    if (isValidParenthesis(s))
        cout << "Valid Parentheses ✅" << endl;
    else
        cout << "Invalid Parentheses ❌" << endl;

    return 0;
}
