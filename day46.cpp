#include <bits/stdc++.h>
using namespace std;

// Function to check if person a knows person b
bool knows(vector<vector<int>>& M, int a, int b) {
    return M[a][b] == 1;
}

int findCelebrity(vector<vector<int>>& M, int n) {
    stack<int> s;

    // Step 1: Push all people into the stack
    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Step 2: Eliminate non-celebrities
    while (s.size() > 1) {
        int A = s.top(); s.pop();
        int B = s.top(); s.pop();

        if (knows(M, A, B)) {
            // A knows B, so A can't be celebrity
            s.push(B);
        } else {
            // A doesn't know B, so B can't be celebrity
            s.push(A);
        }
    }

    // Step 3: Verify the potential celebrity
    int candidate = s.top();

    // Check if candidate is a real celebrity
    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (knows(M, candidate, i) || !knows(M, i, candidate)) {
                return -1;
            }
        }
    }

    return candidate;
}

// Driver code
int main() {
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    int n = M.size();

    int celeb = findCelebrity(M, n);
    if (celeb == -1)
        cout << "No celebrity found\n";
    else
        cout << "Celebrity is person " << celeb << endl;

    return 0;
}
