#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 3;

    // Arithmetic Operators
    cout << "Arithmetic Operators:" << endl;
    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;
    cout << "a / b = " << (a / b) << endl;
    cout << "a % b = " << (a % b) << endl << endl;

    // Relational Operators
    cout << "Relational Operators:" << endl;
    cout << "a == b : " << (a == b) << endl;
    cout << "a != b : " << (a != b) << endl;
    cout << "a > b  : " << (a > b) << endl;
    cout << "a < b  : " << (a < b) << endl;
    cout << "a >= b : " << (a >= b) << endl;
    cout << "a <= b : " << (a <= b) << endl << endl;

    // Logical Operators
    cout << "Logical Operators:" << endl;
    cout << "(a > 5 && b < 5) : " << ((a > 5 && b < 5)) << endl;
    cout << "(a > 5 || b > 5) : " << ((a > 5 || b > 5)) << endl;
    cout << "!(a == b)        : " << (!(a == b)) << endl << endl;

    // Assignment Operators
    cout << "Assignment Operators:" << endl;
    int x = 5;
    cout << "Initial x = " << x << endl;
    x += 2;  cout << "x += 2 → " << x << endl;
    x -= 3;  cout << "x -= 3 → " << x << endl;
    x *= 4;  cout << "x *= 4 → " << x << endl;
    x /= 2;  cout << "x /= 2 → " << x << endl;
    x %= 3;  cout << "x %= 3 → " << x << endl << endl;

    // Bitwise Operators
    cout << "Bitwise Operators:" << endl;
    cout << "a & b = " << (a & b) << endl;   // AND
    cout << "a | b = " << (a | b) << endl;   // OR
    cout << "a ^ b = " << (a ^ b) << endl;   // XOR
    cout << "~a = " << (~a) << endl;         // NOT
    cout << "a << 1 = " << (a << 1) << endl; // Left shift
    cout << "a >> 1 = " << (a >> 1) << endl; // Right shift
    cout << endl;

    // Increment / Decrement
    cout << "Increment / Decrement:" << endl;
    int y = 5;
    cout << "y = " << y << endl;
    cout << "y++ = " << y++ << " (post-increment)" << endl;
    cout << "After y++ : " << y << endl;
    cout << "++y = " << ++y << " (pre-increment)" << endl;
    cout << "y-- = " << y-- << " (post-decrement)" << endl;
    cout << "After y-- : " << y << endl;
    cout << "--y = " << --y << " (pre-decrement)" << endl << endl;

    // Conditional / Ternary Operator
    cout << "Conditional / Ternary Operator:" << endl;
    int max = (a > b) ? a : b;
    cout << "Max of a and b = " << max << endl << endl;

    // sizeof Operator
    cout << "sizeof Operator:" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of char: " << sizeof(char) << " bytes" << endl << endl;

    // Type casting operator
    cout << "Type Casting Operator:" << endl;
    double result = (double)a / b;
    cout << "Casting int a to double in division: " << result << endl;

    return 0;
}
