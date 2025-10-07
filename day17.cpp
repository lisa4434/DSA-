//binary ---> 0/1--> base 2
//hexadecimal ----> base 16 
//octal ---> base 8 



//decimal to binary
//repeated divisions with 2
//(42 ) base 10 = (101010) base 2 


//binary to decimal
//2^4 + 2^3 + 2^2 + 2^1 + 2^0
// 16 + 8+ 4+ 2+ 1 
//form the number and solve in 0/1



//decimal to binary 
#include <iostream>
using namespace std;
int decToBinary(int decNum){
    int ans = 0, pow = 1;

    while(decNum > 0){
        int rem = decNum % 2;
        decNum /=2;

        ans+= (rem * pow);
        pow *=10;
    }
}


//binary to decimal 
int binToDecimal(int binNum){
    int ans = 0, pow =1;
    while(binNum>0){
        int rem =  binNum % 10;
        ans += rem * pow ;
        
        binNum /=10;
        pow *=2;
    }
    return ans;
}

int main(){
    int decNum =50;

    for(int i=1; i<=10; i++){
        cout << decToBinary(i);
    }
    cout << binToDecimal(101) << endl ; //5
    return 0;
}