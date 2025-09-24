#include <iostream>
using namespace std;
int main() {
    //try to write meaningful variable name, we prefer names which have meanings to them
    //liek eg. age , name etc. camelCase(Case, c is capital),totalSum
    


    //for loop
    // for(initialisation ; condition ; updation){
    //     work
    // }    



    //sum of number from 1 to n 
    int sum=0,n,sum2=0;
    cout << "enter a number (n)";
    cin >> n;
    for(int i=1;i<=n;i++){ //1+2+3+4+5=15
        sum+=i;
        //using break within it
        if(i==5){
            break;
        }
        
    }
    cout << "sum of 1 to " << n << " is: " << sum << endl;
    //break; continue; for etc are keywords---those are special reserved words whose 
    //meaning is stored in the compiler file <iostream>

    //sum of all odd number from 1 to n
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            sum2+=i;
        }
    }
    cout << "sum of odd number from 1 to " << n << " is: " << sum2 << endl;

    //print odd numbers
    cout << "printing odd numbers :-" << endl;
    for(int i=1; i<=n;i++){
        if(i%2!=0){
            cout << i << " ";
        }
    }
    cout << endl;

    //do while loop
    //---> always works atleast one time even if condition is false 
    //kaam pehle hota h condition baad m check hoti h 
    do{
        cout << "yes it executed-1" << endl;
    }while(3>5); //while(false condition)


    //infinite loop
    // do{
    //     cout << "hello world 2" << endl;
    //     cout << "yes it executed 2" << endl;
    // }while(3<5);

    cout << "first value of n" << n << endl;
    do{
        cout << "yes it executed-2" << endl;
        n--;
    }while(n>5);
    cout << "new value of n: " << n << endl;

    //CHECK IF A NUMBER IS PRIME OR NOT
    // 1*4=4
    // 2*2=4
    // 2*2=4
    // 4*2=1
    // factors repeat after they reach i*i(2*2)
    int n2;
    cout << "enter number for prime n2 ";
    cin >> n2; 
    bool isPrime = true;    //u can also do it by 1 to underrooat n --- i*i=n
    for(int i=2; i<n2-1;i++){ //for(int i=2; i*i=n; i++)
        if(n2%i==0){
            cout << "not a prime number" << endl;
            isPrime = false;
            break;
        }
        

    }
    if(isPrime==true){
        cout << n2 << " is a prime number" << endl;
    }
    

    //NESTED LOOPS
    //LOOP INSIDE LOOP

    // printing--*****
    //           *****
    //           *****
    //           *****
    //           *****
    for(int i=1; i <=5;i++){
        cout << "*****" << endl;
    }

    int x=10;
    //printing-- **********
    for(int i =1; i<=x; i++){   //one circle of loop = 1 iteration
        cout << "*";
    }
    cout << endl;

    // printing ---- ***
    //               ***
    //               ***
    //               ***
    //               ***
    int y,z;
    cout << "enter a rows";
    cin >> y;
    cout << "enter number of column";
    cin >> z;
    for (int i=1; i<=y;i++){
        for (int j=1; j<=z;j++){
            cout << "* "; 
        }
        cout << endl;
    }


    return 0;
}