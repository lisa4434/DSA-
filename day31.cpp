#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Function for 2 Sum
vector<vector<int>> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    vector<vector<int>> result;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (map.find(complement) != map.end()) {
            result.push_back({complement, nums[i]});
        }
        map[nums[i]] = i;
    }

    return result;
}

// Function for 3 Sum
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates

        int left = i + 1, right = nums.size() - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++; right--;
            }
            else if (sum < 0) left++;
            else right--;
        }
    }

    return result;
}

// Function for 4 Sum
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int n = nums.size();

    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates
        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int left = j + 1, right = n - 1;

            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++; right--;
                }
                else if (sum < target) left++;
                else right--;
            }
        }
    }

    return result;
}

// Utility to print results
void printResult(const vector<vector<int>>& result) {
    for (const auto& vec : result) {
        cout << "[ ";
        for (int num : vec)
            cout << num << " ";
        cout << "]\n";
    }
}

// Driver code
int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target2 = 0;
    int target4 = 0;

    cout << "=== 2 SUM ===\n";
    printResult(twoSum(nums, target2));

    cout << "\n=== 3 SUM (Target = 0) ===\n";
    printResult(threeSum(nums));

    cout << "\n=== 4 SUM ===\n";
    printResult(fourSum(nums, target4));

    return 0;
}
