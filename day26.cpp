#include <bits/stdc++.h>
using namespace std;

/* ================================
   1. Search in Rotated Sorted Array
   ================================ */
int searchInRotatedArray(vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) return mid;

        // Left half sorted
        if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half sorted
        else {
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1; // Not found
}

/* ================================
   2. Peak Index in Mountain Array
   ================================ */
int peakIndexInMountainArray(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < arr[mid + 1])
            low = mid + 1; // Peak lies on right side
        else
            high = mid; // Peak lies on left side
    }
    return low; // Peak index
}

/* ================================
   3. Single Element in Sorted Array
   ================================ */
int singleNonDuplicate(vector<int> &nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (mid % 2 == 1) mid--; // make mid even for pair checking
        if (nums[mid] == nums[mid + 1])
            low = mid + 2;
        else
            high = mid;
    }
    return nums[low];
}

/* ================================
   Driver Code
   ================================ */
int main() {
    cout << "===== DSA Binary Search Problems =====" << endl;

    // 1️⃣ Search in Rotated Sorted Array
    vector<int> rotated = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << "\n1. Search in Rotated Sorted Array:" << endl;
    cout << "Array: ";
    for (int i : rotated) cout << i << " ";
    cout << "\nTarget = " << target << endl;
    int idx = searchInRotatedArray(rotated, target);
    cout << "Found at Index: " << idx << endl;

    // 2️⃣ Peak Index in Mountain Array
    vector<int> mountain = {1, 3, 5, 7, 6, 4, 2};
    cout << "\n2. Peak Index in Mountain Array:" << endl;
    cout << "Array: ";
    for (int i : mountain) cout << i << " ";
    cout << "\nPeak Index = " << peakIndexInMountainArray(mountain) << endl;

    // 3️⃣ Single Element in Sorted Array
    vector<int> single = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    cout << "\n3. Single Element in Sorted Array:" << endl;
    cout << "Array: ";
    for (int i : single) cout << i << " ";
    cout << "\nSingle Element = " << singleNonDuplicate(single) << endl;

    cout << "\n===== END OF PROGRAM =====" << endl;
    return 0;
}
