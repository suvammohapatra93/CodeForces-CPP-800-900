
// CodeForces -> Rating 800-900 -> 4A Watermelon

#include <iostream>
using namespace std;

int main()
{
    int number;
    cin >> number;

    if (number > 2)
    {
        if (number % 2 == 0)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    else
    {
        cout << "NO";
    }

    return 0;
}

//! Time Complexity = O(1)
//! Space Complexity = O(1)