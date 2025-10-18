#include <bits/stdc++.h>
using namespace std;

/* ------------------------- 1. BASIC SORTING -------------------------
   Sorting rearranges elements of an array in increasing/decreasing order.
   Common algorithms: Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort.
   STL: sort(arr.begin(), arr.end());
--------------------------------------------------------------------- */
void basicSortDemo() {
    vector<int> arr = {5, 1, 4, 2, 8};
    cout << "\nOriginal Array: ";
    for (int x : arr) cout << x << " ";

    sort(arr.begin(), arr.end()); // STL sort (QuickSort / IntroSort)
    cout << "\nSorted Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}

/* ------------------ 2. SORT ARRAY OF 0s, 1s, 2s --------------------
   Problem: Sort array containing only 0, 1, 2 without using extra space.
   Approach: Dutch National Flag Algorithm (3 pointers)
   Time: O(n), Space: O(1)
--------------------------------------------------------------------- */
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0)
            swap(nums[low++], nums[mid++]);
        else if (nums[mid] == 1)
            mid++;
        else
            swap(nums[mid], nums[high--]);
    }
}

void sortColorsDemo() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    cout << "\nOriginal 0s,1s,2s Array: ";
    for (int x : nums) cout << x << " ";

    sortColors(nums);

    cout << "\nSorted 0s,1s,2s Array:   ";
    for (int x : nums) cout << x << " ";
    cout << endl;
}

/* ------------------ 3. MERGE TWO SORTED ARRAYS ---------------------
   Problem: Merge two sorted arrays into one sorted array.
   Approaches:
   - Simple: Use extra space (O(n+m))
   - Optimal (in-place): Gap method / Two-pointer technique
   STL: merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
--------------------------------------------------------------------- */
void mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size(), m = arr2.size();
    int i = n - 1, j = 0;

    // Swap elements if arr1[i] > arr2[j]
    while (i >= 0 && j < m) {
        if (arr1[i] > arr2[j])
            swap(arr1[i], arr2[j]);
        i--;
        j++;
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

void mergeSortedArraysDemo() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};

    cout << "\nBefore Merging:\narr1: ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2: ";
    for (int x : arr2) cout << x << " ";

    mergeSortedArrays(arr1, arr2);

    cout << "\n\nAfter Merging (In-place):\narr1: ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
}

/* ---------------------- 4. NEXT PERMUTATION -------------------------
   Problem: Rearrange numbers into the lexicographically next greater permutation.
   Approach:
   - Find first decreasing element from right.
   - Swap with just greater element on right.
   - Reverse remaining right part.
   STL: next_permutation(arr.begin(), arr.end());
--------------------------------------------------------------------- */
void nextPermutationDemo() {
    vector<int> nums = {1, 2, 3};
    cout << "\nOriginal: ";
    for (int x : nums) cout << x << " ";

    next_permutation(nums.begin(), nums.end()); // STL function

    cout << "\nNext Permutation: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
}

/* ---------------------- MAIN DRIVER FUNCTION ----------------------- */
int main() {
    cout << "===== C++ DSA All-in-One: Sorting, Merge, Next Permutation =====\n";

    basicSortDemo();
    sortColorsDemo();
    mergeSortedArraysDemo();
    nextPermutationDemo();

    cout << "\n===============================================================\n";
    return 0;
}
