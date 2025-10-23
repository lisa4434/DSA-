#include <bits/stdc++.h>
using namespace std;

/* ===================== 1. PERMUTATIONS ===================== */
void permute(string &s, int l, int r) {
    if (l == r) {
        cout << s << "\n";
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permute(s, l + 1, r);
        swap(s[l], s[i]); // backtrack
    }
}

void runPermutations() {
    string s;
    cout << "Enter string to generate permutations: ";
    cin >> s;
    cout << "All permutations:\n";
    permute(s, 0, s.size() - 1);
}

/* ===================== 2. N-QUEENS ===================== */
bool isSafeQueen(vector<string> &board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
        int left = col - (row - i);
        int right = col + (row - i);
        if (left >= 0 && board[i][left] == 'Q') return false;
        if (right < n && board[i][right] == 'Q') return false;
    }
    return true;
}

void solveQueens(int row, vector<string> &board, int n, vector<vector<string>> &ans) {
    if (row == n) {
        ans.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafeQueen(board, row, col, n)) {
            board[row][col] = 'Q';
            solveQueens(row + 1, board, n, ans);
            board[row][col] = '.'; // backtrack
        }
    }
}

void runNQueens() {
    int n;
    cout << "Enter value of N for N-Queens: ";
    cin >> n;
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solveQueens(0, board, n, ans);

    cout << "\nSolutions:\n";
    for (auto &sol : ans) {
        for (auto &row : sol) cout << row << "\n";
        cout << "\n";
    }
    if (ans.empty()) cout << "No solution exists.\n";
}

/* ===================== 3. SUDOKU SOLVER ===================== */
bool isValidSudoku(vector<vector<char>> &board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c) return false;
        if (board[i][col] == c) return false;
        if (board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValidSudoku(board, i, j, c)) {
                        board[i][j] = c;
                        if (solveSudoku(board)) return true;
                        board[i][j] = '.'; // backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void runSudoku() {
    cout << "Solving a sample Sudoku puzzle...\n";
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    if (solveSudoku(board)) {
        cout << "Solved Sudoku:\n";
        for (auto &r : board) {
            for (auto &c : r) cout << c << " ";
            cout << "\n";
        }
    } else cout << "No solution exists.\n";
}

/* ===================== 4. RAT IN MAZE ===================== */
void solveMaze(int x, int y, vector<vector<int>> &maze, int n,
           vector<vector<int>> &vis, string path, vector<string> &ans) {
    if (x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }

    string dir = "DLRU";
    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
            !vis[nx][ny] && maze[nx][ny] == 1) {
            vis[x][y] = 1;
            solveMaze(nx, ny, maze, n, vis, path + dir[i], ans);
            vis[x][y] = 0;
        }
    }
}

void runRatInMaze() {
    cout << "Running sample 4x4 Rat in Maze problem...\n";
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = maze.size();
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<string> ans;

    if (maze[0][0] == 1)
        solveMaze(0, 0, maze, n, vis, "", ans);

    if (ans.empty()) cout << "No path found.\n";
    else {
        cout << "Possible paths:\n";
        for (auto &p : ans) cout << p << "\n";
    }
}

/* ===================== MAIN MENU ===================== */
int main() {
    while (true) {
        cout << "\n============================\n";
        cout << "   BACKTRACKING PROBLEMS   \n";
        cout << "============================\n";
        cout << "1. Permutations of String\n";
        cout << "2. N-Queens Problem\n";
        cout << "3. Sudoku Solver\n";
        cout << "4. Rat in a Maze\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cout << "\n";

        switch (choice) {
            case 1: runPermutations(); break;
            case 2: runNQueens(); break;
            case 3: runSudoku(); break;
            case 4: runRatInMaze(); break;
            case 0: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}
