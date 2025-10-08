//multiplication of a table

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 1; i <= 10; ++i) {
        cout << n << " x " << i << " = " << n * i << endl;
    }

    return 0;
}


//sum of even number 1 to n
#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter a number: ";
    cin >> N;

    int sum = 0;
    for (int i = 2; i <= N; i += 2) {
        sum += i;
    }

    cout << "Sum of even numbers from 1 to " << N << " is: " << sum << endl;

    return 0;
}


//Convert Celsius to Fahrenheit
#include <iostream>
using namespace std;

int main() {
    double celsius;
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;

    double fahrenheit = (celsius * 9.0 / 5.0) + 32;
    cout << celsius << " Celsius = " << fahrenheit << " Fahrenheit" << endl;

    return 0;
}

