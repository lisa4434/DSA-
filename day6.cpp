#include <iostream>
#include <string>
using namespace std;

int main() {
    //Nested If with String Length
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (s.length() < 5) {
        cout << "Too short";
    } else if (s.length() <= 10) {
        char ch = tolower(s[0]);
        if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            cout << "Starts with vowel";
        else
            cout << "Does not start with vowel";
    } else {
        cout << "Long string";
    }


    //Break on First Negative
    int n, x;
    cout << "Enter count of numbers: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x < 0) {
            cout << "Stopped at negative number.";
            break;
        }
        cout << x << " ";
    }


    //Continue for Skipping Multiples
    for (int i = 1; i <= 20; i++) {
        if (i % 3 == 0 || i % 7 == 0)
            continue;
        cout << i << " ";
    }


    //If-Else Ladder: Grade System
    //Write a program to assign grades based on marks:
    //90+ → A
    //75–89 → B
    //50–74 → C
    //35–49 → D
    //below 35 → Fail
    int marks;
    cout << "Enter marks: ";
    cin >> marks;

    if (marks >= 90) cout << "Grade: A";
    else if (marks >= 75) cout << "Grade: B";
    else if (marks >= 50) cout << "Grade: C";
    else if (marks >= 35) cout << "Grade: D";
    else cout << "Fail";


    //Mixed Logic (Odd/Even with Extra Condition)
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n % 2 == 0) {
        if (n % 4 == 0) cout << "Special Even";
        else cout << "Normal Even";
    } else {
        if (n > 50) cout << "Big Odd";
        else cout << "Small Odd";
    }
    return 0;
}
