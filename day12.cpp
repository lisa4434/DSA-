#include <iostream>
using namespace std;

int main() {
    //Print Fibonacci Series (first 10 terms)
    int n = 10, a = 0, b = 1;
    cout << "Fibonacci: ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    return 0;
}

//Count Digits of a Number
#include <iostream>
using namespace std;

int main() {
    int n = 12345, count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    cout << "Digits: " << count;
    return 0;
}

//reverse a number 

#include <iostream>
using namespace std;

int main() {
    int n = 1234, rev = 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    cout << "Reversed: " << rev;
    return 0;
}


