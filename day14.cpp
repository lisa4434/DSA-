#include <iostream>
using namespace std;
//function to add 2 numbers

int add(int a, int b) {
    return a + b;
}

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    cout << "Sum = " << add(x, y);
    return 0;
}



#include <iostream>
using namespace std;
//function to find max of 2 numbers
int maxNum(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    cout << "Maximum = " << maxNum(x, y);
    return 0;
}

#include <iostream>
using namespace std;
//function to check odd or even
void checkEvenOdd(int n) {
    if (n % 2 == 0)
        cout << n << " is Even";
    else
        cout << n << " is Odd";
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    checkEvenOdd(num);
    return 0;
}

