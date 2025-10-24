#include <bits/stdc++.h>
using namespace std;

/* =========================================================
   1️⃣  Combination Sum (Backtracking)
   ========================================================= */
void combinationSumHelper(int i, vector<int>& candidates, int target, 
                          vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    if (i == candidates.size() || target < 0)
        return;

    // Pick element
    current.push_back(candidates[i]);
    combinationSumHelper(i, candidates, target - candidates[i], current, result);
    current.pop_back();

    // Skip element
    combinationSumHelper(i + 1, candidates, target, current, result);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    combinationSumHelper(0, candidates, target, current, result);
    return result;
}

/* =========================================================
   2️⃣  Palindrome Partitioning (Backtracking)
   ========================================================= */
bool isPalindrome(const string& s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}

void partitionHelper(int index, const string& s, vector<string>& path, vector<vector<string>>& result) {
    if (index == s.size()) {
        result.push_back(path);
        return;
    }

    for (int i = index; i < s.size(); i++) {
        if (isPalindrome(s, index, i)) {
            path.push_back(s.substr(index, i - index + 1));
            partitionHelper(i + 1, s, path, result);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> path;
    partitionHelper(0, s, path, result);
    return result;
}

/* =========================================================
   3️⃣  Merge Sort (Divide & Conquer)
   ========================================================= */
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

/* =========================================================
   📜 Main Menu-driven Program
   ========================================================= */
int main() {
    int choice;
    cout << "==== DSA Algorithm Menu ====\n";
    cout << "1. Combination Sum\n";
    cout << "2. Palindrome Partitioning\n";
    cout << "3. Merge Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        int n, target;
        cout << "Enter number of elements: ";
        cin >> n;
        vector<int> candidates(n);
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) cin >> candidates[i];
        cout << "Enter target sum: ";
        cin >> target;

        vector<vector<int>> result = combinationSum(candidates, target);
        cout << "\nCombinations that sum to " << target << ":\n";
        for (auto& comb : result) {
            cout << "[ ";
            for (int num : comb) cout << num << " ";
            cout << "]\n";
        }
        break;
    }

    case 2: {
        string s;
        cout << "Enter a string: ";
        cin >> s;
        vector<vector<string>> result = partition(s);
        cout << "\nAll Palindromic Partitions:\n";
        for (auto& part : result) {
            cout << "[ ";
            for (auto& str : part) cout << str << " ";
            cout << "]\n";
        }
        break;
    }

    case 3: {
        int n;
        cout << "Enter number of elements: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) cin >> arr[i];

        mergeSort(arr, 0, n - 1);

        cout << "\nSorted array:\n";
        for (int x : arr) cout << x << " ";
        cout << endl;
        break;
    }

    default:
        cout << "Invalid choice!\n";
        break;
    }

    return 0;
}