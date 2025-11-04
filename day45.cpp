#include <bits/stdc++.h>
using namespace std;

// ---------- Function 1: Next Greater Element II ----------
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st; // store indices

    for (int i = 0; i < 2 * n; i++) {
        int num = nums[i % n];
        while (!st.empty() && nums[st.top()] < num) {
            res[st.top()] = num;
            st.pop();
        }
        if (i < n) st.push(i);
    }
    return res;
}

// ---------- Function 2: Trapping Rain Water ----------
int trapRainWater(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;
    
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax - height[left];
            left++;
        } else {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];
            right--;
        }
    }
    return water;
}

// ---------- Main Function ----------
int main() {
    cout << "==== Next Greater Element II ====\n";
    vector<int> nums = {1, 2, 1};
    vector<int> nge = nextGreaterElements(nums);
    
    cout << "Input: ";
    for (int x : nums) cout << x << " ";
    cout << "\nOutput: ";
    for (int x : nge) cout << x << " ";
    cout << "\n\n";
    
    cout << "==== Trapping Rain Water ====\n";
    vector<int> height = {4, 2, 0, 3, 2, 5};
    int trapped = trapRainWater(height);
    
    cout << "Heights: ";
    for (int h : height) cout << h << " ";
    cout << "\nTrapped Water: " << trapped << " units\n";
    
    return 0;
}
