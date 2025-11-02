#include <bits/stdc++.h>
using namespace std;

// ============================================================
//                    MIN STACK IMPLEMENTATION
// ============================================================

class MinStack {
private:
    stack<int> mainStack;  // Stores all values
    stack<int> minStack;   // Stores current minimums

public:
    // Constructor
    MinStack() {
        // No initialization required
    }

    // Push element onto stack
    void push(int val) {
        mainStack.push(val);
        // If minStack is empty or val <= current min, push to minStack
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    // Pop element from stack
    void pop() {
        if (mainStack.empty()) {
            cout << "Stack Underflow!\n";
            return;
        }
        int topVal = mainStack.top();
        mainStack.pop();
        // Remove from minStack if it’s the current minimum
        if (!minStack.empty() && topVal == minStack.top()) {
            minStack.pop();
        }
    }

    // Return top element
    int top() {
        if (mainStack.empty()) {
            cout << "Stack is Empty!\n";
            return -1; // Or throw exception
        }
        return mainStack.top();
    }

    // Get minimum element in O(1)
    int getMin() {
        if (minStack.empty()) {
            cout << "Stack is Empty!\n";
            return -1; // Or throw exception
        }
        return minStack.top();
    }

    // Check if empty
    bool empty() {
        return mainStack.empty();
    }

    // Get size
    int size() {
        return mainStack.size();
    }

    // Display stack (for debugging)
    void display() {
        stack<int> temp = mainStack;
        cout << "Stack (top -> bottom): ";
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

// ============================================================
//                        DRIVER CODE
// ============================================================

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    MinStack st;
    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);
    st.push(4);

    cout << "Current Stack:\n";
    st.display();

    cout << "Current Minimum: " << st.getMin() << "\n";

    st.pop();
    st.pop();

    cout << "\nAfter popping 2 elements:\n";
    st.display();
    cout << "Current Minimum: " << st.getMin() << "\n";

    st.push(1);
    cout << "\nAfter pushing 1:\n";
    st.display();
    cout << "Current Minimum: " << st.getMin() << "\n";

    return 0;
}
