class Solution {
public:
    bool ok = false;

    void solve(int i, int j, vector<vector<int>>& grid, int count) {
        int n = grid.size();

        if (i < 0 || j < 0 || i >= n || j >= n) {
            return;
        }

        if (n * n - 1 == count) {
            ok = true;
            return;  // CORRECTION 1: stop after reaching the last number
        }

        // CORRECTION 2: count + 1 instead of count
        if (i + 1 < n && j + 2 < n &&
            grid[i + 1][j + 2] == count + 1) {
            solve(i + 1, j + 2, grid, count + 1);
        }

        // CORRECTION 3: i + 1, j - 2
        else if (i + 1 < n && j - 2 >= 0 &&
                 grid[i + 1][j - 2] == count + 1) {
            solve(i + 1, j - 2, grid, count + 1);
        }

        // CORRECTION 4: i - 1, j + 2
        else if (i - 1 >= 0 && j + 2 < n &&
                 grid[i - 1][j + 2] == count + 1) {
            solve(i - 1, j + 2, grid, count + 1);
        }

        // CORRECTION 5: i - 1, j - 2
        else if (i - 1 >= 0 && j - 2 >= 0 &&
                 grid[i - 1][j - 2] == count + 1) {
            solve(i - 1, j - 2, grid, count + 1);
        }

        // CORRECTION 6: i + 2, j + 1
        else if (i + 2 < n && j + 1 < n &&
                 grid[i + 2][j + 1] == count + 1) {
            solve(i + 2, j + 1, grid, count + 1);
        }

        // CORRECTION 7: i + 2, j - 1
        else if (i + 2 < n && j - 1 >= 0 &&
                 grid[i + 2][j - 1] == count + 1) {
            solve(i + 2, j - 1, grid, count + 1);
        }

        // CORRECTION 8: i - 2, j + 1
        else if (i - 2 >= 0 && j + 1 < n &&
                 grid[i - 2][j + 1] == count + 1) {
            solve(i - 2, j + 1, grid, count + 1);
        }

        // CORRECTION 9: i - 2, j - 1
        else if (i - 2 >= 0 && j - 1 >= 0 &&
                 grid[i - 2][j - 1] == count + 1) {
            solve(i - 2, j - 1, grid, count + 1);
        }

        else {
            ok = false;
        }
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        // CORRECTION 10: starting cell must contain 0
        if (grid[0][0] != 0)
            return false;

        // CORRECTION 11: start count from 0
        solve(0, 0, grid, 0);

        return ok;
    }
};