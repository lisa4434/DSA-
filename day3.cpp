#include <iostream>
using namespace std;
int main(){
    //IF-ELSE IF-ELSE
    //UPPER OR LOWER CASE
    char ch;
    cout << "enter a  character";
    cin >> ch;
    //when we are comparing the alphabetical value with number, it comes in implicit
    //                                                                      type conversion
    if(ch>=65 && ch<=90){ //(ch>='A' && ch <='Z');
        cout << "uppercase\n";
    }else if (ch>=97 && ch<=122){ //(ch>='a' && ch <='z');
        cout << "lowercase\n";
    }else{
        cout << "not a letter\n";
    }

    //TERNARY OPERATOR--> used for simple if-else
    //condition ? stat1(true) : stat2(false);

    //POSITIVE OR NEGATIVE
    int n=45;
    cout << (n>=0 ? "positive":"negative") << endl;
    //LOOPS (FOR,WHILE,DO WHILE)
    //COUNT (1 TO 5)
    int count = 1;
    while(count<=5){
        cout << count << " ";
        count++;
    }
    cout << endl;
    //combine compilation and execution -- g++.exe day3.cpp
    //to get the past commands back -- press upward key


    //INFINITE LOOP--ending condition---not present or false
    // while(count<=5){
    //     cout << count << " ";
    // }
    // cout << endl;

    //FOR LOOP
    for (int i = 1; i <= 5; i++) {
        cout << "Number: " << i << endl;
    }

    //DO WHILE 
    int i=1;
    do {
        cout << "Value: " << i << endl;
        i++;
    } while (i <= 3);


    //nested for looping
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cout << i << " * " << j << " = " << i * j << endl;
        }
    }
    return 0;
} 