#include <iostream>
using namespace std;
int main(){
    int n, i, j;
    cout << "enter a number: ";
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << j;
        }
        cout << endl;
    }
    cout << endl;

    //****
    //***
    //**
    //*
    printf("2nd pattern: \n ");
    for(i=n; i>=1; i--) {
        for(j=1; j<=i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}