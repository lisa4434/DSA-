#include <iostream>
using namespace std;

//min of 2 functions 
int min(int a, int b) { //parameters
        return (a<b)? a :b;
}


//sum of number from 1 to N 
int sum(int n){
    int sum =0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    return sum;
}


//calculate N factorial
int fact(int n){
    int pdt=1;
    for(int i=1;i<=n;i++){
        pdt*=i;
    }
    return pdt;
}

//PASS BY VALUE
void changeX(int x){
    x=2*x;
    cout << "x: " << x << endl;

}


//calculate sum of digits of a number
int SD(int n){
    int y, sum=0;
    while(n>0){
        
        y=n%10;
        n=n/10;
        sum+=y;
    }
    return sum;
}



//binomial coeff 
int nCr(int n, int r){
    int fact_n = fact(n);
    int fact_r = fact(r);
    int fact_nmr = fact(n-r);

    return fact_n/(fact_r * fact_nmr);
}





int main(){
    //functions---> gives life to program
    //    syntax---->
    //returnType printHello(){
    //      cout << "hello";
    //}

    //it helps in reducing redundancy---> unneccessary again and again use of codes


    //minimum of 2 functions
    cout << min(4,6); //arguments
    cout << endl;



    //sum from 1 to N 
    int z;
    cout << "enter a number: ";
    cin >> z;
    cout << sum(z) << endl;


    //calculate N factorial
    cout << fact(z) << endl;


    //PASS BY VALUE/REFERRENCE---> copy of argument is passed to functions
    int x=5;
    changeX(x);
    cout << "x in main :  " << x << endl;


    //sum of all digits
    cout << SD(z);




    //binomial coeff --nCr
    int n=8;
    int r=2;
    cout << nCr(n,r) << endl;


    return 0;
}