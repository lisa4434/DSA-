// | Operator | Meaning     | Example    | Binary Result   | Decimal Result |   |
// | -------- | ----------- | ---------- | --------------- | -------------- | - |
// | `&`      | Bitwise AND | 5 & 3      | 0101 & 0011     | 1              |   |
// | `        | `           | Bitwise OR | 5 | 3           | 0101 | 0011    | 7 |
// | `^`      | Bitwise XOR | 5 ^ 3      | 0101 ^ 0011     | 6              |   |
// | `~`      | Bitwise NOT | ~5         | ~(0101) = …1010 | -6             |   |
// | `<<`     | Left Shift  | 5 << 1     | 0101 → 1010     | 10             |   |
// | `>>`     | Right Shift | 5 >> 1     | 0101 → 0010     | 2              |   |



#include <iostream>
using namespace std;

int main() {
    int a = 5;   // 0101 in binary
    int b = 3;   // 0011 in binary

    cout << "a = " << a << ", b = " << b << endl;

    // 1. Bitwise AND (&)
    cout << "a & b = " << (a & b) << endl;   // 0101 & 0011 = 0001 (1)

    // 2. Bitwise OR (|)
    cout << "a | b = " << (a | b) << endl;   // 0101 | 0011 = 0111 (7)

    // 3. Bitwise XOR (^)
    cout << "a ^ b = " << (a ^ b) << endl;   // 0101 ^ 0011 = 0110 (6)

    // 4. Bitwise NOT (~)
    cout << "~a = " << (~a) << endl;         // ~0101 = ...1010 (depends on system, gives -6 for int)

    // 5. Left Shift (<<)
    cout << "a << 1 = " << (a << 1) << endl; // 0101 << 1 = 1010 (10)
    cout << "a << 2 = " << (a << 2) << endl; // 0101 << 2 = 10100 (20)

    // 6. Right Shift (>>)
    cout << "a >> 1 = " << (a >> 1) << endl; // 0101 >> 1 = 0010 (2)
    cout << "a >> 2 = " << (a >> 2) << endl; // 0101 >> 2 = 0001 (1)

    return 0;
}
