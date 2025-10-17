#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
  This single C++ file contains implementations for three classic binary-search-on-answer DSA problems:
  1) Book Allocation (minimum maximum pages)
  2) Painter's Partition (minimum time to paint all boards with k painters; similar to book allocation)
  3) Aggressive Cows (maximize minimum distance)

  Each problem has:
    - a helper 'can' predicate used by binary search
    - a function that returns the optimal answer
    - complexity: O(n * log(sum_or_range)) where n is array size

  Example usage (uncomment main() parts or use the interactive menu at the bottom):

  Input formats used in the sample demonstrations below are also described.
*/

// ---------- 1) Book Allocation Problem ----------
// Given array `pages[]` of n books (pages[i] pages in i-th book) and m students,
// allocate consecutive books to each student so that the maximum pages assigned to a student is minimized.

bool canAllocateBooks(const vector<ll>& pages, int students, ll maxAllowed) {
    int used = 1;
    ll current = 0;
    for (ll p : pages) {
        if (p > maxAllowed) return false; // single book exceeds limit
        if (current + p <= maxAllowed) {
            current += p;
        } else {
            used++;
            current = p;
            if (used > students) return false;
        }
    }
    return true;
}

ll bookAllocation(const vector<ll>& pages, int students) {
    ll low = *max_element(pages.begin(), pages.end());
    ll high = 0;
    for (ll x : pages) high += x;
    ll ans = high;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (canAllocateBooks(pages, students, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// ---------- 2) Painter's Partition Problem ----------
// Given array `boards[]` of lengths and k painters; each painter paints contiguous boards and takes `timePerUnit` time per unit length.
// Find minimum time to paint all boards.
// This is equivalent to Book Allocation but multiply pages/length by timePer-unit.

bool canPaint(const vector<ll>& boards, int painters, ll maxTime, ll timePerUnit) {
    int used = 1;
    ll current = 0;
    for (ll b : boards) {
        ll need = b * timePerUnit;
        if (need > maxTime) return false;
        if (current + need <= maxTime) {
            current += need;
        } else {
            used++;
            current = need;
            if (used > painters) return false;
        }
    }
    return true;
}

ll paintersPartition(const vector<ll>& boards, int painters, ll timePerUnit) {
    ll low = 0, high = 0;
    for (ll b : boards) {
        low = max(low, b * timePerUnit);
        high += b * timePerUnit;
    }
    ll ans = high;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (canPaint(boards, painters, mid, timePerUnit)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// ---------- 3) Aggressive Cows Problem ----------
// Given positions of stalls, place `cows` cows in stalls so that the minimum distance between any two cows is maximized.

bool canPlaceCows(const vector<ll>& stalls, int cows, ll minDist) {
    int count = 1;
    ll lastPos = stalls[0];
    for (size_t i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
            if (count >= cows) return true;
        }
    }
    return false;
}

ll aggressiveCows(vector<ll> stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    ll low = 0;
    ll high = stalls.back() - stalls.front();
    ll ans = 0;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (canPlaceCows(stalls, cows, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

// ----------------- Utility / Demo -----------------

void demo_bookAllocation() {
    cout << "Demo - Book Allocation\n";
    vector<ll> pages = {100, 200, 300, 400};
    int students = 2;
    cout << "Pages: "; for (auto x: pages) cout << x << ' '; cout << '\n';
    cout << "Students: " << students << '\n';
    cout << "Minimized maximum pages = " << bookAllocation(pages, students) << '\n';
    // Expected: 600 (partition after second book -> [100,200,300] and [400])
}

void demo_paintersPartition() {
    cout << "\nDemo - Painter's Partition\n";
    vector<ll> boards = {10, 20, 30, 40};
    int painters = 2;
    ll timePerUnit = 1; // change as needed
    cout << "Boards: "; for (auto x: boards) cout << x << ' '; cout << '\n';
    cout << "Painters: " << painters << ", time/unit=" << timePerUnit << '\n';
    cout << "Minimum time = " << paintersPartition(boards, painters, timePerUnit) << '\n';
    // With timePerUnit = 1 expected: 60 (split [10,20,30] and [40]) -> painter with [10,20,30]=60
}

void demo_aggressiveCows() {
    cout << "\nDemo - Aggressive Cows\n";
    vector<ll> stalls = {1, 2, 4, 8, 9};
    int cows = 3;
    cout << "Stalls: "; for (auto x: stalls) cout << x << ' '; cout << "\nCows: " << cows << '\n';
    cout << "Maximum minimum distance = " << aggressiveCows(stalls, cows) << '\n';
    // Expected: 3 (place at 1,4,8 or 1,4,9)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "C++ DSA - All in one: Book Allocation, Painter Partition, Aggressive Cows\n";
    cout << "Choose demo to run (1=Book, 2=Painter, 3=Aggressive, 4=All): ";
    int choice; if (!(cin >> choice)) return 0;
    if (choice == 1) demo_bookAllocation();
    else if (choice == 2) demo_paintersPartition();
    else if (choice == 3) demo_aggressiveCows();
    else if (choice == 4) { demo_bookAllocation(); demo_paintersPartition(); demo_aggressiveCows(); }
    else cout << "Invalid choice\n";

    return 0;
}
