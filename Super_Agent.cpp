#include <iostream>
using namespace std;

int main()
{
    char grid[3][3];

    // Read the input grid
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> grid[i][j];
        }
    }

    // Check for central symmetry
    // For a pattern to be centrally symmetric, if position (i,j) is pressed,
    // position (2-i,2-j) must also be pressed
    bool isSymmetric = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] != grid[2 - i][2 - j])
            {
                isSymmetric = false;
                break;
            }
        }
    }

    cout << (isSymmetric ? "YES" : "NO") << endl;

    return 0;
}