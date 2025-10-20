#include <iostream>
#include <vector>

using namespace std;

// Function to search for a target in a 2D matrix
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    if (rows == 0) return false;
    int cols = matrix[0].size();
    
    // Start from the top-right corner
    int i = 0, j = cols - 1;
    
    while (i < rows && j >= 0) {
        if (matrix[i][j] == target) {
            return true; // Found the target
        } else if (matrix[i][j] > target) {
            j--; // Move left
        } else {
            i++; // Move down
        }
    }
    return false; // Not found
}

// Function to print the matrix in spiral order
void printSpiralMatrix(vector<vector<int>>& matrix) {
    int top = 0, left = 0;
    int bottom = matrix.size() - 1;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;

        // Traverse downwards
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;

        if (top <= bottom) {
            // Traverse from right to left
            for (int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        if (left <= right) {
            // Traverse upwards
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
    cout << endl;
}

int main() {
    // Initialize a 2D matrix for testing
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // Example: Searching for a target value in the matrix
    int target = 7;
    bool found = searchMatrix(matrix, target);
    if (found) {
        cout << "Target " << target << " found in the matrix!" << endl;
    } else {
        cout << "Target " << target << " not found in the matrix!" << endl;
    }

    // Example: Printing the matrix in spiral order
    cout << "Spiral Order of the Matrix: " << endl;
    printSpiralMatrix(matrix);

    return 0;
}
