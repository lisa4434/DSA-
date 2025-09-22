#include <iostream>
using namespace std;

int main() {
    //IF
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "Even" << endl;
    }
    
    //IF-ELSE
    //ODD AND EVEN
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (num % 2 == 0) {
        cout << num << " is even." << endl;
    } else {
        cout << num << " is odd." << endl;
    }
    //POSITIVE OR NEGATIVE NUMBER
    if (num >= 0) {
        cout << num << " is positive." << endl;
    } else {
        cout << num << " is negative." << endl;
    }
    
    
    //IF-ELSE-IF-ELSE
    // Check positive, negative, or zero
    if (num > 0) {
        cout << num << " is positive." << endl;
    } else if (num < 0) {
        cout << num << " is negative." << endl;
    } else {
        cout << "The number is zero." << endl;
    }
    //A--(>=90); B--(80-90),else C
    int marks;
    cout << "Enter marks: ";
    cin >> marks;
    if (marks >= 90)
        cout << "A grade" << endl;
    else if (marks >= 80)  // marks between 80 and 89
        cout << "B grade" << endl;
    else
        cout << "C grade" << endl;


    return 0;
}