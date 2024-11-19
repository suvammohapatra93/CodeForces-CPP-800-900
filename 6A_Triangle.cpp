
// CodeForces -> Rating 800-900 -> 6A Triangle

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if three sides can form a valid triangle
bool canFormTriangle(int a, int b, int c)
{
    return (a + b > c) && (b + c > a) && (a + c > b);
}

// Function to check if three sides form a degenerate triangle (line)
bool isDegenerate(int a, int b, int c)
{
    return (a + b == c) || (b + c == a) || (a + c == b);
}

string solveTriangle(vector<int> &sticks)
{
    // Try all possible combinations of 3 sticks
    bool canFormValidTriangle = false;
    bool canFormDegenerateTriangle = false;

    // Sort the sticks to make it easier to check
    sort(sticks.begin(), sticks.end());

    // Try all possible combinations of 3 sticks
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            for (int k = j + 1; k < 4; k++)
            {
                int a = sticks[i];
                int b = sticks[j];
                int c = sticks[k];

                if (canFormTriangle(a, b, c))
                {
                    canFormValidTriangle = true;
                    break;
                }

                if (isDegenerate(a, b, c))
                {
                    canFormDegenerateTriangle = true;
                }
            }
            if (canFormValidTriangle)
                break;
        }
        if (canFormValidTriangle)
            break;
    }

    if (canFormValidTriangle)
    {
        return "TRIANGLE";
    }
    else if (canFormDegenerateTriangle)
    {
        return "SEGMENT";
    }
    else
    {
        return "IMPOSSIBLE";
    }
}

int main()
{
    vector<int> sticks(4);

    for (int i = 0; i < 4; i++)
    {
        cin >> sticks[i];
    }

    cout << solveTriangle(sticks) << endl;

    return 0;
}

//! Time Complexity = O(1)
//! Space Complexity = O(1)