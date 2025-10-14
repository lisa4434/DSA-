#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* ============================================================
   1️⃣ KADANE'S ALGORITHM – Maximum Subarray Sum
   ============================================================
   Idea: Keep track of the current subarray sum. 
         If current_sum < 0, reset it to 0.
   Time Complexity:  O(n)
   Space Complexity: O(1)
*/
int maxSubarraySum(vector<int> &arr) {
    int max_sum = arr[0];
    int current_sum = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        current_sum = max(arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

/* ============================================================
   2️⃣ BUY AND SELL STOCK – Single Transaction
   ============================================================
   Idea: Track the minimum price and calculate profit 
         if sold today. Update max profit accordingly.
   Time Complexity:  O(n)
   Space Complexity: O(1)
*/
int maxProfit(vector<int> &prices) {
    int min_price = prices[0];
    int max_profit = 0;

    for (int i = 1; i < prices.size(); i++) {
        max_profit = max(max_profit, prices[i] - min_price);
        min_price = min(min_price, prices[i]);
    }

    return max_profit;
}

/* ============================================================
   3️⃣ CONTAINER WITH MOST WATER
   ============================================================
   Idea: Use two pointers — one at start, one at end.
         Calculate area = min(height[left], height[right]) * width.
         Move the pointer pointing to smaller height.
   Time Complexity:  O(n)
   Space Complexity: O(1)
*/
int maxArea(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int max_water = 0;

    while (left < right) {
        int width = right - left;
        int current_water = min(height[left], height[right]) * width;
        max_water = max(max_water, current_water);

        // Move pointer of smaller height inward
        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return max_water;
}

/* ============================================================
   MAIN FUNCTION
   ============================================================
*/
int main() {
    cout << "===============================\n";
    cout << "  DSA ALGORITHMS IN ONE PROGRAM\n";
    cout << "===============================\n\n";

    /* --------- Kadane’s Algorithm --------- */
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "1️⃣ KADANE'S ALGORITHM:\n";
    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nMaximum Subarray Sum = " << maxSubarraySum(arr);
    cout << "\nTime: O(n), Space: O(1)\n\n";

    /* --------- Best Time to Buy & Sell Stock --------- */
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "2️⃣ BUY AND SELL STOCK (Single Transaction):\n";
    cout << "Prices: ";
    for (int p : prices) cout << p << " ";
    cout << "\nMaximum Profit = " << maxProfit(prices);
    cout << "\nTime: O(n), Space: O(1)\n\n";

    /* --------- Container With Most Water --------- */
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "3️⃣ CONTAINER WITH MOST WATER:\n";
    cout << "Heights: ";
    for (int h : height) cout << h << " ";
    cout << "\nMaximum Water Area = " << maxArea(height);
    cout << "\nTime: O(n), Space: O(1)\n\n";

    cout << "===============================\n";
    cout << "   PROGRAM EXECUTED SUCCESSFULLY\n";
    cout << "===============================\n";

    return 0;
}
