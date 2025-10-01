#include <iostream>
using namespace std;
int main() {
    //1
    //22
    //333
    //4444
    int n;
    cout << "enter a number:";
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1; j<=i;j++){
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;


    //OR 
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout << (i+1) << " ";
        }
        cout << endl;
    }
    cout << endl;


    //A
    //BB
    //CCC
    //DDDD
    char ch='A';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << ch << " ";
        }
        ch++;
        cout << endl;
    }
    cout << endl;



    //1
    //21
    //321
    //4321

    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;


    //FLOYD pattern
    //1
    //2 3
    //4 5 6
    //7 8 9 10

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;


    //*****
    //*   *
    //*   *
    //*   *
    //*****
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==1 || i==n || j==1 || j==n)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    //    *
    //   ***
    //  *****
    // *******
    //  *****
    //   ***
    //    *

    // Upper pyramid
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n-i; j++) printf(" ");
        for(int k=1; k<=2*i-1; k++) printf("*");
        printf("\n");
    }
    // Lower inverted pyramid
    for(int i=n-1; i>=1; i--) {
        for(int j=1; j<=n-i; j++) printf(" ");
        for(int k=1; k<=2*i-1; k++) printf("*");
        printf("\n");
    }




    return 0;
}