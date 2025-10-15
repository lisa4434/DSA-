#include <bits/stdc++.h>
using namespace std;

/*
  Product of array except self (no division), using pointers.
  Input: int* arr, int n
  Output: long long* out (must be preallocated with size n)
  Complexity: O(n) time, O(n) extra space (for output and right product step).
*/
void productExceptSelf(const int* arr, int n, long long* out) {
    if (n <= 0) return;

    // Step 1: left products in out (out[i] = product of arr[0..i-1])
    long long leftProd = 1;
    for (int i = 0; i < n; ++i) {
        out[i] = leftProd;
        leftProd *= arr[i];
    }

    // Step 2: multiply by right products in a single pass from right
    long long rightProd = 1;
    for (int i = n - 1; i >= 0; --i) {
        out[i] = out[i] * rightProd;
        rightProd *= arr[i];
    }
}

/*
  Binary search using pointers.
  Returns index (0-based) if found, otherwise -1.
  Works on sorted array in non-decreasing order.
  Complexity: O(log n)
*/
int binarySearchPtr(const int* arr, int n, int key) {
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int midVal = *(arr + mid); // pointer-style access
        if (midVal == key) return mid;
        if (midVal < key) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// small helper to print arrays using pointer iteration
void printLongLongArray(const long long* a, int n) {
    const long long* p = a;
    for (int i = 0; i < n; ++i, ++p) {
        cout << *p;
        if (i + 1 < n) cout << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // READ: First a generic array for product-except-self
    // Input format example:
    // n
    // a1 a2 ... an
    // Then for binary search:
    // m (size of sorted array)
    // b1 b2 ... bm
    // q (number of queries)
    // q keys (one per line or space separated)
    //
    // Example input (user-friendly):
    // 5
    // 1 2 3 4 5
    // 5
    // 1 2 3 4 5
    // 3
    // 3 6 1

    cout << "Enter n (size for product-except-self) and the n integers:\n";
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    // allocate output using new to illustrate pointer usage, then free
    long long* out = new long long[n];
    productExceptSelf(arr.data(), n, out);

    cout << "\nProduct of array except self:\n";
    printLongLongArray(out, n);

    // free and demonstrate another pointer usage (but keep safe)
    delete[] out;
    out = nullptr;

    // Now binary search demonstration
    cout << "\nEnter m (size of sorted array for binary search) and the m sorted integers:\n";
    int m;
    cin >> m;
    vector<int> sortedArr(m);
    for (int i = 0; i < m; ++i) cin >> sortedArr[i];

    cout << "Enter q (number of search queries) followed by q keys:\n";
    int q;
    cin >> q;
    for (int qi = 0; qi < q; ++qi) {
        int key;
        cin >> key;
        int idx = binarySearchPtr(sortedArr.data(), m, key);
        if (idx >= 0) {
            cout << "Found " << key << " at index " << idx << " (0-based).\n";
        } else {
            cout << key << " not found in the array.\n";
        }
    }

    // Short pointer example: swap using pointers
    cout << "\nPointer swap example (2 numbers). Enter two integers:\n";
    int x, y;
    cin >> x >> y;
    cout << "Before swap: x = " << x << ", y = " << y << "\n";
    int* px = &x;
    int* py = &y;
    // swap via pointers
    int tmp = *px;
    *px = *py;
    *py = tmp;
    cout << "After swap (via pointers): x = " << x << ", y = " << y << "\n";

    return 0;
}
