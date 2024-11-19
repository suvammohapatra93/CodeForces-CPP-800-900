#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    // Find boundaries of shaded area
    int minRow = INT_MAX;
    int maxRow = -1;
    int minCol = INT_MAX;
    int maxCol = -1;
    
    // Find the minimum rectangle that contains all '*'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                minRow = min(minRow, i);
                maxRow = max(maxRow, i);
                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
            }
        }
    }
    
    // Output the minimal rectangle
    for (int i = minRow; i <= maxRow; i++) {
        for (int j = minCol; j <= maxCol; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    
    return 0;
}