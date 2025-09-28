#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    //Reverse Words in a String
    string str = "I love C++";
    string word;
    vector<string> words;
    stringstream ss(str);

    while (ss >> word) {
        words.push_back(word);
    }

    for (int i = words.size() - 1; i >= 0; i--) {
        cout << words[i] << " ";
    }

    //Find First Non-Repeating Character
    string s = "swiss";
    unordered_map<char, int> freq;

    for (char c : s) freq[c]++;

    for (char c : s) {
        if (freq[c] == 1) {
            cout << "First non-repeating: " << c;
            return 0;
        }
    }
    cout << "No unique character found";
    return 0;
}
