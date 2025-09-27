#include <iostream>
using namespace std;

int main() {
    //Second Largest of Three Numbers
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    if ((a > b && a < c) || (a > c && a < b))
        cout << "Second largest: " << a;
    else if ((b > a && b < c) || (b > c && b < a))
        cout << "Second largest: " << b;
    else
        cout << "Second largest: " << c;


    //Skip Numbers Divisible by 3 and 5
    for (int i = 1; i <= 50; i++) {
        if (i % 3 == 0 && i % 5 == 0)
            continue;  // skip multiples of 15
        cout << i << " ";
    }


    //Simple Calculator (Switch-Case)
    char op;
    double a, b;
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    switch(op) {
        case '+': cout << a + b; break;
        case '-': cout << a - b; break;
        case '*': cout << a * b; break;
        case '/': 
            if (b != 0) cout << a / b;
            else cout << "Division by zero not allowed!";
            break;
        default: cout << "Invalid operator!";
    }
    return 0;
}
