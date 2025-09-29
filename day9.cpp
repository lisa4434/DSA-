#include <iostream>
using namespace std;
int main(){
    //print square
    int n;
    cout << "enter a number: ";
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
    cout << endl;


    //print square
    // 1 2 3 4 
    // 1 2 3 4
    // 1 2 3 4
    for(int i=1;i<=3;i++){
        for(int j=1;j<=4;j++){
            cout << j << " ";
        }
        cout << endl;
    }

    //print square
    // A B C D 
    // A B C D
    // A B C D
    char ch='A';//if we give it out of the loop, the number will keep increasing and ends at Y 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << ch << " ";
            ch+=1;
        }
        cout << endl;
    }
    cout << endl;

    //giving it inside the loop now 
    for(int i=1;i<=n;i++){
        char A ='A';
        for(int j=1;j<=n;j++){
            cout << A << " ";
            A+=1;
        }
        cout << endl;
    }

    //Square pattern 
    //1 2 3
    //4 5 6 
    //7 8 9
    int A = 1;
    for(int i =1; i<=n;i++){
        for(int j=1; j<=n;j++){
            cout << A;
            A++;
        }
        cout << endl;
    }
    cout << "after pattern" << A << endl ;
    cout << endl;

    //pattern
    //*
    //* *
    //* * *
    //* * * *
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}