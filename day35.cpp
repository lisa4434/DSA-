#include <bits/stdc++.h>
using namespace std;

/* ================================================================
   1️⃣ QUICK SORT ALGORITHM
   ================================================================ */

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* ================================================================
   2️⃣ COUNT INVERSION (MERGE SORT BASED)
   ================================================================ */

long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    long long swaps = 0;

    while(i < leftArr.size() && j < rightArr.size()) {
        if(leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else {
            arr[k++] = rightArr[j++];
            swaps += (mid + 1) - (left + i);
        }
    }

    while(i < leftArr.size()) arr[k++] = leftArr[i++];
    while(j < rightArr.size()) arr[k++] = rightArr[j++];

    return swaps;
}

long long mergeSortCount(vector<int>& arr, int left, int right) {
    long long count = 0;
    if(left < right) {
        int mid = left + (right - left) / 2;
        count += mergeSortCount(arr, left, mid);
        count += mergeSortCount(arr, mid + 1, right);
        count += mergeAndCount(arr, left, mid, right);
    }
    return count;
}

/* ================================================================
   3️⃣ KNIGHT’S TOUR (BACKTRACKING)
   ================================================================ */

int N = 8; // 8x8 chessboard

bool isSafe(int x, int y, vector<vector<int>>& board) {
    return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == -1);
}

bool solveKnightTour(int x, int y, int movei, vector<vector<int>>& board,
                     int xMove[], int yMove[]) {
    if(movei == N * N)
        return true;

    for(int k = 0; k < 8; k++) {
        int next_x = x + xMove[k];
        int next_y = y + yMove[k];
        if(isSafe(next_x, next_y, board)) {
            board[next_x][next_y] = movei;
            if(solveKnightTour(next_x, next_y, movei + 1, board, xMove, yMove))
                return true;
            board[next_x][next_y] = -1; // Backtrack
        }
    }
    return false;
}

void knightTour() {
    vector<vector<int>> board(N, vector<int>(N, -1));

    // Possible moves for knight
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    board[0][0] = 0; // starting position

    if(!solveKnightTour(0, 0, 1, board, xMove, yMove)) {
        cout << "Solution does not exist.\n";
        return;
    } else {
        cout << "Knight's Tour Solution:\n";
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++)
                cout << setw(2) << board[i][j] << " ";
            cout << "\n";
        }
    }
}

/* ================================================================
   MAIN FUNCTION - DRIVER
   ================================================================ */

int main() {
    cout << "===== Quick Sort Example =====\n";
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr, 0, arr.size() - 1);
    cout << "Sorted Array: ";
    for(int x : arr) cout << x << " ";
    cout << "\n\n";

    cout << "===== Count Inversions Example =====\n";
    vector<int> arr2 = {1, 20, 6, 4, 5};
    long long invCount = mergeSortCount(arr2, 0, arr2.size() - 1);
    cout << "Number of inversions: " << invCount << "\n\n";

    cout << "===== Knight’s Tour Problem =====\n";
    knightTour();

    return 0;
}
