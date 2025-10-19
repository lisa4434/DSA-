#include <bits/stdc++.h>
using namespace std;

// C++ Strings & Character Arrays — All-in-One
// Contains implementations and example usages for common string problems:
// 1. Working with character arrays
// 2. Valid Palindrome (ignore non-alphanumerics, case-insensitive)
// 3. Remove all occurrences (char and substring)
// 4. Generate permutations (unique)
// 5. Reverse words in a string (trim extra spaces)
// 6. String compression (basic run-length encoding)
// 7. Utility functions: reverse string/char-array, print

// ------------------------- Utilities -------------------------
void printLine() {
    cout << string(80, '-') << "\n";
}

void printExampleHeader(const string &title) {
    printLine();
    cout << "Example: " << title << "\n";
    printLine();
}

// Reverse a std::string in-place
void reverseString(string &s) {
    reverse(s.begin(), s.end());
}

// Reverse a C-style character array in-place. arr must be null-terminated.
void reverseCharArray(char *arr) {
    if (!arr) return;
    int n = strlen(arr);
    int i = 0, j = n - 1;
    while (i < j) swap(arr[i++], arr[j--]);
}

// ------------------------- 1. Valid Palindrome -------------------------
// Check if a string is a palindrome considering only alphanumeric characters
// and ignoring cases. O(n) time, O(1) extra space.
bool isValidPalindrome(const string &s) {
    int i = 0, j = (int)s.size() - 1;
    while (i < j) {
        while (i < j && !isalnum((unsigned char)s[i])) ++i;
        while (i < j && !isalnum((unsigned char)s[j])) --j;
        if (i < j) {
            if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])) return false;
            ++i; --j;
        }
    }
    return true;
}

// ------------------------- 2. Remove All Occurrences -------------------------
// Remove all occurrences of a single character (in-place using two-pointer)
// O(n) time, O(1) extra space.
void removeAllChar(string &s, char target) {
    int write = 0;
    for (int read = 0; read < (int)s.size(); ++read) {
        if (s[read] == target) continue;
        s[write++] = s[read];
    }
    s.resize(write);
}

// Remove all occurrences of a substring pattern from string s.
// This implementation repeatedly removes non-overlapping occurrences using
// a stack-like approach (linear in practice, O(n * m) worst-case but
// often efficient). For guaranteed linear time, one could use KMP-based
// streaming removal.
string removeAllSubstring(const string &s, const string &pattern) {
    if (pattern.empty()) return s; // nothing to remove
    string res;
    res.reserve(s.size());
    int m = pattern.size();
    for (char c : s) {
        res.push_back(c);
        if ((int)res.size() >= m) {
            if (res.compare((int)res.size() - m, m, pattern) == 0) {
                // remove the last m characters
                res.resize(res.size() - m);
            }
        }
    }
    return res;
}

// ------------------------- 3. Permutations of a String -------------------------
// Generate unique permutations and return them in lexicographic order.
// For long strings (n > 10) the number of permutations grows factorially,
// so use with caution.
vector<string> uniquePermutations(string s) {
    vector<string> ans;
    sort(s.begin(), s.end());
    do {
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    return ans;
}

// Backtracking variant that avoids creating the full vector if you want to process lazily.
void permuteBT(string &s, int idx, vector<string> &out) {
    if (idx == (int)s.size()) {
        out.push_back(s);
        return;
    }
    unordered_set<char> used;
    for (int i = idx; i < (int)s.size(); ++i) {
        if (used.count(s[i])) continue; // avoid duplicates
        used.insert(s[i]);
        swap(s[idx], s[i]);
        permuteBT(s, idx + 1, out);
        swap(s[idx], s[i]);
    }
}

// ------------------------- 4. Reverse Words in a String -------------------------
// Given a string, reverse the order of words. Remove extra spaces.
// Example: "  the  sky  is  blue " -> "blue is sky the"
string reverseWords(string s) {
    // trim and collapse spaces
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < n && isspace((unsigned char)s[i])) ++i;
    while (j >= 0 && isspace((unsigned char)s[j])) --j;
    if (i > j) return "";
    string trimmed;
    bool inSpace = false;
    for (int k = i; k <= j; ++k) {
        if (isspace((unsigned char)s[k])) {
            if (!inSpace) {
                trimmed.push_back(' ');
                inSpace = true;
            }
        } else {
            trimmed.push_back(s[k]);
            inSpace = false;
        }
    }
    // reverse whole string and then reverse each word
    reverse(trimmed.begin(), trimmed.end());
    int start = 0;
    for (int p = 0; p <= (int)trimmed.size(); ++p) {
        if (p == (int)trimmed.size() || trimmed[p] == ' ') {
            reverse(trimmed.begin() + start, trimmed.begin() + p);
            start = p + 1;
        }
    }
    return trimmed;
}

