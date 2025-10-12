#include <iostream>
#include <vector>
#include <algorithm> // for sort(), reverse()
using namespace std;

int main() {
    // Declare a vector of integers
    vector<int> numbers;

    int n, value;
    cout << "Enter how many elements you want to insert: ";
    cin >> n;

    cout << "Enter " << n << " numbers:\n";
    for(int i = 0; i < n; i++) {
        cin >> value;
        numbers.push_back(value); // add elements at the end
    }

    // Display all elements
    cout << "\nElements in vector: ";
    for(int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }

    // Insert a new element
    int pos, newValue;
    cout << "\n\nEnter position (0-based) to insert new value: ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> newValue;

    if(pos >= 0 && pos <= numbers.size()) {
        numbers.insert(numbers.begin() + pos, newValue);
    } else {
        cout << "Invalid position!";
    }

    // Delete an element
    cout << "\nEnter position (0-based) to delete element: ";
    cin >> pos;
    if(pos >= 0 && pos < numbers.size()) {
        numbers.erase(numbers.begin() + pos);
    } else {
        cout << "Invalid position!";
    }

    // Sort the vector
    sort(numbers.begin(), numbers.end());

    // Reverse the vector
    reverse(numbers.begin(), numbers.end());

    // Display elements after operations
    cout << "\n\nElements after insert, delete, sort, and reverse:\n";
    for(int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }

    // Show size and capacity
    cout << "\n\nVector size: " << numbers.size();
    cout << "\nVector capacity: " << numbers.capacity();

    // Pop last element
    numbers.pop_back();
    cout << "\n\nAfter popping last element: ";
    for(int i : numbers)
        cout << i << " ";

    // Clear vector
    numbers.clear();
    cout << "\n\nVector cleared. Size = " << numbers.size() << endl;

    return 0;
}
