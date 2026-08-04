#include <bits/stdc++.h>
using namespace std;
 
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
 
bool dfs(vector<vector<char>>& grid,
         vector<vector<bool>>& visited,
         int i,
         int j,
         int parentRow,
         int parentCol)
{
    visited[i][j] = true;
 
    int rows = grid.size();
    int cols = grid[0].size();
 
    for (int k = 0; k < 4; k++) {
 
        int nr = i + dr[k];
        int nc = j + dc[k];
 
        // Outside the grid
        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
            continue;
 
        // We can only move to the same coloured cells
        if (grid[nr][nc] != grid[i][j])
            continue;
 
        // Ignore the cell from which we just came.
        // Otherwise every DFS call would immediately think
        // it found a cycle by going back to its parent.
        if (nr == parentRow && nc == parentCol)
            continue;
 
        // IMPORTANT:
        // We check if the neighbour is visited BEFORE entering it.
        // This was the main mistake in my previous approach.
        //
        // My previous idea was:
        //      Enter neighbour -> then check visited
        //
        // Correct idea:
        //      Look at neighbour -> if already visited, cycle found
        //      Otherwise enter it.
        //
        // We never need to enter an already visited cell.
        if (visited[nr][nc])
            return true;
 
        // Explore this neighbour
        if (dfs(grid, visited, nr, nc, i, j))
            return true;
    }
 
    // Checked all neighbours and no cycle found.
    return false;
}
 
int main() {
 
    int rows, cols;
    cin >> rows >> cols;
 
    vector<vector<char>> grid(rows, vector<char>(cols));
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
 
    for (int i = 0; i < rows; i++) {
        string s;
        cin >> s;
 
        for (int j = 0; j < cols; j++)
            grid[i][j] = s[j];
    }
 
    // Every connected component needs one DFS.
    // If a component is already visited, we skip it.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
 
            if (!visited[i][j]) {
 
                // (-1,-1) means the starting node has no parent.
                if (dfs(grid, visited, i, j, -1, -1)) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
 
    cout << "No";
}