#include <bits/stdc++.h>
using namespace std;

// ------------------- RECURSION BASICS -------------------

// Factorial using recursion
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// Sum of first n numbers using recursion
int sumN(int n) {
    if (n == 0) return 0;
    return n + sumN(n - 1);
}

// Fibonacci using recursion
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// ------------------- CHECK IF ARRAY IS SORTED -------------------
bool isSorted(vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

// ------------------- BINARY SEARCH -------------------
int binarySearch(vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1; // Not found
}

// ------------------- SUBARRAY SUM EQUALS K -------------------
// Using prefix sum and unordered_map (O(n) solution)
int subarraySumEqualsK(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1;
    int count = 0, sum = 0;

    for (int num : nums) {
        sum += num;
        if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
            count += prefixSumCount[sum - k];
        }
        prefixSumCount[sum]++;
    }
    return count;
}

// ------------------- MAIN FUNCTION -------------------
int main() {
    cout << "================ DSA ALL-IN-ONE PROGRAM ================\n\n";

    // 1️⃣ Recursion
    cout << "--- RECURSION ---\n";
    int n = 5;
    cout << "Factorial of " << n << " = " << factorial(n) << endl;
    cout << "Sum of first " << n << " numbers = " << sumN(n) << endl;
    cout << "Fibonacci of " << n << " = " << fibonacci(n) << endl;

    // 2️⃣ Check if array is sorted
    cout << "\n--- CHECK IF ARRAY IS SORTED ---\n";
    vector<int> arr1 = {1, 2, 3, 4, 5};
    cout << "Array: ";
    for (int x : arr1) cout << x << " ";
    cout << "\nIs array sorted? " << (isSorted(arr1, arr1.size()) ? "Yes" : "No") << endl;

    // 3️⃣ Binary Search
    cout << "\n--- BINARY SEARCH ---\n";
    vector<int> arr2 = {1, 3, 5, 7, 9, 11};
    int target = 7;
    int index = binarySearch(arr2, target);
    if (index != -1)
        cout << "Element " << target << " found at index " << index << endl;
    else
        cout << "Element " << target << " not found." << endl;

    // 4️⃣ Subarray Sum Equals K
    cout << "\n--- SUBARRAY SUM EQUALS K ---\n";
    vector<int> nums = {1, 2, 3, -1, 2};
    int k = 3;
    cout << "Array: ";
    for (int x : nums) cout << x << " ";
    cout << "\nK = " << k << endl;
    cout << "Number of subarrays with sum K = " << subarraySumEqualsK(nums, k) << endl;

    cout << "\n=========================================================\n";
    return 0;
}
