// Maximum Subarray Sum – Kadane’s Algorithm
// Concept:
// We want the contiguous subarray with the maximum sum.
// Keep track of current_sum as we traverse.
// If current_sum becomes negative, reset it to 0.
// Keep a max_sum to store the maximum sum seen so far.

#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int> &arr) {
    int max_sum = arr[0]; // max sum so far
    int current_sum = arr[0]; // current subarray sum

    for(int i = 1; i < arr.size(); i++) {
        current_sum = max(arr[i], current_sum + arr[i]); // either start new subarray or extend
        max_sum = max(max_sum, current_sum); // update max sum
    }

    return max_sum;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubarraySum(arr) << endl;
    return 0;
}


// Majority Element – Moore’s Voting Algorithm
// Concept:
// A majority element appears more than n/2 times in an array.
// Maintain a candidate and a count.
// If count is 0 → choose current element as candidate.
// If current element == candidate → increment count, else decrement count.
// After one pass, candidate may be majority → verify in second pass.
#include <iostream>
#include <vector>
using namespace std;

int findMajorityElement(vector<int> &arr) {
    int count = 0;
    int candidate = -1;

    // 1st pass: find candidate
    for(int num : arr) {
        if(count == 0) {
            candidate = num;
            count = 1;
        } else if(num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // 2nd pass: verify candidate
    count = 0;
    for(int num : arr) {
        if(num == candidate) count++;
    }

    if(count > arr.size()/2) return candidate;
    else return -1; // no majority element
}

int main() {
    vector<int> arr = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int majority = findMajorityElement(arr);
    if(majority != -1)
        cout << "Majority Element: " << majority << endl;
    else
        cout << "No Majority Element" << endl;
    return 0;
}
