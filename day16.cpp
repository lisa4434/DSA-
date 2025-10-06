//Function to find square of a number
#include <iostream>
using namespace std;

int square(int n) {
    return n * n;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Square = " << square(num);
    return 0;
}



//Function to check if number is positive, negative, or zero
#include <iostream>
using namespace std;

void checkNumber(int n) {
    if (n > 0)
        cout << n << " is Positive";
    else if (n < 0)
        cout << n << " is Negative";
    else
        cout << "Number is Zero";
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    checkNumber(num);
    return 0;
}



//Function to calculate simple interest
#include <iostream>
using namespace std;

float simpleInterest(float p, float r, float t) {
    return (p * r * t) / 100;
}

int main() {
    float principal, rate, time;
    cout << "Enter Principal, Rate, and Time: ";
    cin >> principal >> rate >> time;

    cout << "Simple Interest = " << simpleInterest(principal, rate, time);
    return 0;
}


//Function to check if a character is a vowel
#include <iostream>
using namespace std;

void checkVowel(char ch) {
    ch = tolower(ch);
    if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        cout << ch << " is a vowel";
    else
        cout << ch << " is a consonant";
}

int main() {
    char c;
    cout << "Enter a character: ";
    cin >> c;
    checkVowel(c);
    return 0;
}