// ------------------------- 5. String Compression -------------------------
// Basic run-length encoding: "aaabbc" -> "a3b2c1"
// Optionally return the shorter of compressed and original.
string compressString(const string &s, bool returnShorter = true) {
    if (s.empty()) return s;
    string out;
    out.reserve(s.size());
    int count = 1;
    for (int i = 1; i <= (int)s.size(); ++i) {
        if (i < (int)s.size() && s[i] == s[i - 1]) {
            ++count;
        } else {
            out.push_back(s[i - 1]);
            out += to_string(count);
            count = 1;
        }
    }
    if (returnShorter && out.size() >= s.size()) return s;
    return out;
}

// ------------------------- Example/demonstration -------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1) Character array
    printExampleHeader("C-style character array operations");
    char arr[] = "hello_world"; // null-terminated
    cout << "Original C-array: " << arr << "\n";
    reverseCharArray(arr);
    cout << "Reversed C-array: " << arr << "\n\n";

    // 2) Valid palindrome
    printExampleHeader("Valid Palindrome");
    vector<string> palTests = {
        "A man, a plan, a canal: Panama",
        "race a car",
        "",
        "0P"
    };
    for (auto &t : palTests) {
        cout << "\"" << t << "\" -> " << (isValidPalindrome(t) ? "YES" : "NO") << "\n";
    }
    cout << '\n';

    // 3) Remove all occurrences
    printExampleHeader("Remove All Occurrences");
    string s1 = "bbaacddab";
    cout << "Original: " << s1 << "\n";
    removeAllChar(s1, 'b');
    cout << "After removing 'b': " << s1 << "\n";

    string s2 = "abcXYZabc123abc";
    cout << "Original: " << s2 << "\n";
    string removed = removeAllSubstring(s2, "abc");
    cout << "After removing substring 'abc': " << removed << "\n\n";

    // 4) Permutations
    printExampleHeader("Unique Permutations (lexicographic)");
    string p = "aab";
    auto perms = uniquePermutations(p);
    cout << "Permutations of \"" << p << "\":\n";
    for (auto &q : perms) cout << q << "\n";
    cout << "(total: " << perms.size() << ")\n\n";

    // 5) Reverse words in a string
    printExampleHeader("Reverse Words in a String");
    string rw = "  the  sky  is  blue ";
    cout << "Original: \"" << rw << "\"\n";
    cout << "Reversed words: \"" << reverseWords(rw) << "\"\n\n";

    // 6) String compression
    printExampleHeader("String Compression (run-length)");
    vector<string> compTests = {"aabcccccaaa", "abcdef", "aaAAaa"};
    for (auto &x : compTests) {
        cout << "Original: " << x << " -> Compressed: " << compressString(x) << "\n";
    }
    cout << "\n";

    // 7) Additional short utilities
    printExampleHeader("Additional Utilities & Notes");
    string demo = "hello";
    cout << "Before reverse: " << demo << "\n";
    reverseString(demo);
    cout << "After reverse: " << demo << "\n";

    cout << "\nNotes:\n";
    cout << "- Permutations are factorial in count; avoid for long strings in production.\n";
    cout << "- removeAllSubstring uses a stack-buffer approach and handles overlapping by removing when a suffix matches pattern.\n";
    cout << "- reverseWords trims and collapses multiple spaces.\n";

    printLine();
    cout << "Done.\n";
    return 0;
}
