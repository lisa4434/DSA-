#include <iostream>
using namespace std;

int main() {
    //Breaking out of a for loop
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            break; // stop loop when i = 5
        }
        cout << i << " ";
    }


    //Breaking out of a while loop
    int i = 1;
    while (i <= 10) {
        if (i == 7) break;
        cout << i << " ";
        i++;
    }

    //Breaking out of a do-while loop
    do {
        if (i == 4) break;
        cout << i << " ";
        i++;
    } while (i <= 6);


    //break in a switch case
    int day = 3;
    switch (day) {
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        default: cout << "Other day";
    }


    //Breaking nested loops
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (j == 2) break; // exit inner loop
            cout << "(" << i << "," << j << ") ";
        }
    }


    //Skipping an iteration in for loop
    for (int i = 1; i <= 5; i++) {
        if (i == 3) continue; // skip 3
        cout << i << " ";
    }


    //Skipping iteration in while loop
    int i = 0;
    while (i < 5) {
        i++;
        if (i == 2) continue; // skip 2
        cout << i << " ";
    }


    //Skipping in do-while loop
     int i = 0;
    do {
        i++;
        if (i == 4) continue; // skip 4
        cout << i << " ";
    } while (i < 5);


    //Using continue with switch inside loop
    for (int i = 1; i <= 3; i++) {
        switch (i) {
            case 2: continue; // skip printing when i=2
        }
        cout << i << " ";
    }


    //Skipping specific numbers in nested loop
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (j == 2) continue; // skip printing j=2
            cout << "(" << i << "," << j << ") ";
        }
    }

    
    return 0;
}