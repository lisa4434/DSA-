//OUR FIRST PROGRAM

#include <iostream>

using namespace std;

int main() {
    //OUTPUT
    cout << "Hello World!" << endl; // double quotes are treated as string , hence , if there is variable, do not put it in ""
    cout << "Hello World!"; //In vs code , % sign will show behind                          Hello World!% if we dont add endl 
    cout << "Hello World!\n";
    cout << "Hello World!" << "\n";
    
    //BOILER PLATE CODE
    // #include <iostream>
    // using namespace std;
    // int main(){
    //     return 0;
    // }    
    //YOU CAN COMMENT OUT PARAGRAOH BY Ctrl+/
    
    
    //VARIABLES (int-> 4 bytes) 
    int age=25; //variable age stores some integer value
    cout << age << endl;
    cout << sizeof(age) << endl; //sizeof() is a f/n that prints the number of bytes taken by variable data type
    
    //char--> 1 bytes
    char grade = 'a'; // "="-->assignment operator
    cout << grade << endl;
    char Grade ='A';  //CASE SENSITIVE
    cout << Grade <<endl;
    
    //FLOAT--> 4 bytes
    float PI = 3.14F; // or 3.14f , if we dont write f or F , the compiler will automatically assume we were trying to write some double value
    //generally constant values are stored in variable with uppercase name (eg. PI)
    
    
    //BOOL--> 1 bytes
    bool isSafe = false ; // by default, true-->1 & false-->0
    cout << isSafe <<endl; 
    
    //DOUBLE--->8 bytes
    double price = 100.99; //by default this number will be double
    
    
    //conversion
    //implicit
    //char grade ='a';
    //char Grade = 'A';
    int value = grade;
    cout << value << endl;
    int Value = Grade;
    cout << Value <<endl;
    
    //explicit
    //double price = 100.99;
    int newPrice = (int)price;
    cout << newPrice << endl; //unlike maths, the decimal value does not round off, it just simply gets removed, whatever is after decimal
    
    //INPUT
    int A;
    cout << A << endl;  //random garbage value gets printed
    
    int Age;
    cout << "enter your age(25): " ;//even if u remove spacing, it dont                           matter
    cin>>Age;
    cout << "your age is: " << age << endl;
    
    
    double Price;
    cout << "enter the price(99.99): ";
    cin >> Price;
    cout << "entered price is: " << Price << endl;
    
    //ARITHMATIC OPERATORS
    int a,b;
    cout << "enter first number(11): ";
    cin >> a;
    cout << "enter second number(5): ";
    cin >> b;
    cout << "sum: " << (a+b) << endl;
    cout << "difference: " << (a-b) << endl;
    cout << "multiplication: " << (a*b) << endl;
    cout << "division: " << (a/b) << endl;
    cout << "modulo: " << (a%b) << endl;
    
    //understanding how decimal works
    cout << (5/2) << endl;  //ans is 2 (int/int=int); arithmatic operations only give answer in float if one of the operand was in float
    
    //if you want answer in decimal or float
    //1st meathod: type cast one of them
    cout << (5/(double)2) << endl;
    //2nd: already make one of them double
    int c=5;
    double d=2;
    cout << (c/d) << endl;
    
    //ans back in integer
    int ans = (5/(double)2);
    cout << ans << endl;
    
    
    //relational operator---> returns BOOLEAN {True(1) or False(0)}
    cout << (3<5) << endl;  //true-->1
    cout << (3>5) << endl;  //false-->0
    cout << (3<=3) << endl;  //true-->1
    cout << (3==3) << endl;  //true-->1
    cout << (3==5) << endl;  //false-->0
    cout << (3!=5) << endl;  //true-->1
    cout << (3!=3) << endl;  //false-->0
    cout << (3>1) << endl;  //true-->1
    cout << !(3>1) << endl;  //false-->0 //logical NOT--->REVERSES                        THE ANSWER
    cout << !(3<1) << endl;  //true-->1
    cout << ((3<1)||(3<5)) << endl; //true-->1
    cout << ((3<1)||(3<1)) << endl; //false-->0
    cout << ((3>1)&&(3>2)) << endl; //true-->1
    cout << ((3>1)&&(3>4)) << endl; //false-->0
    
    
    //SUM OF TWO NUMBERS
    int x,y;
    cout << "enter x(5): ";
    cin >> x;
    cout << "enter y(5): ";
    cin >> y;
    int sum = x+y;
    cout << "sum = " << sum << endl;
    
    
    //INCREAMENT OPERATORS
    int p = 10;
    int q = p++; //kaam; then update (post-increament operator)
    cout << "q = " << q << endl; //10
    cout << "p = " << p << endl; //11
    int s=10;
    int r = ++s; //update; then kaam (pre-increament operator)
    cout << "r = " << r << endl; //11
    cout << "s = " << s << endl; //11
    
    //DECREAMENT OPERATOR
    int t = 10;
    int u = t--; //kaam; then update (post-decreament operator)
    cout << "u = " << u << endl; //10
    cout << "t = " << t << endl; //9
    int v=10;
    int w = --v; //update; then kaam (pre-decreament operator)
    cout << "w = " << w << endl; //9
    cout << "v = " << v << endl; //9
    
    


    
    
    
    return 0;
}