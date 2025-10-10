//Arrays in C++
//An array in C++ is a collection of elements, all of the same type, stored 
//in contiguous memory locations. Arrays are used when you need to store a 
//fixed-size sequential collection of elements.

#include <iostream>
using namespace std;

int main() {
    // Declare an array of 5 integers
    int arr[5] = {1, 2, 3, 4, 5};
    
    // Accessing elements of the array
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i << ": " << arr[i] << endl;
    }

    return 0;
}


// Key Points About Arrays:

// Fixed Size: The size of an array must be known at compile-time (though C++11 onward has support for variable-length arrays
// in certain scenarios).

// Indexing: Array indices in C++ start at 0. So, arr[0] accesses the first element, arr[1] the second, and so on.

// Size: You need to know the size of the array beforehand, as arrays in C++ do not dynamically grow like other data structures 
//(e.g., vectors).

// Memory Allocation: Arrays use contiguous blocks of memory. 
//For example, an int arr[5] allocates a block of 5 integers in memory.




//Common Things with Arrays:

//Multidimensional Arrays: Arrays can have more than one dimension (like matrices):
int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};


// Passing Arrays to Functions: 
// Arrays can be passed to functions as arguments, though they lose their size information when passed this way.
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr, 5);
    return 0;
}
